#include <iostream>
#include <string>
using namespace std;

class Person{
public:
    Person(string name, int age){
        this->m_Age = age;
        this->m_Name = name;
    }

    string m_Name;
    int m_Age;
};

template<class T>
bool myCompare(T& a, T& b){
    cout<<"调用原始函数模板"<<endl;
    return a==b;
}

template<>
bool myCompare(Person& a, Person& b){
    cout<<"调用具体化的函数模板"<<endl;
    return a.m_Age==b.m_Age && a.m_Name==b.m_Name;
}

void test1(){
    Person a("Tom", 18);
    Person b("Tom", 18);
    Person c("Jerry", 15);
    int d = 1;
    cout<<myCompare(d, d)<<endl;
    cout<<myCompare(a, b)<<endl;
    cout<<myCompare(a, c)<<endl;

}

int main(){
    test1();

    system("pause");
    return 0;
}