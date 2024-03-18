#include <iostream>
using namespace std;

class MyException{
public:
    MyException(){
        count++;
        cout<<"MyException构造"<<count<<endl;
    }
    MyException(const MyException& e){
        count++;
        cout<<"MyException拷贝构造"<<count<<endl;
    }

    ~MyException(){
        cout<<"MyException析构"<<count<<endl;
        count--;
    }

    static int count;
};

int MyException::count = 0;

void doWork1(){
    throw MyException();
}

void doWork2(){
    // MyException e;
    // throw &e;
    throw new MyException();
}

void test1(){
    try{
        doWork1();
    }
    // catch(MyException){
    //     cout<<"捕获MyException异常"<<endl;
    // }
    // catch(MyException e){
    //     cout<<"捕获MyException异常"<<endl;
    // }
    catch(MyException& e){
        cout<<"捕获MyException异常"<<endl;
    }
}

void test2(){
    try{
        doWork2();
    }
    catch(MyException* e){
        cout<<"捕获MyException异常"<<endl;
        delete e;
    }
}

int main(){
    test1();
    // test2();

    system("pause");
    return 0;
}