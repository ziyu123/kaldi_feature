// nclude "feat/feature-window.h"ivector/voice-activity-detection.cc

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

void ComputeVadEnergyRaw(const FrameExtractionOptions &frame_opts,
                         const VadEnergyOptions &opts,
                         const VectorBase<BaseFloat> &wave,
                         Vector<BaseFloat> *output_voiced) {
  int32 rows_out = NumFrames(wave.Dim(), frame_opts);
  if (rows_out == 0) {
    return;
  }
  // compute log energy 
  Vector<BaseFloat> raw_log_energy(rows_out);
  bool use_raw_log_energy = true;
  bool raw_energy = true; 
  FeatureWindowFunction feature_window_function_(frame_opts);
  Vector<BaseFloat> window;  // windowed waveform.
  for (int32 r = 0; r < rows_out; r++) {  // r is frame index.
    BaseFloat raw_log_energy_frame = 0.0;
    ExtractWindow(0, wave, r, frame_opts,
                  feature_window_function_, &window,
                  (use_raw_log_energy ? &raw_log_energy_frame : NULL));
    if(!raw_energy)
        raw_log_energy_frame = Log(std::max<BaseFloat>(VecVec(window, window),
                                     std::numeric_limits<float>::epsilon()));
    //(raw_log_energy)(r) = raw_log_energy_frame;
    (raw_log_energy)(r) = raw_log_energy_frame;

  }

  int32 T = rows_out;
  output_voiced->Resize(T);
  BaseFloat energy_threshold = opts.vad_energy_threshold;
  if (opts.vad_energy_mean_scale != 0.0) {
    KALDI_ASSERT(opts.vad_energy_mean_scale > 0.0);
    energy_threshold += opts.vad_energy_mean_scale * raw_log_energy.Sum() / T;
  }
  
  KALDI_ASSERT(opts.vad_frames_context >= 0);
  KALDI_ASSERT(opts.vad_proportion_threshold > 0.0 &&
               opts.vad_proportion_threshold < 1.0);
  for (int32 t = 0; t < T; t++) {
    const BaseFloat *log_energy_data = raw_log_energy.Data();
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

/// compute zero cross rate 
void ComputeVadZcr(const FrameExtractionOptions &frame_opts, VectorBase<BaseFloat> &wave, Vector<BaseFloat> *output_voiced){
  int32 rows_out = NumFrames(wave.Dim(), frame_opts);
  if (rows_out == 0) {
    return;
  }
  // compute zcr
  Vector<BaseFloat> zcr(rows_out);
  BaseFloat max_val = wave.Max();
  if(max_val < 100){
      output_voiced->SetZero();
      return ;
  }
  wave.Scale(1.0/wave.Max()); // normale
  int32 frameid = 0;
  int32 sample_offset = 0, cur_offset = 0;
  
  int32 frame_length = frame_opts.WindowSize();
  int32 frame_length_padded = frame_opts.PaddedWindowSize();
  int64 num_samples = wave.Dim();
  Vector<BaseFloat> window(frame_length), tmp_window(frame_length), diff_window(frame_length);

  while(cur_offset < num_samples && (num_samples - cur_offset) > frame_length){
    int32 start_sample = FirstSampleOfFrame(frameid, frame_opts),
        end_sample = start_sample + frame_length;
    int32 wave_start = int32(start_sample - sample_offset),
      wave_end = wave_start + frame_length;
    window.SetZero();
    tmp_window.SetZero();
    diff_window.SetZero();  

    if (wave_start >= 0 && wave_end <= wave.Dim()) {
      // the normal case-- no edge effects to consider.
      window.CopyFromVec(wave.Range(wave_start, frame_length));
      if(wave_end < wave.Dim())
          diff_window.CopyFromVec(wave.Range(wave_start+1, frame_length));
      else{
        diff_window.Range(0, frame_length-1).CopyFromVec(wave.Range(wave_start+1, frame_length-1));
        (diff_window)(frame_length-1) = (diff_window)(frame_length-2);
      }
      tmp_window.CopyFromVec(diff_window);
      cur_offset = start_sample;
      tmp_window.MulElements(window);
      for(int i = 0; i < tmp_window.Dim(); i++){
         (tmp_window)(i) = (tmp_window)(i) >= 0 ? 0 : 1;
      }
    
      diff_window.AddVec(-1.0, window);
      diff_window.ApplyAbs();
      diff_window.Add(-0.02);
      for(int i = 0; i < diff_window.Dim(); i++){
        (diff_window)(i) = (diff_window)(i) <= 0 ? 0 : 1;
      }
  
      tmp_window.MulElements(diff_window);
      (zcr)(frameid) = tmp_window.Sum();
      frameid++;
    }else{
      break;
    }
  }
  BaseFloat zcrlowThres = (std::max)(3.0, 0.2*(zcr.Sum()/zcr.Dim()));
  for(int i = 0; i < rows_out; i++){
      if((zcr)(i) > zcrlowThres){
        (*output_voiced)(i) = 1.0;
      }else{
        (*output_voiced)(i) = 0.0;
      }
  } 
  wave.Scale(max_val);  // unnormale
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
    //std::cout << "vad: "<< vad_result << std::endl;
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

int VadComputeRaw(const FrameExtractionOptions &frame_opts, const VectorBase<BaseFloat> &wave, const Matrix<BaseFloat> &input_fbank, Matrix<BaseFloat> &output_fbank){
    VadEnergyOptions opts;
    opts.vad_energy_threshold = 5.5;
    opts.vad_frames_context = 3;
    if (input_fbank.NumRows() == 0) {
        KALDI_WARN << "Empty feature matrix for utterance ";
        return 0;
    }
    int32 T = NumFrames(wave.Dim(), frame_opts);
    Vector<BaseFloat> vad_result(T);
    ComputeVadEnergyRaw(frame_opts, opts, wave, &vad_result);
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

int VadComputeRawBaseZcrEnergy(const FrameExtractionOptions &frame_opts,
                  VectorBase<BaseFloat> &wave,
                  const Matrix<BaseFloat> &input_fbank,
                  Matrix<BaseFloat> &output_fbank){
    VadEnergyOptions opts;
    opts.vad_energy_threshold = 5.5;
    opts.vad_frames_context = 3;
    if (input_fbank.NumRows() == 0) {
        KALDI_WARN << "Empty feature matrix for utterance ";
        return 0;
    }
    int32 T = NumFrames(wave.Dim(), frame_opts);
    Vector<BaseFloat> vad_result(T);
    ComputeVadEnergyRaw(frame_opts, opts, wave, &vad_result);
    
    Vector<BaseFloat> vad_zcr_result(T);
    ComputeVadZcr(frame_opts, wave, &vad_zcr_result);

    double sum = vad_result.Sum();
    if (sum == 0.0 || vad_zcr_result.Sum() == 0.0) {
        KALDI_WARN << "No frames were judged voiced";
        output_fbank.Resize(0, 0);
    }else{
        int32 dim = 0;
        for (int32 i = 0; i < vad_result.Dim(); i++)
            if (vad_result(i) != 0.0 && vad_zcr_result(i) != 0.0)
                dim++;
        output_fbank.Resize(dim, input_fbank.NumCols());
        int32 index = 0;
        for (int32 i = 0; i < input_fbank.NumRows(); i++) {
            if (vad_result(i) != 0.0 && vad_zcr_result(i) != 0.0) {
                  KALDI_ASSERT(vad_result(i) == 1.0); // should be zero or one.
                  KALDI_ASSERT(vad_zcr_result(i) == 1.0);
                  output_fbank.Row(index).CopyFromVec(input_fbank.Row(i));
                  index++;
            }   
        }   
        KALDI_ASSERT(index == dim);
    }   
    return 0;	
}

}
