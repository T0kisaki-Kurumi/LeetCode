#include <iostream>
using namespace std;

class Person{
public:
    int m_A;
    int m_B;

    Person(){}

    Person(int a, int b): m_A(a), m_B(b){}

    // 利用成员函数对加号运算符重载
    Person operator+(Person &p){
        Person temp;
        temp.m_A = this->m_A + p.m_A;
        temp.m_B = this->m_B + p.m_B;
        return temp; 
    }

    // 运算符重载发生函数重载
    Person operator+(int a){
        Person temp;
        temp.m_A = this->m_A + a;
        temp.m_B = this->m_B + a;
        return temp; 
    }

// private:
//     int m_A;
//     int m_B;
};

// // 利用全局函数对加号运算符重载
// Person operator+(Person &p1, Person &p2){
//     Person temp;
//     temp.m_A = p1.m_A + p2.m_A;
//     temp.m_B = p1.m_B + p2.m_B;
//     return temp;
// }

void test0(){
    Person p1(10,20);
    Person p2(30,40);

    Person p3 = p1 + p2;
    // Person p3 = p1.operator+(p2);
    // Person p3 = operator+(p1, p2);
    cout<<p3.m_A<<" "<<p3.m_B<<endl;

    Person p4 = p1 + 10;
    cout<<p4.m_A<<" "<<p4.m_B<<endl;

}

int main(){
    test0();

    system("pause");
    return 0;
}