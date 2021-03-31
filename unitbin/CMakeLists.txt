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
    compute_fbank_vad
    kaldi_vad
    kaldi_vad_tool
    kaldi_split
    compute_fbank_zcr_energy_vad
    compute_fbank_cmvn_vad
    get_fbank_vad
)
foreach(bin ${BINS})
        MESSAGE(STATUS "generate make for ${bin}")
        add_executable(${bin} ${bin}.cc)
        target_link_libraries(${bin} ${CMAKE_BINARY_DIR}/${OUTPUT_LIB_NAME} ${SYS_DEPS})
endforeach()
