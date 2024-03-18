#include <iostream>
#include <map>
using namespace std;

class MyPrint{
public:
    void operator()(int x){
        cout<<x<<endl;
        ++m_Count;
    }

    int m_Count = 0;
};

void test1(){
    MyPrint mp;
    mp(100);
    MyPrint()(200);
}

void test2(){
    MyPrint mp;
    mp(1);
    mp(2);
    mp(3);
    cout<<mp.m_Count<<endl;
}

void doWork(MyPrint mp, int num){
    mp(num);
}

void test3(){
    doWork(MyPrint(), 1);
}

int main(){
    // test1();
    // test2();
    test3();

    system("pause");
    return 0;
}