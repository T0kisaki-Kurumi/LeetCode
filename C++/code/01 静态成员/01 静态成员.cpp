#include <iostream>
using namespace std;

class Person{
public:
    static int m_A;
};

int Person::m_A = 100;

int main(){
    Person p;
    cout<<p.m_A<<endl;
    cout<<Person::m_A<<endl;
    system("pause");
    return 0;
}