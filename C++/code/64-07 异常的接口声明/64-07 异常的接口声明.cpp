#include <iostream>
using namespace std;

void test1() throw(double){
    throw -1.5;
}

void test2() noexcept{
    throw -1.5;
}
 
int main(){
    try{
        test1();
        // test2();
    }
    catch(int){
        cout<<"捕获int类型异常"<<endl;
    }
    catch(double){
        cout<<"捕获double类型异常"<<endl;
    }

    system("pause");
    return 0;
}