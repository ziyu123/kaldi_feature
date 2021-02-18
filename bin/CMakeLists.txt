add_compile_options(-Wl,--as-needed -g -std=c++0x -D_GLIBCXX_USE_CXX11_ABI=0)
include_directories(${CMAKE_SOURCE_DIR}/src)
SET(CMAKE_MACOSX_RPATH 0)

SET(SYS_DEPS
    -lm
    -lpthread
    -ldl	
)
link_directories(${LIB_PATH})

SET(BINS
    compute_spectrogram	 
    compute-spectrogram-feats
    compute_pitch
    compute_pitch_fbank
    compute_spe
    compute_mfcc
    compute-mfcc-feats
    #compute_fbank_cmvn_vad
    wav-reverberate
    wav-to-duration
    kaldi_split
    kaldi_vad_tool 
)
foreach(bin ${BINS})
        MESSAGE(STATUS "generate make for ${bin}")
        add_executable(${bin} ${bin}.cc)
        target_link_libraries(${bin} ${CMAKE_BINARY_DIR}/${OUTPUT_LIB_NAME} ${SYS_DEPS})
endforeach()
