#include <iostream>
using namespace std;

class Base{
public:
    Base(){
        cout<<"调用Base的构造函数"<<endl;
    }

    
    ~Base(){
        cout<<"调用Base的析构函数"<<endl;
    }
};

class Son: public Base{
public:
    Son(){
        cout<<"调用Son的构造函数"<<endl;
    }

    
    ~Son(){
        cout<<"调用Son的析构函数"<<endl;
    }
};

void test1(){
    Base b;
    Son s;
}

class Base2{
public:
    Base2(int x){}
};

// 冒号后为基类
class Son2: public Base2{
public:
    // 冒号后为初始化列表
    Son2(): Base2(1){}
};

void test2(){
    Son2 s;
}

int main(){
    // test1();
    test2();

    system("pause");
    return 0;
}