#include <strings.h>
#include "computeFeature.h"

namespace sid{
    computeFeature::computeFeature(){
        bzero(m_featureType,8);
        m_mfcc = NULL;
        m_fbank = NULL;
        m_spec = NULL;
    }
    computeFeature::~computeFeature(){
        if(NULL != m_mfcc){
	    delete m_mfcc;
	}
	if(NULL != m_fbank){
	    delete m_fbank;
	}
	if(NULL != m_spec){
	    delete m_spec;
	}
    }
	
    int computeFeature::Init(const char* featureType, int resampeRate){
        if(NULL == featureType || 0 == strlen(featureType)){//default fbank
	    strcpy(m_featureType,"fbank");        
	}
       	if(0 != strcmp(featureType,"mfcc") && 0 != strcmp(featureType,"fbank") && 0 != strcmp(featureType, "spec") && 0 != strcmp(featureType, "pitch")){
	    fprintf(stderr,"set feature type error!");
	    return -1;
	}
	if(0 == strcmp(featureType,"mfcc")){
	    strcpy(m_featureType,"mfcc");        
	    mfcc_opts.mel_opts = MelBanksOptions(40);
            mfcc_opts.num_ceps = 36;  // e.g. 13: num cepstral coeffs, counting zero.
	    mfcc_opts.use_energy = true; //false;  // use energy; else C0
            mfcc_opts.energy_floor = 0.0;
            mfcc_opts.raw_energy = true;  // If true, compute energy before preemphasis and windowing
            mfcc_opts.cepstral_lifter = 22.0;  // Scaling factor on cepstra for HTK compatibility.
            mfcc_opts.frame_opts.samp_freq = resampeRate;
	    mfcc_opts.frame_opts.frame_shift_ms = 10;  // in milliseconds.
            mfcc_opts.frame_opts.frame_length_ms = 25;  // in milliseconds.
            mfcc_opts.frame_opts.dither = 1.0;  // Amount of dithering, 0.0 means no dither.
            mfcc_opts.frame_opts.preemph_coeff = 0.97;  // Preemphasis coefficient.
            mfcc_opts.frame_opts.remove_dc_offset = true;  // Subtract mean of wave before FFT.
            mfcc_opts.frame_opts.snip_edges = true;
	    m_mfcc = new Mfcc(mfcc_opts);
	    if(NULL == m_mfcc){
                return -1;			
	    }
	}else if(0 == strcmp(featureType,"fbank")){
	    strcpy(m_featureType,"fbank");        
	    fbank_opts.mel_opts = MelBanksOptions(40);
	    fbank_opts.mel_opts.low_freq = 100;
	    fbank_opts.mel_opts.high_freq = 7800;
	    fbank_opts.use_energy = false;  // use energy; else C0
            fbank_opts.energy_floor = 0.0;
            fbank_opts.raw_energy = true;  // If true, compute energy before preemphasis and windowing
            fbank_opts.use_log_fbank = true;
            fbank_opts.use_power = true;
            fbank_opts.frame_opts.samp_freq = resampeRate;
            fbank_opts.frame_opts.frame_shift_ms = 10;  // in milliseconds.
            fbank_opts.frame_opts.frame_length_ms = 25;  // in milliseconds.
            fbank_opts.frame_opts.dither = 0.0;  // Amount of dithering, 0.0 means no dither.
            fbank_opts.frame_opts.preemph_coeff = 0.97;  // Preemphasis coefficient.
            fbank_opts.frame_opts.remove_dc_offset = true;  // Subtract mean of wave before FFT.
            fbank_opts.frame_opts.snip_edges = true;
            fbank_opts.frame_opts.window_type= "povey";
            m_fbank = new Fbank(fbank_opts);
            if(NULL == m_fbank){
                return -1;
	    }
            strcpy(m_featureType,"fbank");       
        }else if(0 == strcmp(featureType, "spec")){
                        spec_opts.frame_opts.samp_freq = resampeRate;
			spec_opts.frame_opts.frame_shift_ms = 10;  // in milliseconds.
                        spec_opts.frame_opts.frame_length_ms = 40;  // in milliseconds.
                        spec_opts.frame_opts.dither = 1.0;  // Amount of dithering, 0.0 means no dither.
			spec_opts.frame_opts.preemph_coeff = 0.97;  // Preemphasis coefficient.
                        spec_opts.frame_opts.remove_dc_offset = true;  // Subtract mean of wave before FFT.
                        spec_opts.frame_opts.snip_edges = true;
		        strcpy(m_featureType,"spec");
			m_spec = new Spectrogram(spec_opts); 
		}else if(0 == strcmp(featureType, "pitch")){
                    strcpy(m_featureType,"pitch");
	            pitch_opts.samp_freq = resampeRate;
            pitch_opts.frame_shift_ms = 10.0;
            pitch_opts.frame_length_ms = 25.0;
            pitch_opts.preemph_coeff = 0.0;
            pitch_opts.min_f0 = 50;
            pitch_opts.max_f0 = 400;
            pitch_opts.soft_min_f0 = 10.0;
            pitch_opts.penalty_factor = 0.1;
            pitch_opts.lowpass_cutoff = 1000;
            pitch_opts.resample_freq = 4000;
            pitch_opts.delta_pitch = 0.005;
            pitch_opts.nccf_ballast = 7000;
            pitch_opts.lowpass_filter_width = 1;
            pitch_opts.upsample_filter_width = 5;
            pitch_opts.max_frames_latency = 0;
            pitch_opts.frames_per_chunk = 0;
            pitch_opts.simulate_first_pass_online = false;
            pitch_opts.recompute_frame = 500;
            pitch_opts.nccf_ballast_online = false;
            pitch_opts.snip_edges = true;

			process_opts.pitch_scale  = 2.0;
            process_opts.pov_scale = 2.0;
            process_opts.pov_offset = 0.0;
            process_opts.delta_pitch_scale = 10.0;
            process_opts.delta_pitch_noise_stddev = 0.005;
            process_opts.normalization_left_context = 75;
            process_opts.normalization_right_context = 75;
            process_opts.delta_window = 2;
            process_opts.delay = 0;
            process_opts.add_pov_feature = true;
            process_opts.add_normalized_log_pitch = true;
            process_opts.add_delta_pitch = true;
            process_opts.add_raw_log_pitch = false; 
		}
		return 0;
	}

    	int computeFeature::Compute(VectorBase<BaseFloat> *data, Matrix<BaseFloat> &features){
        	if(NULL == data){
			fprintf(stderr,"audio data is null.");
			return -1;
		}
	    	BaseFloat vtln_warp = 1.0;	
		if(0 == strcmp(m_featureType,"mfcc")){
           		 m_mfcc->Compute(*data, vtln_warp, &features);
		}else if(0 == strcmp(m_featureType,"fbank")){
			m_fbank->Compute(*data, vtln_warp, &features);
		}else if(0 == strcmp(m_featureType, "spec")){
		    m_spec->Compute(*data, vtln_warp, &features);
		}else if(0 == strcmp(m_featureType, "pitch")){
		    ComputeAndProcessKaldiPitch(pitch_opts, process_opts, *data, &features);
		}
	    
		return 0;
	}
}// end namespace lid
