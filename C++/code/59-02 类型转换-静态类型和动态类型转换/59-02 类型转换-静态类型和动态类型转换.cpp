#include <iostream>
#include <string>
using namespace std;

class Base{
    virtual void func(){}
};

class Son:public Base{
    virtual void func() override{}
};

class Other{

};

// 1. 静态类型转换
void test1(){
    // 内置数据类型
    char a = 'a';
    double d = static_cast<double>(a);
    cout<<d<<endl;

    Base* base = nullptr;
    Son* son = nullptr;
    
    // 向下类型转换
    Son* son2 = static_cast<Son*>(base);
    // 向上类型转换
    Base* base2 = static_cast<Base*>(son);
    // 转为其他类型，没有父子关系，无法转换
    // Other* other = static_cast<Other*>(base);

    // 必须是指针或引用
    // Base base3;
    // Son son3 = static_cast<Son>(base3);
}

// 2. 动态类型转换
void test2(){
    // 内置数据类型不允许动态转换
    // char a = 'a';
    // double d = dynamic_cast<double>(a);
    // cout<<d<<endl;

    Base* base = nullptr;
    Son* son = nullptr;
    
    // 直接向下类型转换,不安全，不允许
    // Son* son2 = dynamic_cast<Son*>(base);
    // 向上类型转换
    Base* base2 = dynamic_cast<Base*>(son);

    // 发生多态时，总是安全的，允许向下类型转换
    Base* base3 = new Son;
    Son* son3 = dynamic_cast<Son*>(base3);

}
 
int main(){
    // test1();
    test2();

    system("pause");
    return 0;
}