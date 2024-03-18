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

    virtual void num(int x){
        cout<<"动物认数："<<x<<endl;
    }
};

class Cat: public Animal{
public:
    void speak(){
        cout<<"小猫喵喵"<<endl;
    }
    
    void eat(){
        cout<<"小猫吃吃"<<endl;
    }

    void num(int x){
        cout<<"小猫认数："<<x<<endl;
    }
};

class Dog: public Animal{
public:
    void speak(){
        cout<<"小狗汪汪"<<endl;
    }
};

void test1() {
    Animal* a = new Cat;
    // a->speak();
    ((void (*)())(*(long long*)*(long long*)a))();
    ((void (*)())(*((long long*)*(long long*)a + 1)))();

    // ((void (*)(int))(*((long long*)*(long long*)a + 2)))(10);
    typedef void (__stdcall *func)(int);
    a->num(10);
    (func(*((long long*)*(long long*)a + 2)))(10);
}

int main(){
    test1();

    system("pause");
    return 0;
}