#include <iostream>
using namespace std;

void swap1(int& a, int& b){
    a = a - b;
    b = b + a;
    a = b - a;
}

void swap2(int& a, int& b){
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

int main(){
    int a = 1;
    int b = 2;
    swap1(a, b);
    cout<<a<<" "<<b<<endl;
    swap2(a, b);
    cout<<a<<" "<<b<<endl;

    system("pause");
}