#include <iostream>
using namespace std;

class Animal{
public:
    // void speak(){
    //     cout<<"动物说话"<<endl;
    // }

    virtual void speak(){
        cout<<"动物说话"<<endl;
    }

    virtual void eat(){
        cout<<"动物吃东西"<<endl;
    }
};

class Cat: public Animal{
public:
    void speak(){
        cout<<"小猫喵喵"<<endl;
    }
};

class Dog: public Animal{
public:
    void speak(){
        cout<<"小狗汪汪"<<endl;
    }
};

void test1(){
    // 通过引用实现多态
    Cat c;
    Animal &a1 = c;
    a1.speak();

    // 通过指针实现多态
    Animal* a2 = new Dog;
    a2->speak();
}

int main(){
    test1();

    system("pause");
    return 0;
}