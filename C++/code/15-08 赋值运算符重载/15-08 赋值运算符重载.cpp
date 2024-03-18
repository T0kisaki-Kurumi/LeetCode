#include <iostream>
#include <cstring>
using namespace std;

class Person{
public:
    Person(char* name, int age){
        this->m_Name = new char[strlen(name) + 1];
        strcpy(this->m_Name, name);
        this->m_Age = age;
    }

    Person(const Person& p){
        this->m_Name = new char[strlen(p.m_Name) + 1];
        strcpy(this->m_Name, p.m_Name);
        this->m_Age = p.m_Age;
    }

    Person& operator=(const Person& p){
        // // 系统默认生成以下两行，为浅拷贝，会导致悬垂指针，因此要重载
        // this->m_Name = p.m_Name;
        // this->m_Age = p.m_Age;
        if(this->m_Name != nullptr){
            delete[] this->m_Name;
            this->m_Name = nullptr;
        }
        this->m_Name = new char[strlen(p.m_Name) + 1];
        strcpy(this->m_Name, p.m_Name);
        this->m_Age = p.m_Age;
        return *this;
    }

    ~Person(){
        if(this->m_Name != nullptr){
            delete[] this->m_Name;
            this->m_Name = nullptr;
        }
    }

    char* m_Name;
    int m_Age;
};

void test0(){
    Person p1("Tom", 18);
    Person p2("Jerry", 19);
    cout<<p1.m_Name<<" "<<p1.m_Age<<endl;
    cout<<p2.m_Name<<" "<<p2.m_Age<<endl;

    // p1 = p2;
    // cout<<p1.m_Name<<" "<<p1.m_Age<<endl;
    // cout<<p2.m_Name<<" "<<p2.m_Age<<endl;

    Person p3("",0);
    p3 = p1 = p2;
    cout<<p3.m_Name<<" "<<p3.m_Age<<endl;

    Person p4(p3);
    cout<<p4.m_Name<<" "<<p4.m_Age<<endl;
}

int main(){
    test0();
    system("pause");
    return 0;
}