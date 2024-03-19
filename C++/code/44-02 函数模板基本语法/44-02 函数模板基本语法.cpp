#include <iostream>
using namespace std;

void mySwapInt(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

void mySwapDouble(double& a, double& b){
    double temp = a;
    a = b;
    b = temp;
}

// 函数模板实现通用功能
// T是一个通用的类型，告诉编译器后面的函数或类中出现T别报错
template<typename T> 
void mySwap(T& a, T& b){
    T temp = a;
    a = b;
    b = temp;
}

template<typename T1, typename T2>
void mySwap2(T1& a, T2& b){
    T1 tmp = a;
    a = (T1)b;
    b = (T2)tmp;
}

void test1(){
    // int a = 1;
    // int b = 2;
    // mySwapInt(a, b);
    // cout<<a<<" "<<b<<endl;
    
    // double c = 1.1;
    // double d = 2.2;
    // mySwapDouble(c, d);
    // cout<<c<<" "<<d<<endl;

    int a = 1;
    int b = 2;
    // mySwap(1, b);
    mySwap(a, b);
    cout<<a<<" "<<b<<endl;

    double c = 1.1;
    double d = 2.2;
    mySwap(c, d);
    cout<<c<<" "<<d<<endl;

    char e = '1';
    mySwap<int>(a, b);
    // mySwap<int>(a, c);

    // mySwap();
    mySwap2<int, int>(a, b);

}

int main(){
    test1();

    system("pause");
    return 0;
}