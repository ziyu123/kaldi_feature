#include <stdio.h>
#include "readData.h"
#include "computeFeature.h"
#include "voiceActivitydetection.h"
#include "writeData.h"
using namespace sid;

int main(int argc, char* argv[]){
    if(argc != 3){
        printf("Usage:%s wavpath outfile\n",argv[0]);
        return -1;
    }
    const char* filename = argv[1];
    const char* fbankfile = argv[2];
    computeFeature* fbank= new computeFeature();
    fbank->Init("fbank",16000);
    Matrix<BaseFloat> fbank_features;

    computeFeature* mfcc= new computeFeature();
    mfcc->Init("mfcc",16000);
    Matrix<BaseFloat> mfcc_features;

    int num_chan = 0;
    WaveData* read_data = readDataFile(filename, num_chan);
    SubVector<BaseFloat> wave(read_data->Data(),num_chan-1);
    
    fbank->Compute(&wave, fbank_features);
    mfcc->Compute(&wave, mfcc_features);
    
    //printMatrix("fbank", fbank_features); 
    //printMatrix("mfcc", mfcc_features); 

    SlidingWindowCmnOptions opts;
    opts.cmn_window = 300;
    opts.center = true;
    Matrix<BaseFloat> cmvn_feat(fbank_features.NumRows(), fbank_features.NumCols(), kUndefined);
    SlidingWindowCmn(opts, fbank_features, &cmvn_feat);
    //printMatrix("cmvn_fbank", cmvn_feat);

    Matrix<BaseFloat> vad_fbank;
    VadCompute(mfcc_features, cmvn_feat, vad_fbank);   

    writeMatrix(fbankfile, vad_fbank);
    delete read_data;
    delete fbank;
    delete mfcc;
    return 0;
}
