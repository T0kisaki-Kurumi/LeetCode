#include <iostream>
#include <string.h>
using namespace std;

void func(int* p){
    cout<<"int* p"<<endl;
}

void func(const int* p){
    cout<<"const int* p"<<endl;
}

void func1(int& a){
    cout<<"int& a"<<endl;
}

void func1(const int& a){
    cout<<"const int& a"<<endl;
}

// void func2(int x){
//     cout<<"int x"<<endl;
// }

// void func2(const int x){
//     cout<<"const int x"<<endl;
// }

int main() {
    int* p1;
    const int* p2 = nullptr;
    int* const p3 = nullptr;
    func(p1);
    func(p2);
    func(p3);

    int a = 1;
    int& b1 = a;
    const int& b2 = a;
    func1(b1);
    func1(b2);

    // int x1 = 1;
    // const int x2 = 2;
    // func2(x1);
    // func2(x2);

    system("pause");
    return 0;
} 