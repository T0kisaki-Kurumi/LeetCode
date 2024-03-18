#include <iostream>
#include <string>
using namespace std;

template<class NAMETYPE, class AGETYPE>
class Person{
public:
    Person(NAMETYPE name, AGETYPE age){
        this->m_Age = age;
        this->m_Name = name;
    }

    NAMETYPE m_Name;
    AGETYPE m_Age;
};

// 指定参数类型
void doWork1(Person<string, int>& p){
    cout<<p.m_Name<<" "<<p.m_Age<<endl;
}

// 参数模板化
template<class T1, class T2>
void doWork2(Person<T1, T2>& p){
    cout<<p.m_Name<<" "<<p.m_Age<<endl;
}

// 整个类模板化
template<class T>
void doWork3(T& p){
    cout<<p.m_Name<<" "<<p.m_Age<<endl;
}

void test1(){
    Person<string, int> p("aaa", 10);
    doWork1(p);
    doWork2(p);
    doWork3(p);
}

int main(){
    test1();

    system("pause");
    return 0;
}