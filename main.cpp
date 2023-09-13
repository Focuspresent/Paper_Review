#include "fun.h"
using namespace std;

//基于jieba库进行论文查重
int main(int argc,char* argv[]){
    if(argc!=4){
        put_error("Parameter Quantity Error");
    }
    string orig_path=argv[1],origadd_path=argv[2],target_path=argv[3];
    //检测路径
    if(!check_path(orig_path)||!check_path(origadd_path)||!check_path(target_path)){
        put_error("File Path Error");
    }
    string paper=read_file(orig_path),copied_paper=read_file(origadd_path);
    //其中一个内容为空
    if(!paper.size()||!copied_paper.size()){
        put_error("File Size Empty");
    }
    system("pause");
}