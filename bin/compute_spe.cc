#include <stdio.h>
#include "readData.h"
#include "computeFeature.h"
#include "writeData.h"
using namespace sid;

int main(int argc, char* argv[]){
	if(argc != 2){
	        printf("Usage:%s wavpath\n",argv[0]);
		return -1;
	}
	const char* filename = argv[1];
	computeFeature* fbank= new computeFeature();
	fbank->Init("spec",16000);
	Matrix<BaseFloat> features;
	int num_chan = 0;
        WaveData* read_data = readDataFile(filename, num_chan);
	SubVector<BaseFloat> wave(read_data->Data(),num_chan-1);
        fbank->Compute(&wave, features);
        SubMatrix<BaseFloat> LowFreq(features, 0, features.NumRows(), 0, 400); 
        Matrix<BaseFloat> subFeat(LowFreq);
        writeMatrix("fbank.spe", subFeat);
	std::cout<<"Features:\n"<<features;
        delete read_data;
	delete fbank;
        return 0;
}
