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
    return wave_read;
}
