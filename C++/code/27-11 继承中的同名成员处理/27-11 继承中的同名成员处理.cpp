#include <iostream>
using namespace std;

class Base{
public:
    Base(){
        this->m_A = 100;
    }

    int m_A;

    void func(){
        cout<<"Base"<<endl;
    }

    void func(int x){
        cout<<"Base"<<" "<<x<<endl;
    }
};

class Son: public Base{
public:
    Son(){
        this->m_A = 200;
    }

    int m_A;

    void func(){
        cout<<"Son"<<endl;
    }
};

void test1(){
    Son s;
    cout<<s.m_A<<endl;
    cout<<s.Base::m_A<<endl;
    s.func();
    s.Base::func();

    // s.func(10);  //报错，因为有参的func被隐藏了
    s.Base::func(10);
}
int main(){
    test1();

    system("pause");
    return 0;
}