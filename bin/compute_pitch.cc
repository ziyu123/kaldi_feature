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
	computeFeature* fpitch = new computeFeature();
	fpitch->Init("pitch",16000);
	Matrix<BaseFloat> features;
	int num_chan = 0;
    WaveData* read_data = readDataFile(filename, num_chan);
	SubVector<BaseFloat> wave(read_data->Data(),num_chan-1);
    fpitch->Compute(&wave, features);
    writeMatrix("fpitch.spe", features);
	std::cout<<"Features:\n"<<features;
    delete read_data;
	delete fpitch;
        return 0;
}
