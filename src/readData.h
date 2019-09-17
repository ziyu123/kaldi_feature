#ifndef __READ__DATA__H__
#define __READ__DATA__H__
#include "feat/wave-reader.h"
using namespace kaldi;

WaveData* readDataFile(const char* path, int& num_chan);

#endif
