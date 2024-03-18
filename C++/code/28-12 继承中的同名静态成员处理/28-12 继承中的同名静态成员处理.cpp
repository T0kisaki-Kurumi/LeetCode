#include <iostream>
using namespace std;

class Base{
public:
    static int m_A;
    static void func(){
        cout<<"Base func"<<endl;
    }
    static void func(int x){
        cout<<"Base func int"<<endl;
    }
};

int Base::m_A = 100;

class Son: public Base{
public:
    static int m_A;
    static void func(){
        cout<<"Son func"<<endl;
    }
};

int Son::m_A = 200;

void test1(){
    Son s;
    cout<<s.m_A<<endl;
    cout<<s.Base::m_A<<endl;
    cout<<Son::m_A<<endl;
    cout<<Base::m_A<<endl;
    cout<<Son::Base::m_A<<endl;

    s.func();
    s.Base::func();
    // s.func(1);
    Son::func();
    Base::func();
    Son::Base::func();
}

int main(){
    test1();

    system("pause");
    return 0;
}