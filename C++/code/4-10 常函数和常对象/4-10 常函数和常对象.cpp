#include <iostream>
using namespace std;

class Person{
public:
    void showAge(){
        this->m_Age = 10;
        // this = nullptr;
        cout<<this->m_Age<<endl;
    }

    void showAge2() const{
        cout<<this->m_B<<endl;
    }

    // 常函数，不可以修改成员属性
    void changeAge() const{
        // this->m_Age = 10;
        cout<<"常函数不能修改成员属性"<<endl;
        cout<<this->m_Age<<endl;
        // mutable关键字修饰的成员属性可以修改
        this->m_B = 100;
    }

    Person(){}

    int m_Age;
    mutable int m_B;
};

int main(){
    Person p1;
    p1.m_Age = 18;
    p1.showAge();
    p1.changeAge();

    const Person p2;
    // p2.m_Age = 18;
    p2.m_B = 18;
    // p2.showAge();
    p2.showAge2();

    

    system("pause");
    return 0;
}