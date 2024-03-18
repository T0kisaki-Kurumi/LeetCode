#include <iostream>
using namespace std;
#include "MyString.h"

void test1(){
    MyString str = "abc";
    cout<<str<<endl;
    cout<<"请重新给str赋值:";
    cin>>str;
    cout<<str<<endl;
    MyString str2(str);
    cout<<str2<<endl;
}

void test2(){
    MyString str("abcd");
    cout<<str[0]<<endl;
    str[0] = 'w';
    cout<<str<<endl;
}

void test3(){
    MyString str = "hello";
    MyString str2 = "aa";
    cout<<str2<<endl;
    str2 = str;
    cout<<str2<<endl;
    str2 = "world";
    cout<<str2<<endl;
}

void test4(){
    MyString str1 = "abc";
    MyString str2 = "def";
    MyString str3 = str1 + str2;
    cout<<str3<<endl;
    str3 = str1 + "666";
    cout<<str3<<endl;
}

void test5(){
    MyString str1 = "abc";
    MyString str2 = "def";
    char* str3 = "abc";
    cout<<(str1 == str2)<<endl;
    cout<<(str1 == str3)<<endl;
}

int main(){
    // test1();
    // test2();
    // test3();
    // test4();
    test5();

    system("pause");
    return 0;
}