#include <iostream>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <unordered_map>
#include <vector>
#include <set>
#include <string.h>
using namespace std;

class A{
public:
    A(int a, int b): a(a), b(b){}
    A(int a): A(a, 0){}
    int a;
    int b;
    int c;
};

int main(){
    A a;
    cout<<a.a<<endl;

    system("pause");
}