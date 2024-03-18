#include "MyString.h"

ostream& operator<<(ostream& cout, const MyString& str){
    cout<<str.pString;
    return cout;
}

void operator>>(istream& cin, MyString& str){
    if(str.pString != nullptr){
        delete[] str.pString;
        str.pString = nullptr;
    }
    char buf[1024]; // 缓冲区
    cin>>buf;
    str.pString = new char[strlen(buf)+1];
    strcpy(str.pString, buf);
    str.m_Size = strlen(buf);
}

MyString::MyString(char *str){
    this->pString = new char[strlen(str)+1];
    strcpy(this->pString, str);
    this->m_Size = strlen(str);
}

MyString::MyString(const MyString &str){
    this->pString = new char[strlen(str.pString)+1];
    strcpy(this->pString, str.pString);
    this->m_Size = strlen(str.pString);
}

char& MyString::operator[](int index){
    return this->pString[index];
}

MyString& MyString::operator=(char* str){
    if(this->pString != nullptr){
        delete[] this->pString;
        this->pString = nullptr;
    }
    this->pString = new char[strlen(str)+1];
    strcpy(this->pString, str);
    this->m_Size = strlen(str);
    return *this;
}

MyString& MyString::operator=(const MyString &str)
{
    if(this->pString != nullptr){
        delete[] this->pString;
        this->pString = nullptr;
    }
    this->pString = new char[strlen(str.pString)+1];
    strcpy(this->pString, str.pString);
    this->m_Size = str.m_Size;
    return *this;
}

MyString MyString::operator+(char* str){
    int newSize = this->m_Size + strlen(str) + 1;
    char* tmp = new char[newSize];
    memset(tmp, 0, newSize);
    strcat(tmp, this->pString);
    strcat(tmp, str);
    MyString newStr(tmp);
    delete[] tmp;
    return newStr;
}

MyString MyString::operator+(const MyString& str){
    int newSize = this->m_Size + str.m_Size + 1;
    char* tmp = new char[newSize];
    memset(tmp, 0, newSize);
    strcat(tmp, this->pString);
    strcat(tmp, str.pString);
    MyString newStr(tmp);
    delete[] tmp;
    return newStr;
}

bool MyString::operator==(char *str){
    return strcmp(this->pString, str) == 0;
}

bool MyString::operator==(const MyString &str){
    return strcmp(this->pString, str.pString) == 0;
}

MyString::~MyString(){
    if(this->pString != nullptr){
        delete[] this->pString;
        this->pString = nullptr;
    }
}
