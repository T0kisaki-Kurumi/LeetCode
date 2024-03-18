#include <iostream>
using namespace std;

class MyException{
public:
    void printError(){
        cout<<"自定义异常类"<<endl;
    }
};

class Person{
public:
    Person(int x){
        this->x = x;
        cout<<"Person构造"<<x<<endl;
    }
    ~Person(){
        cout<<"Person析构"<<this->x<<endl;
    }
    int x;
};

int myDevide(int a, int b){
    if(b == 0){
        // throw -1;
        // throw 3.14;
        // throw "222";
        Person p1(1);
        Person p2(2);
        cout<<"11"<<endl;
        throw MyException();
    }
    return a/b;
}

void test1(){
    int a = 10;
    int b = 0;

    // cout<<myDevide(a,b)<<endl;

    try{
        int ret = myDevide(a,b);
    }
    catch(int){
        cout<<"捕获int类型的异常"<<endl;
    }
    catch(double){
        cout<<"捕获double类型的异常"<<endl;
    }
    catch(MyException){
        cout<<"捕获自定义类型的异常"<<endl;
    }
    catch(...){
        // 如果不想处理，可以继续往外抛出异常
        throw;

        cout<<"捕获其他类型的异常"<<endl;
    }

}
 
int main(){
    try{
        test1();
    }
    catch(...){
        cout<<"main中捕获了异常"<<endl;
    }

    system("pause");
    return 0;
}