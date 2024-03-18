#include <iostream>
#include <fstream>
using namespace std;

void test1(){
    // ofstream ofs("./HeiMa2017/code/72-15 文件的读写/test.txt", ios::out | ios::trunc);
    ofstream ofs;
    ofs.open("./HeiMa2017/code/72-15 文件的读写/test.txt", ios::out | ios::trunc);
    if(!ofs.is_open()){
        cout<<"文件打开失败"<<endl;
        return;
    }
    ofs<<"Hello world!"<<endl;
    ofs<<"Hello world!"<<endl;
    ofs<<"Hello world!";
    ofs.close();
}

void test2(){
    ifstream ifs;
    ifs.open("./HeiMa2017/code/72-15 文件的读写/test.txt", ios::in);
    if(!ifs){
        cout<<"文件打开失败"<<endl;
        return;
    }
    // //第一种方式
    // char buf[1024] = {0};
    // while(ifs>>buf){
    //     cout<<buf<<endl;
    // }

    // //第二种方式
    // char buf[1024] = {0};
    // while(!ifs.eof()){
    //     ifs.getline(buf, 1024);
    //     cout<<buf<<endl;
    // }

    //第三种方式
    char c;
    while((c=ifs.get()) != EOF){
        cout<<c;
    }

    ifs.close();
}

int main(){
    // test1();
    test2();

    system("pause");
    return 0;
}