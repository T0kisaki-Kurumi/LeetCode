#include <iostream>
using namespace std;

class Person{
public:
    // Person(int age){
    //     age = age;
    //     age1 = age;
    // }
    Person(int age){
        this->age = age;
        this->age1 = age;
    }

    Person & addAge(int age){
        this->age += age;
        return *this;
    }

    // 错误，相当于返回了一个原对象的拷贝
    Person addAge1(int age){
        this->age1 += age;
        return *this;
    }

    int age;
    int age1;
};

int main(){
    Person p(18);
    // cout<<p.age<<" "<<p.age1<<endl;
    cout<<p.age<<" "<<p.age1<<endl; // 18 18
    p.addAge(1).addAge(2).addAge(3).addAge(4); // 链式编程
    cout<<p.age<<" "<<p.age1<<endl; // 28 18
    p.addAge1(1).addAge1(2).addAge1(3).addAge1(4); // 链式编程
    cout<<p.age<<" "<<p.age1<<endl; // 28 19， 相当于只执行了第一个addAge1(1)，后面都是对其他对象做的
    system("pause");
    return 0;
}