#include <iostream>
using namespace std;

template<class T>
class Base{
    T m_A;
};

class Son1: public Base<int>{

};

template<class T1, class T2>
class Son2: public Base<T2>{
    T1 m_B;
};

void test1(){
    Son2<int, double> s;
}

int main(){
    test1();

    system("pause");
    return 0;
}