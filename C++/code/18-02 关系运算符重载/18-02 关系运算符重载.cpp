#include <iostream>
#include <cstring>
using namespace std;

class Person{
public:
    Person(string name, int age){
        this->m_Name = name;
        this->m_Age = age;
    }

    bool operator==(const Person& p){
        return this->m_Name==p.m_Name && this->m_Age==p.m_Age;
    }
    
    // bool operator!=(const Person& p){
    //     return this->m_Name!=p.m_Name || this->m_Age!=p.m_Age;
    // }

    string m_Name;
    int m_Age;
};

bool operator!=(const Person& p1, const Person& p2){
    return p1.m_Name!=p2.m_Name || p1.m_Age!=p2.m_Age;
}

void test0(){
    Person p1("Tom", 11);
    Person p2("Tom", 10);
    cout<<(p1==p2)<<endl;
    cout<<(p1!=p2)<<endl;
}

int main(){
    test0();
    system("pause");
    return 0;
}