CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
cmake_policy(SET CMP0016 OLD)
PROJECT(KALDI_FEATURE)
SET(CMAKE_BUILD_TYPE "Debug")
SET(CMAKE_BUILD_TYPE Debug CACHE STRING "set build type to debug")
SET(CMAKE_VERBOSE_MAKEFILE on)
SET(CMAKE_MACOSX_RPATH 0)
SET(CMAKE_CXX_COMPILER "g++")
SET(CMAKE_CXX_FLAGS "-msse -msse2 -std=gnu++11  -Wall -fPIC -Wno-sign-compare -Wl --verbose  -Wno-dev -Winit-self -D_GLIBCXX_USE_CXX11_ABI=0") # -rdynamic")
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS} -g -std=c++0x")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CMAKE_CXX_FLAGS}  ${CMAKE_CXX_FLAGS} -O2")


MESSAGE(STATUS "CXX: ${CMAKE_CXX_FLAGS}")

SET(LIB_PATH "${CMAKE_SOURCE_DIR}/lib/")
SET(OUTPUT_LIB "kaldi_feature")
SET(OUTPUT_LIB2 "tmpkaldi")
SET(OUTPUT_LIB_NAME "lib${OUTPUT_LIB}.a")

SET(LIB_INCLUDE "${CMAKE_SOURCE_DIR}/include/")
MESSAGE(STATUS"thirdlib include: ${LIB_INCLUDE}")

include_directories(${LIB_INCLUDE})

include_directories(src)
add_subdirectory(src)
include_directories(bin)
add_subdirectory(bin)
#include_directories(unitbin)
#add_subdirectory(unitbin)
