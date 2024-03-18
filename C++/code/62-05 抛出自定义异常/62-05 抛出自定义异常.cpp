#include <iostream>
using namespace std;

class MyException{
public:
    void printError(){
        cout<<"自定义异常类"<<endl;
    }
};

// C语言返回一个值表示发生异常，存在缺陷，因为存在正常情况也返回与异常相同的值
// C++把异常和正常返回值分离，异常用throw，正常返回用return
int myDevide(int a, int b){
    if(b == 0){
        // throw -1;
        // throw 3.14;
        // throw "222";
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