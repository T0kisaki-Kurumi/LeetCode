#include <iostream>
using namespace std;

class Person{
public:
    Person(int age){
        cout<<"调用有参构造函数"<<endl;
        this->m_Age = age;
    }

    void showAge(){
        cout<<this->m_Age<<endl;
    }

    ~Person(){
        cout<<"调用析构函数"<<endl;
    }

private:
    int m_Age;
};

// 智能指针，用来托管new出来的对象的释放
class SmartPointer{
public:
    SmartPointer(Person* person){
        cout<<"调用smart构造函数"<<endl;
        this->person = person;
    }

    // 重载->运算符
    Person* operator->(){
        return this->person;
    }

    // 重载*运算符
    Person& operator*(){
        return *(this->person);
    }

    ~SmartPointer(){
        cout<<"调用smart析构函数"<<endl;
        if(this->person != nullptr){
            delete this->person;
            this->person = nullptr;
        }
    }

private:
    Person *person;
};

void test0(){
    // Person *p = new Person(18);
    // delete p;
    SmartPointer sp(new Person(18));
    // sp->->showAge();
    sp->showAge();
    (*sp).showAge();
}

int main(){
    test0();
    system("pause");
    return 0;
}