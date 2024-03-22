#include <iostream>
using namespace std;

void test1(){
    int a = 0x1234;
    char b = (char)(a);
    if(b == 0x12){
        cout<<"大端"<<endl;
    }
    else if(b == 0x34){
        cout<<"小端"<<endl;
    }
}

void test2(){
    union U{
        int a;
        char b;
    } test;
    test.a = 0x1234;
    if(test.b == 0x12){
        cout<<"大端"<<endl;
    }
    else if(test.b == 0x34){
        cout<<"小端"<<endl;
    }
}

int main(){
    test1();
    test2();

    system("pause");
}