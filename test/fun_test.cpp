#include "../fun.h"
#include "cppjieba/Jieba.hpp"

void check_path_test(){
    //相对路径
    string s1=".\\test",s2="saxaxa",s3="E:\\hah\\hha.txt";
    cout<<check_path(s1)<<endl;
    //错误路径
    cout<<check_path(s2)<<endl;
    //绝对路径
    cout<<check_path(s3)<<endl;
}

void spilt_test(){
    //打印函数
    auto print=[&](string& s){
        for(auto& w: spilt(s)){
            cout<<w<<" ";
        }
        cout<<endl;
    };
    //
    string s1="你说的对但是原神是由米哈游自主研发的一款全新开放世界冒险游戏游戏发生在一个被称作提瓦特的幻想世界在这里被神选中的人将被授予神之眼导引元素之力你将扮演一位名为旅行者的神秘角色在自由的旅行中邂逅性格各异能力独特的同伴们和他们一起击败强敌找回失散的亲人的同时逐步发掘原神的真相";
    string s2="我认为， 识之律者女士万岁，发生了会如何，不发生又会如何。 识之律者女士万岁，发生了会如何，不发生又会如何。 要想清楚，识之律者女士万岁，到底是一种怎么样的存在。 而这些并不是完全重要，更加重要的问题是， 了解清楚识之律者女士万岁到底是一种怎么样的存在，是解决一切问题的关键。 这种事实对本人来说意义重大，相信对这个世界也是有一定意义的。 既然如此， 就我个人来说，识之律者女士万岁对我的意义，不能不说非常重大。 带着这些问题，我们来审视一下识之律者女士万岁。 要想清楚，识之律者女士万岁，到底是一种怎么样的存在。 所谓识之律者女士万岁，关键是识之律者女士万岁需要如何写。";
    print(s1);print(s2);
}

void count_test(){
    string s1="生活中，若你说的对出现了，我们就不得不考虑它出现了的事实。 既然如何， 一般来说， 那么， 这种事实对本人来说意义重大，相信对这个世界也是有一定意义的。 我们都知道，只要有意义，那么就必须慎重考虑。";
    string s2="一般来说， 现在，解决你说的对的问题，是非常非常重要的。 所以， 阿卜·日·法拉兹曾经说过，学问是异常珍贵的东西，从任何源泉吸收都不可耻。我希望诸位也能好好地体会这句话。 美华纳在不经意间这样说过，勿问成功的秘诀为何，且尽全力做你应该做的事吧。带着这句话，我们还要更加慎重的审视这个问题： ";
    cout<<count(s1,s2)<<endl;
}

void jieba_test(){
    cppjieba::Jieba jieba("E:/CODE/Git/Paper/cppjieba/dict/jieba.dict.utf8",
                          "E:/CODE/Git/Paper/cppjieba/dict/hmm_model.utf8",
                          "E:/CODE/Git/Paper/cppjieba/dict/user.dict.utf8",
                          "E:/CODE/Git/Paper/cppjieba/dict/idf.utf8",
                          "E:/CODE/Git/Paper/cppjieba/dict/stop_words.utf8");
    string s1="生活中，若你说的对出现了，我们就不得不考虑它出现了的事实。 既然如何， 一般来说， 那么， 这种事实对本人来说意义重大，相信对这个世界也是有一定意义的。 我们都知道，只要有意义，那么就必须慎重考虑。";
    vector<string> words;
    jieba.Cut(s1,words,true);
    for(auto& word: words){
        cout<<word<<" ";
    }
    cout<<endl;
}

int main(){
    jieba_test();
    check_path_test();
    spilt_test();
    count_test();
    system("pause");
}