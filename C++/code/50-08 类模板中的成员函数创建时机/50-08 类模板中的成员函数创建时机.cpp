#include <iostream>
#include <string>
using namespace std;

class Person1{
public:
    void show1(){
        cout<<"Person1"<<endl;
    }
};

class Person2{
public:
    void show2(){
        cout<<"Person2"<<endl;
    }
};

template<class T>
class C{
public:
    T obj;

    void func1(){
        obj.show1();
    }

    void func2(){
        obj.show2();
    }
};

void test1(){
    C<Person1> c1;
    c1.func1();
    // c1.func2();

    C<Person2> c2;
    c2.func2();
}

int main(){
    test1();

    system("pause");
    return 0;
}