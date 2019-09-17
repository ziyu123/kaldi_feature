#include <stdio.h>
#include "readData.h"
#include "computeFeature.h"
#include "writeData.h"
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include<sys/stat.h>
using namespace sid;

void mkdirs(char *muldir){
    int i,len;
    char str[1024];
    strncpy(str, muldir, 1024);
    len=strlen(str);
    for( i=0; i<len; i++ ){
        if( str[i]=='/' ){
            str[i] = '\0';
            if( access(str,0)!=0 ){
                mkdir(str, 0777 );
            }
            str[i]='/';
        }
    }
    if( len>0 && access(str,0)!=0 ){
        mkdir(str, 0777 );
    }
    return;
}


int main(int argc, char* argv[]){
	if(argc != 3){
	        printf("Usage:%s wavpath outfile\n",argv[0]);
		return -1;
	}
	const char* filename = argv[1];
	const char* outfile = argv[2];
	int num_chan = 0;
    WaveData* read_data = readDataFile(filename, num_chan);
	SubVector<BaseFloat> wave(read_data->Data(),num_chan-1);
	
	computeFeature* fpitch = new computeFeature();
	fpitch->Init("pitch",16000);
	Matrix<BaseFloat> pitch_feat;
    fpitch->Compute(&wave, pitch_feat);

	computeFeature* fbank = new computeFeature();
	fbank->Init("fbank",16000);
	Matrix<BaseFloat> fbank_feat;
    fbank->Compute(&wave, fbank_feat);

	int rows = fbank_feat.NumRows();
	int pitch_cols = pitch_feat.NumCols();
	int fbank_cols = fbank_feat.NumCols();
	Matrix<BaseFloat> features(rows, pitch_cols + fbank_cols);
    SubMatrix<BaseFloat> pitch_mat(features, 0, rows, 0, pitch_cols);
    SubMatrix<BaseFloat> fbank_mat(features, 0, rows, pitch_cols, fbank_cols);
    pitch_mat.CopyFromMat(pitch_feat, kNoTrans);
    fbank_mat.CopyFromMat(fbank_feat, kNoTrans);
	
	char name[1024] = {0};
	int len = strlen(outfile);
	int pos = 0;
	for(int i = len-1; i > 0; i--){
	    if(outfile[i] == '/'){
		    pos = i;
			break;
		}
	}
    strncpy(name, outfile, pos);

    DIR *dirp = opendir(name);
    if(NULL == dirp){
        mkdirs(name);
    }else{
        closedir(dirp);
    }
	writeMatrix(outfile, features);
    delete read_data;
	delete fpitch;
	delete fbank;
        return 0;
}
