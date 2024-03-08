#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int main(){
    char * a = "12345";
    char * b;
    // memcpy(b, a, strlen(a) + 1);
    strcpy(b,a);
    cout<<strlen(b)<<endl;

    system("pause");
}