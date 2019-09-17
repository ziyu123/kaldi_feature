# kaldi_feature (static lib)
kaldi feature module from [kaldi](http://kaldi-asr.org) toolkit
## 说明：
- 本模块从kaldi中提取，不需要任何外部依赖，不同于[kaldi-io](https://github.com/open-speech/kaldi-io)，需要指定数学库路径
- 对原始的kaldi读取wave语音和scp，ark格式进行了提取，可以直接读取wave语音，特征数据写为二进制格式文件
- 数学库采用mkl
## 注意：
- 由于libmkl_core.a 文件太大，超过GitHub 单个文件100M的限制，所以需要clone后，自己拷贝libmkl_core.a文件(版本2017.0.098)
## 编译:
- **requirements:**
  - cmake >= 2.8
- **compile:**
    ```
    cd kaldi_feaure
    mkdir build && cd build
    cmake ..
    make
    ```
- **after compile:**
  - build/libkaldi_featue.a
  - bin subdirs
- **usage:**
  - extract mfcc
    - ./build/bin/compute_mfcc wavefile
  - extract fbank-> cmvn -> vad
    - ./build/bin/compute_fbank_cmvn_vad wavefile outfile
  - . . .

