#include <iostream>
using namespace std;

class Base{
public:
    Base(int a){
        cout<<"父类构造函数"<<endl;
    }
};

class Other{
public:
    Other(int a){
        cout<<"成员对象构造函数"<<endl;
    }
};

class Foo: public Base{
public:
    const int x;
    int& y;
    Other o;

public:
    Foo(int x, int y): o(2), Base(1), x(x), y(y){

    }
};

int main() {
    int x=1;
    int y=2;
    Foo f(x, y);

    system("pause");
    return 0;
} 