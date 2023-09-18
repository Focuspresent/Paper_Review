#include <bits/stdc++.h>
#include <process.h>
using namespace std;

int main(){
    int ch;
    cin>>ch;
    switch(ch){
        case 0:{
            //错误路径
            _execl("..\\main.exe","main_test_0","wad","xaw","../../data/target.txt",NULL);
            break;
        }
        case 1:{
            //文本为空
            _execl("..\\main.exe","main_test_1","E:\\CODE\\data\\paper.txt","E:\\CODE\\data\\copy_paper2.txt","E:\\CODE\\data\\target.txt",NULL);
            break;
        }
        case 2:{
            //正确
            _execl("..\\main.exe","main_test_2","E:\\CODE\\data\\paper.txt","E:\\CODE\\data\\copy_paper1.txt","E:\\CODE\\data\\target.txt",NULL);
            break;
        }
    }
    return EXIT_SUCCESS;
}