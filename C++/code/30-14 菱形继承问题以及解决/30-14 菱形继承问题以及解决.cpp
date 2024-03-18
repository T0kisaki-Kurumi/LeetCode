#include <iostream>
using namespace std;

class Animal{
public:
    int m_Age;
};

class Sheep: virtual public Animal{
public:

};

class Tuo: virtual public Animal{
public:

};

class SheepTuo: public Sheep, public Tuo{
public:

};

void test1(){
    SheepTuo st;
    // st.m_Age = 10;  // 由于二义性无法直接访问
    st.Sheep::m_Age = 10;
    st.Tuo::m_Age = 20;
    cout<<st.Sheep::m_Age<<endl;
    cout<<st.Tuo::m_Age<<endl;
    cout<<st.m_Age<<endl;
}

int main(){
    test1();

    system("pause");
    return 0;
}