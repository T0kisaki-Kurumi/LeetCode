#include <iostream>
#include <string>
using namespace std;

class MyFunc{
public:
    void operator()(string s){
        cout<<s<<endl;
    }
};

class MyAdd{
public:
    int operator()(int a, int b){
        return a+b;
    }
};

void test0(){
    MyFunc func;
    func("Hello world!"); // 仿函数，直接用对象实现函数的功能
    MyFunc()("123"); // 匿名函数对象

    MyAdd add;
    cout<<add(1,2)<<endl;
}

int main(){
    test0();
    system("pause");
    return 0;
}