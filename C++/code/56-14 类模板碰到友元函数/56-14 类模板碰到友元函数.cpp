#include <iostream>
#include <string>
using namespace std;

template<class T1, class T2> class Person;
template<class T1, class T2> void showPerson2(Person<T1, T2>& p);

template<class T1, class T2>
void showPerson3(Person<T1, T2>& p){
    cout<<p.m_Name<<" "<<p.m_Age<<endl;
}

template<class T1, class T2>
class Person{
    friend void showPerson1(Person<T1, T2>& p){
        cout<<p.m_Name<<" "<<p.m_Age<<endl;
    }
    friend void showPerson2<>(Person<T1, T2>& p);
    friend void showPerson3<>(Person<T1, T2>& p);
public:
    Person(T1 name, T2 age){
        this->m_Name = name;
        this->m_Age = age;
    }
private:
    T1 m_Name;
    T2 m_Age;
};

template<class T1, class T2>
void showPerson2(Person<T1, T2>& p){
    cout<<p.m_Name<<" "<<p.m_Age<<endl;
}

void test1(){
    Person<string, int>p("aaa",1);
    showPerson1(p);
    showPerson2(p);
    showPerson3(p);
}
 
int main(){
    test1();

    system("pause");
    return 0;
}