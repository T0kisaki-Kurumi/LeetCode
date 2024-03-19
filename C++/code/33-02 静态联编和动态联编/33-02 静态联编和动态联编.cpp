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
};

class Cat: public Animal{
public:
    virtual void speak() override{
        cout<<"小猫喵喵"<<endl;
    }
};

class Dog: public Animal{
public:
    void speak(){
        cout<<"小狗汪汪"<<endl;
    }
};

void doSpeak(Animal &animal){
    animal.speak();
}

void test1(){
    Cat c;
    doSpeak(c);
    Dog d;
    doSpeak(d);
    // Animal a = c;
    // doSpeak(a);
}

int main(){
    test1();

    system("pause");
    return 0;
}