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


    int num_chan = 0;
    WaveData* read_data = readDataFile(filename, num_chan);
    SubVector<BaseFloat> wave(read_data->Data(),num_chan-1);
    
    fbank->Compute(&wave, fbank_features);
    

    FrameExtractionOptions frame_opts;
    frame_opts.frame_shift_ms = 10;  // in milliseconds.
    frame_opts.frame_length_ms = 25;  // in milliseconds.
    frame_opts.dither = 0.0;  // Amount of dithering, 0.0 means no dither.
    frame_opts.preemph_coeff = 0.97;  // Preemphasis coefficient.
    frame_opts.remove_dc_offset = true;  // Subtract mean of wave before FFT.
    frame_opts.snip_edges = true;
    
    Matrix<BaseFloat> vad_fbank;
    VadComputeRawBaseZcrEnergy(frame_opts, wave, fbank_features, vad_fbank);

    if(vad_fbank.NumRows() != 0)
        writeMatrix(fbankfile, vad_fbank);
    else{
        printf("%s voiced frame is 0.\n", filename);
    }
    //VadCompute(mfcc_features, fbank_features, vad_fbank);   
    //VadComputeRaw(mfcc->getFrameOptions(), wave, fbank_features, vad_fbank);   
 
 
    delete read_data;
    delete fbank;
    return 0;
}
