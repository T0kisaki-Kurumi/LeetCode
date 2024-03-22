#include <iostream>
using namespace std;

class A{
public:
    A(int a, int b=2, int c=1): a(a), b(b), c(c) {}
    int a,b,c;
};

int main() {
    A a1 = 3;
    cout<<a1.a<<a1.b<<a1.c<<endl;
    
    system("pause");
    return 0;
} 