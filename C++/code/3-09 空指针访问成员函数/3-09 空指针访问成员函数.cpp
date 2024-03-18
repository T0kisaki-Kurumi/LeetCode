#include <iostream>
using namespace std;

class Person{
public:
    void showClassName(){
        cout<<"class name is Person"<<endl;
    }

    void showAge(){
        cout<<"age = "<<this->m_Age<<endl;
    }

    int m_Age;
};

int main(){
    // Person p;
    // p.m_Age = 18;
    // p.showAge();
    // p.showClassName();

    Person *p = nullptr;
    // p->showAge();
    p->showClassName();

    system("pause");
    return 0;
}