#include <stdio.h>
#include "readData.h"
#include "computeFeature.h"
#include "voiceActivitydetection.h"
#include "writeData.h"
using namespace sid;

int main(int argc, char* argv[]){
    if(argc != 4){
        printf("Usage:%s vadrefwavpath wavpath outfile\n",argv[0]);
        return -1;
    }
    const char* filename = argv[2];
    const char* fbankfile = argv[3];
    const char* reffile = argv[1];
    computeFeature* fbank= new computeFeature();
    fbank->Init("fbank",16000);
    Matrix<BaseFloat> fbank_features;


    int num_chan = 0;
    WaveData* read_data = readDataFile(filename, num_chan);
    SubVector<BaseFloat> wave(read_data->Data(),num_chan-1);
    
    fbank->Compute(&wave, fbank_features);
   
    int ref_chan = 0;
    WaveData* ref_read_data = readDataFile(reffile, ref_chan); 
    SubVector<BaseFloat> ref_wave(ref_read_data->Data(),num_chan-1);

    FrameExtractionOptions frame_opts;
    frame_opts.frame_shift_ms = 10;  // in milliseconds.
    frame_opts.frame_length_ms = 25;  // in milliseconds.
    frame_opts.dither = 0.0;  // Amount of dithering, 0.0 means no dither.
    frame_opts.preemph_coeff = 0.97;  // Preemphasis coefficient.
    frame_opts.remove_dc_offset = true;  // Subtract mean of wave before FFT.
    frame_opts.snip_edges = true;
    
    Matrix<BaseFloat> vad_fbank;

    VadEnergyOptions opts;
    opts.vad_energy_threshold = 5.5;
    opts.vad_frames_context = 3;
    
    int32 T = NumFrames(wave.Dim(), frame_opts);
    if(T != fbank_features.NumRows()){
        printf("frame len is not match,%s and  %s.\n", reffile, filename);
        return -1;
    }
    Vector<BaseFloat> vad_result(T);
    ComputeVadEnergyRaw(frame_opts, opts, ref_wave, &vad_result);

    Vector<BaseFloat> vad_zcr_result(T);
    ComputeVadZcr(frame_opts, ref_wave, &vad_zcr_result);

    double sum = vad_result.Sum();
    if (sum == 0.0 || vad_zcr_result.Sum() == 0.0) {
        printf("No frames were judged voiced %s .\n", filename);
    }else{  
        int32 dim = 0;
        for (int32 i = 0; i < vad_result.Dim(); i++)
            if (vad_result(i) != 0.0 && vad_zcr_result(i) != 0.0)
                dim++;
        vad_fbank.Resize(dim, fbank_features.NumCols());
        int32 index = 0;
        for (int32 i = 0; i < fbank_features.NumRows(); i++) {
            if (vad_result(i) != 0.0 && vad_zcr_result(i) != 0.0) {
                  vad_fbank.Row(index).CopyFromVec(fbank_features.Row(i));
                  index++;
            }
        }
        KALDI_ASSERT(index == dim);
    }  

    if(vad_fbank.NumRows() != 0)
        writeMatrix(fbankfile, vad_fbank);
    else{
        printf("%s voiced frame is 0.\n", filename);
    }
 
    delete read_data;
    delete ref_read_data;
    delete fbank;
    return 0;
}
