#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int func(int a[]){
    cout<<a[3]<<endl;
    return 0;
}

void func2(int a[][3]){
    cout<<a[1][2]<<endl;
}

int main(){
    int a=5;
	cout<<a/3*3<<endl;

    system("pause");
}