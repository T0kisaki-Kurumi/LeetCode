#include <iostream>
#include <stdexcept> // 系统标准异常头文件
#include <string>
using namespace std;

// 自己的异常类
class MyOutOfRangeException: public exception{
public:
    MyOutOfRangeException(const char* exceptInfo){
        // cout<<"char*"<<endl;
        this->m_ExceptInfo = string(exceptInfo);
    }
    MyOutOfRangeException(string exceptInfo){
        // cout<<"string"<<endl;
        this->m_ExceptInfo = exceptInfo;
    }

    virtual const char*
    what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT{
        return this->m_ExceptInfo.c_str();
    }

    string m_ExceptInfo;
};

class Person{
public:
    Person(int age){
        if(age<0 || age>150){
            // throw MyOutOfRangeException(string("年龄必须在0-150之间"));
            throw MyOutOfRangeException("年龄必须在0-150之间");
        }
        this->m_Age = age;
    }

    int m_Age;
};

void test1(){
    try{
        Person p1(200);
    }
    // catch(MyOutOfRangeException& e){
    //     cout<<e.what()<<endl;
    // }
    catch(exception& e){
        cout<<e.what()<<endl;
    }
}
 
int main(){
    test1();

    system("pause");
    return 0;
}