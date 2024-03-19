#include <iostream>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <unordered_map>
using namespace std;

void func(){
    throw;
}

int main(){
    try{
        func();
    }
    catch(...){
        cout<<"异常"<<endl;
    }
    system("pause");
}