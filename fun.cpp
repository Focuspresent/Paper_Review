#include "fun.h"
#include "cppjieba/Jieba.hpp"
using namespace std;

//错误提示
void put_error(string str){
    cout<<str;
    exit(-1);
}

//路径检测
bool check_path(string path){
    return regex_match(path,regex("[a-z|A-Z]:([\\\\|/]\\w+)*[\\\\|/]\\w*(.\\w*|)"));
}

//jieba库测试
void test(){
    cppjieba::Jieba jieba("./cppjieba/dict/jieba.dict.utf8",
                          "./cppjieba/dict/hmm_model.utf8",
                          "./cppjieba/dict/user.dict.utf8",
                          "./cppjieba/dict/idf.utf8",
                          "./cppjieba/dict/stop_words.utf8");
    string text = "今天天气不错,我们一起出去玩吧!";
    vector<string> words;
    jieba.Cut(text,words,true);

    for (auto& word : words) {
        std::cout << word <<endl;
    }
    return ;
}