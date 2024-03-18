#include <iostream>
#include <string>
using namespace std;

#include "MyArray.h"

void test0(){
    MyArray arr(10);
    arr.setData(0, 1);
    cout<<arr[0]<<endl;
    arr[0] = 114;
    cout<<arr[0]<<endl;
}

int main(){
    test0();

    system("pause");
    return 0;
}