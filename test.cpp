#include <iostream>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <unordered_map>
using namespace std;

class A{
public:
    int a = 10;
    A(int x){
        cout<<x<<endl;
    }
};

int main(){
    A a = 5;
    system("pause");
}