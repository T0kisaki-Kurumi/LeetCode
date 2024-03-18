#include <iostream>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <unordered_map>
using namespace std;

int main(){
    int a = 1;
    int b = 2;
    int* const p1 = &a;
    p1 = &b;
    *p1 = 0;
    int const* p2 = &a;
    p2 = &b;
    *p2 = 0;
    const int* p3 = &a;
    p3 = &b;
    *p3 = 0;
    system("pause");
}