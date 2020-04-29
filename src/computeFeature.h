#ifndef __COMPUTE__FEATE__H__
#define __COMPUTE__FEATE__H__
#include <stdio.h>
#include <iostream>
#include "feat/feature-mfcc.h"
#include "feat/feature-fbank.h"
#include "feat/feature-spectrogram.h"
#include "feat/pitch-functions.h"
//#include "feat/wave-reader.h"
using namespace std;
using namespace kaldi;

namespace sid{
	class computeFeature{
    	public:
        	computeFeature();
        	~computeFeature();
        	
                int Init(const char*featureType, int resampeRate);
        	int Compute(VectorBase<BaseFloat> *data, Matrix<BaseFloat> &features);
                FrameExtractionOptions getFrameOptions();
    	private:
        	char m_featureType[8];
        	MfccOptions mfcc_opts;
		Mfcc* m_mfcc;
		FbankOptions fbank_opts;
		Fbank* m_fbank;
		SpectrogramOptions spec_opts;
		Spectrogram* m_spec;
                PitchExtractionOptions pitch_opts;
                ProcessPitchOptions process_opts;
    	};
}// end namespace lid
#endif
