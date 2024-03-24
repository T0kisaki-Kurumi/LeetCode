#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
using namespace std;

class A{
public:
    A(){}
    ~A(){cout<<"~A"<<endl;}
};

class B{
public:
    B():a(){}
    ~B(){cout<<"~B"<<endl;}

    A a;
};

void test(){
    B b;
}
 
int main(){
    test();

    system("pause");
    return 0;
}