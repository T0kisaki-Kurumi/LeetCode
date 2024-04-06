#include <iostream>
using namespace std;

class A
{
public:
    A() { cout << "构造" << endl; }
    A(const A &obj) { cout << "拷贝" << endl; }
    A(A &&obj) { cout << "移动" << endl; }

    ~A() { cout << "析构" << endl; }
};

void runcode(A &&m)
{
    cout << "rvalue ref" << endl;
}
void runcode(A &m)
{
    cout << "lvalue ref" << endl;
}
void runcode(const A &m)
{
    cout << "const lvalue ref" << endl;
}
void runcode(const A &&m)
{
    cout << "const rvalue ref" << endl;
}

template <typename T>
void Forwarding1(T t)
{
    runcode(t);
}

template <typename T>
void Forwarding2(T&& t)
{
    runcode(t);
}

template <typename T>
void PerfectForward(T &&t)
{
    runcode(forward<T>(t));
}

void test()
{
    A a;
    A b;
    const A c;
    const A d;
    cout<<endl;

    // Forwarding1(a);
    // cout << endl;
    // Forwarding1(move(b));
    // cout << endl;
    // Forwarding1(c);
    // cout << endl;
    // Forwarding1(move(d));
    // cout << endl;

    Forwarding2(a);
    cout << endl;
    Forwarding2(move(b));
    cout << endl;
    Forwarding2(c);
    cout << endl;
    Forwarding2(move(d));
    cout << endl;

    // PerfectForward(a);
    // cout << endl;
    // PerfectForward(move(b));
    // cout << endl;
    // PerfectForward(c);
    // cout << endl;
    // PerfectForward(move(d));
    // cout << endl;
    // cout << endl;
}

int main()
{
    test();

    system("pause");
}