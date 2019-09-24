// featbin/wav-to-duration.cc

// Copyright 2013  Daniel Povey

// See ../../COPYING for clarification regarding multiple authors
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//  http://www.apache.org/licenses/LICENSE-2.0
//
// THIS CODE IS PROVIDED *AS IS* BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION ANY IMPLIED
// WARRANTIES OR CONDITIONS OF TITLE, FITNESS FOR A PARTICULAR PURPOSE,
// MERCHANTABLITY OR NON-INFRINGEMENT.
// See the Apache 2 License for the specific language governing permissions and
// limitations under the License.

#include "base/kaldi-common.h"
#include "feat/feature-mfcc.h"
#include "readData.h"
#include "util/common-utils.h"

int main(int argc, char *argv[]) {
  try {
    using namespace kaldi;
    const char *usage =
        "Read wav file and output a single float the duration of wav file in seconds.\n"
        "Usage:  wav-to-duration [options...] <wav-file> \n"
        "E.g.: wav-to-duration test.wav\n";

    ParseOptions po(usage);
    po.Read(argc, argv);
    if (po.NumArgs() != 1) {
      po.PrintUsage();
      exit(1);
    }

    std::string wav_rspecifier = po.GetArg(1);
    int num_chan = 0;
    WaveData* read_data = readDataFile(wav_rspecifier.c_str(), num_chan); 
    BaseFloat duration = read_data->Duration();
    std::cout << duration << std::endl;
    delete read_data;
  } catch(const std::exception &e) {
    std::cerr << e.what();
    return -1;
  }
}
