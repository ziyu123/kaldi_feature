#ifndef __WRITE_DATA__
#define __WRITE_DATA__
#include <stdio.h>
#include <iostream>
#include "matrix/kaldi-matrix.h"
#include "base/io-funcs.h"
using namespace std;
using namespace kaldi;
int writeMatrix(string filename, Matrix<BaseFloat> &features);
void printMatrix(string note, Matrix<BaseFloat> &features);// text mode
#endif
