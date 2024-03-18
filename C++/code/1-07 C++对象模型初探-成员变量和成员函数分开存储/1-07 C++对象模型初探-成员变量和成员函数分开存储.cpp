#include <iostream>
using namespace std;

// # pragma pack(8)

class Person{
public:
    int x;

    void func(){

    }

    static int y;

    double z;
};

// int Person::y = 1;

int main(){
    cout<<sizeof(Person)<<endl;
    Person p;
    // cout<<p.y<<endl;
    system("pause");
    return 0;
}