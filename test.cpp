#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

class A{
public:
    A(){
        cout<<"默认构造函数"<<endl;
    }
    // A(const A& obj){
    //     cout<<"拷贝构造函数"<<endl;
    // }
    A(A&& obj){
        cout<<"移动构造函数"<<endl;
    }

    int x;
};

void func(A a){
    return;
}

void test(){
    A a;
    // func(a);
    func(move(a));
}

int main(){
    test();

    system("pause");
    return 0;
}