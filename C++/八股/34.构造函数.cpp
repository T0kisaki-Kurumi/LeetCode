#include <iostream>
using namespace std;

class A{
public:
    A(): a(0), b(0), c(0), p(nullptr){}                             // 默认构造函数
    A(int a, int b, int c, char* p): a(a), b(b), c(c), p(p){}       // 初始化构造函数
    A(const A& obj): a(obj.a), b(obj.b), c(obj.c){/*为p开辟空间，把obj中的p指向的空间的内容复制过来，等等*/}     // 拷贝构造函数
    A(string s): a((int)(s[0]-'0')), b(0), c(0), p(nullptr){}       // 转换构造函数
    A(A&& obj): a(obj.a), b(obj.b), c(obj.c), p(obj.p){obj.p = nullptr;} //移动构造函数，因为obj变为了将亡值，要将obj.p指向nullptr，否则会调用obj的析构把“偷”来的这块内存中的东西删掉
    A(int a): A(a, 0, 0, nullptr){}                                 //委托构造函数，委托另一个构造函数构造，然后再执行自己的函数体

public:
    int a;
    int b;
    int c;
    char* p;
};

int main(){
    

    system("pause");
}