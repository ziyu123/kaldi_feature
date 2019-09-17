set(SOURCES
    computeFeature.cc
    readData.cc
    writeData.cc
    voiceActivitydetection.cc
)
MESSAGE(STATUS "sources:${SOURCES}")
add_compile_options(-Wl,--as-needed -g -std=c++0x)
add_library(${OUTPUT_LIB}  ${SOURCES})


ADD_CUSTOM_TARGET(${OUTPUT_LIB2} ALL
    COMMAND cp src/${OUTPUT_LIB_NAME} ${OUTPUT_LIB_NAME}
    COMMAND echo CREATE ${OUTPUT_LIB_NAME} > ar.mac
    COMMAND echo SAVE >> ar.mac
    COMMAND echo END >> ar.mac
    COMMAND echo OPEN ${OUTPUT_LIB_NAME} > ar.mac
    COMMAND echo ADDLIB ${LIB_PATH}/kaldi-matrix.a >> ar.mac
    COMMAND echo ADDLIB ${LIB_PATH}/kaldi-base.a >> ar.mac
    COMMAND echo ADDLIB ${LIB_PATH}/kaldi-util.a >> ar.mac
    COMMAND echo ADDLIB ${LIB_PATH}/kaldi-feat.a >> ar.mac
    COMMAND echo ADDLIB ${LIB_PATH}/libmkl_core.a >> ar.mac
    COMMAND echo ADDLIB ${LIB_PATH}/libmkl_sequential.a >> ar.mac
    COMMAND echo ADDLIB ${LIB_PATH}/libmkl_intel_lp64.a >> ar.mac
    COMMAND echo SAVE >> ar.mac
    COMMAND echo END >> ar.mac
    COMMAND ar -M < ar.mac
    COMMAND rm ar.mac
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    DEPENDS ${OUTPUT_LIB})


