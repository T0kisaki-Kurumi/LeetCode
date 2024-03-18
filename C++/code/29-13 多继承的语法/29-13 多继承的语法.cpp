#include <iostream>
using namespace std;

class Base1{
public:
    Base1():m_A(1), m_Z(111){}
    int m_A;
    int m_Z;
};

class Base2{
public:
    Base2():m_B(2), m_Z(222){}
    int m_B;
    int m_Z;
};

class Son: public Base1, public Base2{
public:
    int m_C;
    int m_D;
};

void test1(){
    cout<<sizeof(Son)<<endl;
    Son s;
    cout<<s.m_A<<endl;
    cout<<s.m_B<<endl;
    // cout<<s.m_Z<<endl;
    cout<<s.Base1::m_Z<<endl;
    cout<<s.Base2::m_Z<<endl;
    
}

int main(){
    test1();

    system("pause");
    return 0;
}