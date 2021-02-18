#include <stdio.h>
#include <fstream>
#include "readData.h"

WaveData* readDataFile(const char* path, int &num_chan){
    if(NULL == path){
        fprintf(stderr,"audio file name NULL.");
        return NULL;
    }
    std::ifstream ifs;
    ifs.open(path,std::ios_base::in);
    if(!ifs.is_open()){
        fprintf(stderr, "open %s fail.",path);
        return NULL; 
    }   
    if(ifs.bad()){
       fprintf(stderr, "file read error.");
       return NULL;
    }
    WaveData *wave_read = new WaveData();
    
    wave_read->Read(ifs);
    

    float min_duration = 0.01f;
    if(wave_read->Duration() < min_duration) {
        fprintf(stderr, "File: %s is too short [%.3f < %.3f]sec",path, wave_read->Duration(),min_duration);
        delete wave_read;
        return NULL; 
    }   
    num_chan = wave_read->Data().NumRows();
    if(num_chan > 2){ 
        fprintf(stderr, "File: %s is %d channel, not support.\n",path, num_chan);
        delete wave_read;
	return NULL;
    } 
    SubVector<BaseFloat> wave(wave_read->Data(),num_chan-1);
     
    BaseFloat sample_freq = wave_read->SampFreq();
    if(sample_freq != 16000){
        BaseFloat  new_sample_freq = 16000;
        SubVector<BaseFloat> wave(wave_read->Data(),num_chan-1);
        Vector<BaseFloat> resampled_wave(wave);
        DownsampleWaveForm(sample_freq, wave, new_sample_freq, &resampled_wave);
        Matrix<BaseFloat> resampled_data(num_chan, resampled_wave.Dim());
        resampled_data.CopyRowFromVec(resampled_wave, 0);
        delete wave_read;
        wave_read = NULL;
        wave_read = new WaveData(new_sample_freq, resampled_data); 
    }
    ifs.close();
    return wave_read;
}

int writeWaveData(const char *file, WaveData* wave){
    std::ofstream ofile;
    ofile.open(file, std::ios_base::trunc);
    if(!ofile.is_open()){
        fprintf(stderr, "open %s fail.", file);
        return -1;
    }
    if(ofile.bad()){
       fprintf(stderr, "file write error.");
       return -1;
    }
    wave->Write(ofile); 
    ofile.close(); 
    return 0;
}

int writeData2Wave(const char * file, char * dataBuff, int len, int samples){
    if(NULL == file || NULL == dataBuff){
        fprintf(stderr, "poist is NULL.\n");
        return -1;
    }
    FILE *fp = fopen(file, "w");
    if(NULL == fp){
        fprintf(stderr, "open %s fail.\n", file);
        return -1;
    }
    RIFF_HEADER riff_h;
    strncpy((char*)riff_h.szRiffID, "RIFF", 4);
    strncpy((char*)riff_h.szRiffFormat, "WAVE", 4);
    riff_h.dwRiffSize = 32 + len ;
    fwrite(&riff_h, 1, sizeof(riff_h), fp);

    FMT_BLOCK fmt_h;
    strncpy((char*)fmt_h.szFmtID, "fmt ", 4);
    fmt_h.dwFmtSize = 16;
    fmt_h.wFormatTag = 1;
    fmt_h.wChannels = 1;
    if(samples != 8000 && samples != 16000){
        fprintf(stderr, "write fail, support 8k or 16k only.\n");
        return -1;
    }
    fmt_h.dwSamplesPerSec = samples;
    fmt_h.wBitsPerSample = 16;
    fmt_h.dwAvgBytesPerSec = fmt_h.dwSamplesPerSec * (fmt_h.wBitsPerSample / 8);
    fmt_h.wBlockAlign = 2;
    fwrite(&fmt_h, 1, sizeof(fmt_h), fp);

    DATA_BLOCK data_h;
    strncpy((char*)data_h.szDataID, "data", 4);
    data_h.dwDataSize = len;
    fwrite(&data_h, 1, sizeof(data_h), fp);
    fwrite(dataBuff, 1, len, fp);

    if(NULL != fp){
        fclose(fp);
    }
    return 0;
}


