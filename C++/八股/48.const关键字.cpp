#include <iostream>
using namespace std;

class A{
public:
    int a;
    const int b = 2;

    A(){
        a = 1;
    }

    void func1(const A& obj){
        cout<<obj.a<<endl;
        cout<<obj.b<<endl;
    }
    void func2() const{

    }
};

int main(){
    const A a;
    A b;
    b.func1(a);

    system("pause");
}