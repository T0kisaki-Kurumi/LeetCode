#include <iostream>
using namespace std;

class Person{
    friend ostream& operator<<(ostream &cout, const Person &p);
public:

    Person(){}

    Person(int a, int b): m_A(a), m_B(b){}

    // // 利用成员函数对左移运算符重载（顺序不对，不能用）
    // void operator<<(ostream &cout){
    //     cout<<this->m_A<<" "<<this->m_B<<endl;
    // }

private:
    int m_A;
    int m_B;
};

// 利用全局函数对左移运算符重载
ostream& operator<<(ostream &cout, const Person &p){
    cout<<p.m_A<<" "<<p.m_B;
    return cout;
}

void test0(){
    Person p1(10,20);
    // cout<<p1.m_A<<" "<<p1.m_B<<endl;
    // p1.operator<<(cout);
    // p1<<cout; // 不是想要的顺序
    cout<<p1<<endl;
}

int main(){
    test0();

    system("pause");
    return 0;
}