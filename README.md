# kaldi_feature (static lib)
kaldi feature module from [kaldi](http://kaldi-asr.org) toolkit
## 说明：
- 本模块从kaldi中提取，不需要任何外部依赖，不同于[kaldi-io](https://github.com/open-speech/kaldi-io)，需要指定数学库路径
- 对原始的kaldi读取wave语音和scp，ark格式进行了提取，可以直接读取wave语音，特征数据写为二进制格式文件
- 数学库采用mkl
- 采用静态库方便不同机器上进行拷贝和使用
## 注意：
- 由于libmkl_core.a 文件太大，超过GitHub 单个文件100M的限制，需要安装git-lfs，
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
  - extract mfcc 提取MFCC特征
    - ./build/bin/compute_mfcc wavefile
  - extract fbank-> cmvn -> vad 提取fbank特征并进行CMNV和vad操作
    - ./build/bin/compute_fbank_cmvn_vad wavefile outfile
  - vad 对音频进行vad去除静音并输出非静音段
    - ./build/bin/kaldi_vad_tool wavpath outwavpath
  - 对长语音段进行切分,切分为指定长度（切分根据vad，在静音段段处进行切分）
    - ./build/bin/kaldi_split wavpath length outwavdir  

