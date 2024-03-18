#include <iostream>
using namespace std;

class A{
public:
    int a;
protected:
    int b;
private:
    int c;
};

class B1: public A{
public:
    void func(){
        a = 1;
        b = 2;
        // c = 3;
    }
};

class B2: protected A{
public:
    void func(){
        a = 1;
        b = 2;
        // c = 3;
    }
};

class B3: private A{
public:
    void func(){
        a = 1;
        b = 2;
        // c = 3;
    }
};

class C3: public B3{
public:
    void func(){
        // a = 1;
    }
};

void test1(){
    B1 b1;
    b1.a = 11;
    B2 b2;
    // b2.a = 11;  // B2类的a是protected，类外不能访问
    B3 b3;
    // b3.a = 11;  // B3类的a是private，类外不能访问
}

void test2(){
    cout<<sizeof(A)<<endl;
    cout<<sizeof(B1)<<endl;
    cout<<sizeof(B2)<<endl;
    cout<<sizeof(B3)<<endl;
    cout<<sizeof(C3)<<endl;
}

int main(){
    // test1();
    test2();

    system("pause");
    return 0;
}