#include <stdio.h>
#include "readData.h"
#include "voiceActivitydetection.h"

int main(int argc, char* argv[]){
    if(argc != 3){
        printf("Usage:%s wavpath outwavpath\n",argv[0]);
        return -1;
    }
    const char* filename = argv[1];
    const char* outfilename = argv[2];
    int num_chan = 0;
    WaveData* read_data = readDataFile(filename, num_chan);
    SubVector<BaseFloat> wave(read_data->Data(),num_chan-1);
   
    VadEnergyOptions vad_opts;
    vad_opts.vad_energy_threshold = 5.5; 
    FrameExtractionOptions frame_opts;
    frame_opts.frame_shift_ms = 10;  // in milliseconds.
    frame_opts.frame_length_ms = 25;  // in milliseconds.
    frame_opts.dither = 0.0;  // Amount of dithering, 0.0 means no dither.
    frame_opts.preemph_coeff = 0.97;  // Preemphasis coefficient.
    frame_opts.remove_dc_offset = true;  // Subtract mean of wave before FFT.
    frame_opts.snip_edges = true;
    int32 T = NumFrames(wave.Dim(), frame_opts);
    Vector<BaseFloat> vad_result(T);
    ComputeVadEnergyRaw(frame_opts, vad_opts, wave, &vad_result);
    
    Vector<BaseFloat> vad_zcr_result(T);
    ComputeVadZcr(frame_opts, wave, &vad_zcr_result);
    int count = 0;
    Vector<BaseFloat> vad_merge_result(T);
    for(int i = 0; i <T; i++){
        if( (vad_result)(i) == 1.0 && (vad_zcr_result)(i) == 1.0 ){
            count ++;
            (vad_merge_result)(i) = 1.0;
	    //printf("frame: %d, timepoint: %.3f\n", i+1, i*0.01);
	}else{
            (vad_merge_result)(i) = 0.0;
        }
    }
    if(vad_merge_result.Sum() == 0){
        printf("%s unvoiced.", filename);
        delete read_data;
        return -1;
    }
    int num_output_channels = 1;
    int offset = 0;
    Matrix<BaseFloat> out_matrix(num_output_channels, count * 160); 
    for(int i = 0; i < T; i++){
        if((vad_merge_result)(i) == 1.0){
            SubMatrix<BaseFloat> subOut = out_matrix.Range(0,1, offset, 160); 
            SubVector<BaseFloat> subWave = wave.Range(i*160, 160);
            subOut.CopyRowFromVec(subWave, 0);
            offset += 160;
        }
    }   
    WaveData out_wave(16000, out_matrix); 
    writeWaveData(outfilename, &out_wave);
 
    delete read_data;
    return 0;
}
