#include <iostream>
#include <string>
using namespace std;

#include "MyArray.h"

void test0(){
    MyArray * arr = new MyArray(10);
    delete arr;
    MyArray arr2;

    // for(int i=0; i<10; ++i){
    //     arr2.setData(i, i+100);
    // }

    for(int i=0; i<10; ++i){
        arr2.pushBack(i+50);
    }

    MyArray arr3(arr2);

    for(int i=0; i<10; ++i){
        cout<<arr3.getData(i)<<" ";
    }
    cout<<endl;

    arr3.setData(0, 114514);
    for(int i=0; i<10; ++i){
        cout<<arr3.getData(i)<<" ";
    }
    cout<<endl;
    cout<<arr3.getSize()<<" "<<arr3.getCapacity()<<endl;
}

int main(){
    test0();

    system("pause");
    return 0;
}