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
using namespace std;

int& f(){
    int* a = new int(1);
    return *a;
}

int main(){
    int* p = f();
    cout<<*p<<endl;
    delete p;
    p = nullptr;
    system("pause");
}