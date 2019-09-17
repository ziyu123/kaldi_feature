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
	

	computeFeature* fbank = new computeFeature();
	fbank->Init("spec",16000);
	Matrix<BaseFloat> fbank_feat;
        fbank->Compute(&wave, fbank_feat);

        SubMatrix<BaseFloat> fbank_mat(fbank_feat, 0, fbank_feat.NumRows(), 0, 400);
        Matrix<BaseFloat> fbank_spe(fbank_mat);
	
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
	writeMatrix(outfile, fbank_spe);
    delete read_data;
	delete fbank;
        return 0;
}
