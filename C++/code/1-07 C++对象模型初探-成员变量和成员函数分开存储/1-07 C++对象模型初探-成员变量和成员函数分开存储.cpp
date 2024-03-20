#include <iostream>
using namespace std;

# pragma pack(8)

class Empty{

};

class Person{
public:
    int x;  // int 4字节    double 8字节    char 1字节

    void func(){

    }

    static int y;

    double z;
};

class packTest{
public:
    char a;
    double c;
    int b;
};

// int Person::y = 1;

int main(){
    cout<<sizeof(Empty)<<endl;
    cout<<sizeof(Person)<<endl;
    cout<<sizeof(packTest)<<endl;
    Person p;
    // cout<<p.y<<endl;

    packTest pt;
    cout<<&pt<<" "<<&(pt.a)<<" "<<&(pt.b)<<" "<<&(pt.c)<<endl;

    system("pause");
    return 0;
}