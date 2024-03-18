#include <iostream>
using namespace std;

class BaseException{
public:
    virtual void printError() = 0;
};

class NullPtrException: public BaseException{
public:
    void printError(){
        cout<<"空指针异常"<<endl;
    }
};

class OutOfRangeException: public BaseException{

public:
    void printError(){
        cout<<"越界异常"<<endl;
    }
};

void doWork(){
    // throw NullPtrException();
    throw OutOfRangeException();
}

void test1(){
    try{
        doWork();
    }
    catch(BaseException& e){
        e.printError();
    }
}
 
int main(){
    test1();

    system("pause");
    return 0;
}