#pragma once

#include <iostream>
#include <cstring>
using namespace std;

class MyString{
    friend ostream& operator<<(ostream& cout, const MyString& str);
    friend void operator>>(istream& cin, MyString& str);
public:
    // 有参构造函数
    MyString(char* str);

    // 拷贝构造函数
    MyString(const MyString& str);

    // 重载[]运算符
    char& operator[](int index);

    // 重载=运算符
    MyString& operator=(char* str);
    MyString& operator=(const MyString& str);

    // 重载+运算符
    MyString operator+(char* str);
    MyString operator+(const MyString& str);

    // 重载==运算符
    bool operator==(char* str);
    bool operator==(const MyString& str);

    // 析构函数
    ~MyString();

private:
    // 指向堆区的字符串指针
    char* pString;
    // 字符串长度
    int m_Size;
};