#include "writeData.h"

void CheckToken(const char *token) {
  if (*token == '\0')
    KALDI_ERR << "Token is empty (not a valid token)";
  const char *orig_token = token;
  while (*token != '\0') {
    if (::isspace(*token))
      KALDI_ERR << "Token is not a valid token (contains space): '"
                << orig_token << "'";
    token++;
  }
}


int writeToken(std::ofstream &os, string &token){
    CheckToken(token.c_str());  // make sure it's valid (can be read back)
    os << token;
    if (os.fail()) {
        throw std::runtime_error("Write failure in WriteToken.");
    }
    return 0; 
}

int writeMatrix(string filename, Matrix<BaseFloat> &features){
    std::string my_token = "BF";
    std::ofstream outs(filename, std::ios_base::out | std::ios_base::binary);
    //writeToken(outs, my_token);
    int32 rows = features.NumRows();  // make the size 32-bit on disk.
    int32 cols = features.NumCols();
    if (features.Stride() == features.NumCols())
       outs.write(reinterpret_cast<const char*> (features.Data()), sizeof(float) * static_cast<size_t>(rows) * static_cast<size_t>(cols));
    else 
      for (MatrixIndexT i = 0; i < rows; i++) 
        outs.write(reinterpret_cast<const char*> (features.RowData(i)), sizeof(float)*cols);
    if (!outs.good()) {
      KALDI_ERR << "Failed to write matrix to stream";
    }    
    return 0; 
}

void printMatrix(string note, Matrix<BaseFloat> &features){
    int32 rows = features.NumRows();  // make the size 32-bit on disk.
    int32 cols = features.NumCols();
    std::cout << "\t" << note << " (" << rows << "," << cols << ")\n";
    if (cols == 0) { 
        std::cout << " [ ]\n";
    } else {
        std::cout << " [";
        for (MatrixIndexT i = 0; i < rows; i++) {
            std::cout << "\n  ";
            for (MatrixIndexT j = 0; j < cols; j++) 
                std::cout << features(i, j) << " "; 
        }    
        std::cout << "]\n";
    }    
}
