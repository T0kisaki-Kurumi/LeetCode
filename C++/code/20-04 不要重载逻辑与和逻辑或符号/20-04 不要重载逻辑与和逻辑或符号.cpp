#include <iostream>
#include <string>
using namespace std;

class Complex{
public:
    Complex(int flag){
        this->flag = flag;
    }

    Complex& operator+=(const Complex& c){
        this->flag += c.flag;
        return *this;
    }

    bool operator&&(const Complex& c){
        return this->flag && c.flag;
    }

    int flag;
};

void test0(){
    Complex c1(0);
    Complex c2(1);
    cout<<(c1 && (c1+=c2))<<endl; // 原本应该直接根据c1就输出假，不再计算c1+=c2，但由于重载，失去了短路运算的特性，变成了先算括号内的东西，改变了c1的值，整个式子变为输出真。

    int a = 0;
    int b = 1;
    cout<<(a && (a+=b))<<endl;
}

int main(){
    test0();
    system("pause");
    return 0;
}