#include <iostream>
using namespace std;

int myPlus(int a, int b){
    return a + b;
}

template<class T>
int myPlus2(T a, T b){
    return a + b;
}

void test1(){
    int a = 10;
    int b = 20;
    char c = 'c';
    cout<<myPlus(a, c)<<endl;
    // cout<<myPlus2(a, c)<<endl;
}

template<class T>
void myPrint(T a){
    cout<<"调用函数模板"<<endl;
}

template<class T>
void myPrint(T a, T b){
    cout<<"调用重载的函数模板"<<endl;
}

// void myPrint(int a);

void myPrint(int a){
    cout<<"调用普通函数"<<endl;
}

void test2(){
    int a = 1;
    myPrint(a);
    myPrint<>(a);
    myPrint(a,a);

    char c = 'c';
    myPrint(c);
}

int main(){
    // test1();
    test2();

    system("pause");
    return 0;
}