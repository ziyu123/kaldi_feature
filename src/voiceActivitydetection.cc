// ivector/voice-activity-detection.cc

// Copyright     2013  Daniel Povey

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


#include "voiceActivitydetection.h"
#include "matrix/matrix-functions.h"


namespace kaldi {

void ComputeVadEnergy(const VadEnergyOptions &opts,
                      const MatrixBase<BaseFloat> &feats,
                      Vector<BaseFloat> *output_voiced) {
  int32 T = feats.NumRows();
  output_voiced->Resize(T);
  if (T == 0) {
    KALDI_WARN << "Empty features";
    return;
  }
  Vector<BaseFloat> log_energy(T);
  log_energy.CopyColFromMat(feats, 0); // column zero is log-energy.
  
  BaseFloat energy_threshold = opts.vad_energy_threshold;
  if (opts.vad_energy_mean_scale != 0.0) {
    KALDI_ASSERT(opts.vad_energy_mean_scale > 0.0);
    energy_threshold += opts.vad_energy_mean_scale * log_energy.Sum() / T;
  }
  
  KALDI_ASSERT(opts.vad_frames_context >= 0);
  KALDI_ASSERT(opts.vad_proportion_threshold > 0.0 &&
               opts.vad_proportion_threshold < 1.0);
  for (int32 t = 0; t < T; t++) {
    const BaseFloat *log_energy_data = log_energy.Data();
    int32 num_count = 0, den_count = 0, context = opts.vad_frames_context;
    for (int32 t2 = t - context; t2 <= t + context; t2++) {
      if (t2 >= 0 && t2 < T) {
        den_count++;
        if (log_energy_data[t2] > energy_threshold)
          num_count++;
      }
    }
    if (num_count >= den_count * opts.vad_proportion_threshold)
      (*output_voiced)(t) = 1.0;
    else
      (*output_voiced)(t) = 0.0;
  }
}

int VadCompute(const Matrix<BaseFloat> &input_features_mfcc, const Matrix<BaseFloat> &input_fbank, Matrix<BaseFloat> &output_fbank){
    VadEnergyOptions opts;
    if (input_features_mfcc.NumRows() == 0 || input_fbank.NumRows() == 0) {
        KALDI_WARN << "Empty feature matrix for utterance ";
        return 0;
	}
    if(input_features_mfcc.NumRows() != input_fbank.NumRows()){
            // || input_features_mfcc.NumCols() != input_fbank.NumCols()){
	    KALDI_WARN << "input mfcc not match fbank";
	    return 0;
    }
    Vector<BaseFloat> vad_result(input_features_mfcc.NumRows());
    ComputeVadEnergy(opts, input_features_mfcc, &vad_result);
    double sum = vad_result.Sum();
    if (sum == 0.0) {
        KALDI_WARN << "No frames were judged voiced";
    }else{
        int32 dim = 0;
        for (int32 i = 0; i < vad_result.Dim(); i++)
            if (vad_result(i) != 0.0)
                dim++;
		output_fbank.Resize(dim, input_fbank.NumCols());
        int32 index = 0;
        for (int32 i = 0; i < input_fbank.NumRows(); i++) {
            if (vad_result(i) != 0.0) {
                  KALDI_ASSERT(vad_result(i) == 1.0); // should be zero or one.
                  output_fbank.Row(index).CopyFromVec(input_fbank.Row(i));
                  index++;
            }   
        }   
        KALDI_ASSERT(index == dim);
    }   
    return 0;	
}
}
