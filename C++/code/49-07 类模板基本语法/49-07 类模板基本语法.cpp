#include <iostream>
#include <string>
using namespace std;

template<class NAMETYPE, class AGETYPE = int>
class Person{
public:
    Person(NAMETYPE name, AGETYPE age){
        this->m_Age = age;
        this->m_Name = name;
    }

    NAMETYPE m_Name;
    AGETYPE m_Age;
};

void test1(){
    Person<string, int> p1("Tom", 18);
    Person<string> p2("Tom", 18); // 有默认类型的情况下才可以省略
}

int main(){
    test1();

    system("pause");
    return 0;
}