#include <iostream>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
using namespace std;

int main(){
    char* str = "12345";
    cout<<strspn(str, "5")<<endl;

    system("pause");
}