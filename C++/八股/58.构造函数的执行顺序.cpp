#include <iostream>
#include <string>
using namespace std;

class Other{
public:
    Other(){
        cout<<"Other类型成员对象构造函数"<<endl;
    }
};

class Base1{
public:
    Base1(){
        cout<<"普通父类Base1构造函数"<<endl;
    }
};

class Base2{
public:
    Base2(){
        cout<<"普通父类Base2构造函数"<<endl;
    }
};

class VBase1{
public:
    VBase1(){
        cout<<"虚拟父类VBase1构造函数"<<endl;
    }
    int v1;
};

class VBase2{
public:
    VBase2(){
        cout<<"虚拟父类VBase2构造函数"<<endl;
    }
    int v2;
};

class Son: public Base2, public Base1, virtual public VBase2, virtual public VBase1{
public:
    Other o1;

    Son(){
        cout<<"子类Son构造函数"<<endl;
    }
};


int main(){
    Son s;

    system("pause");
	return 0;
}

// 虚拟父类VBase2构造函数
// 虚拟父类VBase1构造函数
// 普通父类Base2构造函数
// 普通父类Base1构造函数
// Other类型成员对象构造函数
// 子类Son构造函数