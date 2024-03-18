#include <iostream>
#include <stdexcept> // 系统标准异常头文件
using namespace std;

class Person{
public:
    Person(int age){
        if(age<0 || age>150){
            // throw out_of_range("年龄必须在0-150之间");
            throw length_error("年龄必须在0-150之间");
        }
        this->m_Age = age;
    }

    int m_Age;
};

void test1(){
    try{
        Person p1(200);
    }
    // catch(out_of_range& e){
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