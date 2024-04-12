#include <iostream>
#include <thread> //包含std::thread类以及std::this_thread命名空间。管理线程的函数和类在该头文件中有声明；
#include <mutex> //包含了与互斥量相关的类以及其他类型的函数；
#include <condition_variable> //包含与条件变量相关的类，包括std::condition_variable和std::condition_variable_any
#include <atomic> //包含std::atomic和std::atomic_flag类，以及一套C风格的原子类型和与C兼容的原子操作的函数；
#include <future> //包含两个Provider类（std::promise和std::package_task）和两个Future类（std::future和std::shared_future）以及相关的类型和函数；

using namespace std;

thread_local int i;


void func(int x){
    i = x;
    ++i;
    // this_thread::sleep_for(chrono::seconds(1));
    cout<<this_thread::get_id()<<" : "<<i<<endl;
}

int main(){
    i = 9;
    thread t1(func, 1);
    thread t2(func, 2);
    thread t3(func, 3);
    cout<<this_thread::get_id()<<" : "<<i<<endl;

    t1.join();
    t2.join();
    t3.join();

    system("pause");
    return 0;
}