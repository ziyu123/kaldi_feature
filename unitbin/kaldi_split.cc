#include <stdio.h>
#include <unistd.h>
#include <libgen.h>
#include "readData.h"
#include "voiceActivitydetection.h"


int getIndex(Vector<BaseFloat> &vad_result, int idx, int left_idx, int right_idx){
    if(vad_result.Dim() <= idx){
        return vad_result.Dim();
    }
    // left 5s,  right 3s
    // no voiced frame 
    int left = idx - left_idx;
    int right = idx + right_idx;
    if(left < 0) left = 0;
    if(right > vad_result.Dim()) right = vad_result.Dim();
    int count = 0;
    int count_idx = 0;
    for(int i = idx; i >= left; i--){
        if((vad_result)(i) == 0.0){
            count ++;
        }
        if((vad_result)(i) == 1.0){
            count = 0;
        }
        if(count >= 20){  // 20 frames
            count_idx = i;
            break;
        }
    }
    if(0 != count && count >= 20){
        return count_idx;
    }   
    count = 0;
    count_idx = 0;
    for(int i = idx; i < right; i++){
        if((vad_result)(i) == 0.0){
            count ++;
        }
        if((vad_result)(i) == 1.0){
            count = 0;
        }
        if(count >= 15){  // 20 frames
            count_idx = i;
            break;
        }
    } 
    if( 0 != count && count >= 15){
        return count_idx;
    }
    return idx; 
}

int main(int argc, char* argv[]){
    if(argc != 4){
        printf("Usage:%s wavpath length outwavdir\n",argv[0]);
        printf("         length is split segment length, such as 30s\n");
        return -1;
    }
    const char* filename = argv[1];
    const int split_len = atoi(argv[2]);
    const char* outfiledir = argv[3];

    if(F_OK != access(filename, 0)){
        printf("%s seems not exist!", filename);
        return -1;
    }
    if(F_OK != access(outfiledir, 0)){
        printf("%s must exists!", outfiledir);
        return -1;
    }
 
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
    
    int split_frames = split_len * 100;
    char* file_basename = basename(const_cast<char*>(filename));
    char outfilename [1024 * 5] = {0};
    if(T <= split_frames){
        sprintf(outfilename, "%s/%s", outfiledir, file_basename);
        writeWaveData(outfilename, read_data);
        delete read_data;
        return 0;
    }   

    Vector<BaseFloat> vad_result(T);
    ComputeVadEnergyRaw(frame_opts, vad_opts, wave, &vad_result);
    
    if(vad_result.Sum() == 0){
        printf("%s seems not active voiced.", filename);
        delete read_data;
        return -1;
    }

    char *extr = strrchr(file_basename,'.');
    if (extr){    
        *extr='\0';    
        extr++;
    } 
     
    int num_output_channels = 1;
    int offset = 0;
    int left_offset = split_frames / 4;
    int right_offset = split_frames / 8;
    
    for(int i = split_frames; i <= T; ){
        int split_idx = getIndex(vad_result, i, left_offset, right_offset);
        float start_p = (i - split_frames)*0.01;
        float end_p = split_idx * 0.01;
        Matrix<BaseFloat> out_matrix(num_output_channels, (split_idx - i + split_frames) * 160); 
        SubMatrix<BaseFloat> subOut = out_matrix.Range(0,1, 0, (split_idx - i + split_frames)*160); 
        SubVector<BaseFloat> subWave = wave.Range((i-split_frames)*160, (split_idx - i + split_frames)*160);
        subOut.CopyRowFromVec(subWave, 0);
        WaveData out_wave(16000, out_matrix);
         
        sprintf(outfilename, "%s/%s_%.2f_%.2f.wav", outfiledir, file_basename, start_p, end_p);
        writeWaveData(outfilename, &out_wave);
        memset(outfilename, 0, 1024*5);
        i = split_idx + split_frames;
        if(i > T){
            if(T - split_idx < 50) break; 
            start_p = (i - split_frames)*0.01;
            end_p = T * 0.01;
            Matrix<BaseFloat> out_matrix_end(num_output_channels, (T - split_idx) * 160);
            SubMatrix<BaseFloat> subOut_end = out_matrix_end.Range(0,1, 0, (T - split_idx)*160);
            subOut_end.CopyRowFromVec(wave.Range(split_idx*160, (T - split_idx)*160), 0);
            WaveData out_wave_end(16000, out_matrix_end);
            sprintf(outfilename, "%s/%s_%.2f_%.2f.wav", outfiledir, file_basename, start_p, end_p);
            writeWaveData(outfilename, &out_wave_end);
        }
    }   
    delete read_data;
    return 0;
}
