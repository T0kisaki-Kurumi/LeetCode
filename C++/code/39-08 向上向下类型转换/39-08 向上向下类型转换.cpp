#include <iostream>
#include <cstring>
using namespace std;

class Animal{
public:
    virtual void speak(){
        cout<<"动物说话"<<endl;
    }
};

class Cat: public Animal{
public:
    void speak(){
        cout<<"小猫喵喵"<<endl;
    }
};

void test1(){
    // 向下类型转换，父类转子类，不安全
    Animal* a = nullptr;
    Cat* c = (Cat*)a;

    // 向上类型转换，子类转父类，安全
    Cat* c2 = nullptr;
    Animal* a2 = (Animal*)c2;
}

int main(){
    test1();

    system("pause");
    return 0;
}