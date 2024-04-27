#include <iostream>
#include <thread>
#include <windows.h>
#include <mutex>

using namespace std;

mutex mutex_A;
mutex mutex_B;

//线程函数 A
void func1(){
    printf("thread A waiting get ResourceA \n");
    mutex_A.lock();
    printf("thread A got ResourceA \n");
    
    this_thread::sleep_for(chrono::seconds(1));
    
    printf("thread A waiting get ResourceB \n");
    mutex_B.lock();
    printf("thread A got ResourceB \n");

    mutex_B.unlock();
    mutex_A.unlock();
}

//线程函数 B
void func2()
{
    printf("thread B waiting get ResourceB \n");
    mutex_B.lock();
    printf("thread B got ResourceB \n");
    
    this_thread::sleep_for(chrono::seconds(1));
    
    printf("thread B waiting get ResourceA \n");
    mutex_A.lock();
    printf("thread B got ResourceA \n");

    mutex_A.unlock();
    mutex_B.unlock();
}

int main(){
    
    //创建两个线程
    thread t1(func1);
    thread t2(func2);

    t1.join();
    t2.join();

	system("pause");
    return 0;
}