#include "fun.h"
#include "cppjieba/Jieba.hpp"
using namespace std;

//错误提示
void put_error(string str){
    cout<<str;
    exit(-1);
}

//路径检测
bool check_path(string& path){
    return regex_match(path,regex("[a-z|A-Z]:([\\\\|/]\\w+)*[\\\\|/]\\w*(.\\w*|)"));
}

//读取文件到字符串
string read_file(string& path){
    ifstream fin;
    fin.open(path,ios::in);
    if(!fin.is_open()){
        put_error("File Open Error");
    }
    string ans;
    string s;
    while(getline(fin,s)) ans+=s;
    fin.close();
    //cout<<ans<<endl;
    return ans;
}

//写文件
void write_file(string& path,string text){
    ofstream fout;
    fout.open(path,ios::app);
    if(!fout.is_open()){
        put_error("File Open Error");
    }
    fout<<text<<endl;
    fout.close();
    return ;
};

//将字符串分词,并去掉标点符号
vector<string> spilt(string& text){
    cppjieba::Jieba jieba("E:/CODE/Git/Paper/cppjieba/dict/jieba.dict.utf8",
                          "E:/CODE/Git/Paper/cppjieba/dict/hmm_model.utf8",
                          "E:/CODE/Git/Paper/cppjieba/dict/user.dict.utf8",
                          "E:/CODE/Git/Paper/cppjieba/dict/idf.utf8",
                          "E:/CODE/Git/Paper/cppjieba/dict/stop_words.utf8");
    vector<string> orign,words;
    jieba.Cut(text,orign,true);
    unordered_set<string> stop{",",".","!","，","。","！","!","！","、","“","”",":","："};
    for(auto& word: orign){
        if(stop.count(word)) continue;
        words.push_back(word);
    }
    return words;
}

//计算文本相似度(余弦距离)
string count(string& text1,string& text2){
    //先分词
    vector<string> l1=spilt(text1),l2=spilt(text2);
    vector<int> v1,v2;
    //合并
    unordered_set<string> us;
    unordered_map<string,int> um;
    int index=0;
    //合并
    auto Union=[&](vector<string>& l){
        for(auto& n: l){
            if(us.count(n)) continue;
            um[n]=index++;
            us.insert(n);
        }
    };
    //转化
    auto ltov=[&](vector<string>& l,vector<int>& v){
        if(!index) {
            put_error("File Size Empty");
        }
        v.resize(index);
        for(auto& n: l){
            if(!us.count(n)) continue;
            v[um[n]]++;
        }
    };
    //计算余弦相似度
    auto getSim=[&](vector<int>& v1, vector<int>& v2)->double{
        double ans=0,m1=0,m2=0;
        for(int i=0;i<v1.size();i++){
            ans+=v1[i]*v2[i];
            m1+=v1[i]*v1[i];
            m2+=v2[i]*v2[i];
        }
        if(!m1||!m2){
            put_error("Zero Denominator");
        }
        return ans/(sqrt(m1)*sqrt(m2));
    };
    Union(l1);Union(l2);
    ltov(l1,v1);ltov(l2,v2);
    //格式化
    char ans[4];
    sprintf(ans,"%3.2f",getSim(v1,v2));
    return string(ans);
}