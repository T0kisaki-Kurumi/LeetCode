#include <iostream>
#include <thread> //包含std::thread类以及std::this_thread命名空间。管理线程的函数和类在该头文件中有声明；
#include <mutex> //包含了与互斥量相关的类以及其他类型的函数；
#include <condition_variable> //包含与条件变量相关的类，包括std::condition_variable和std::condition_variable_any
#include <atomic> //包含std::atomic和std::atomic_flag类，以及一套C风格的原子类型和与C兼容的原子操作的函数；
#include <future> //包含两个Provider类（std::promise和std::package_task）和两个Future类（std::future和std::shared_future）以及相关的类型和函数；
#include <vector>

using namespace std;

// notify_one 和 notify_all
void test1(){
    condition_variable cv;
    mutex mtx;
    thread t1([&]{
        unique_lock<mutex> ulock(mtx);
        cv.wait(ulock);
        cout<<"t1 is awake"<<endl;
    });
    thread t2([&]{
        unique_lock<mutex> ulock(mtx);
        cv.wait(ulock);
        cout<<"t2 is awake"<<endl;
    });
    thread t3([&]{
        unique_lock<mutex> ulock(mtx);
        cv.wait(ulock);
        cout<<"t3 is awake"<<endl;
    });

    int x;
    while(cin>>x){
        if(x == 1) cv.notify_one();
        else if(x == 0) cv.notify_all();
    }
}

// wait等待某一条件
void test2(){
    condition_variable cv;
    mutex mtx;
    int x;
    thread t1([&]{
        unique_lock<mutex> ulock(mtx);
        cv.wait(ulock, [&]{return x==1;});
        cout<<"t1 is awake"<<endl;
    });
    thread t2([&]{
        unique_lock<mutex> ulock(mtx);
        cv.wait(ulock, [&]{return x==2;});
        cout<<"t2 is awake"<<endl;
    });
    thread t3([&]{
        unique_lock<mutex> ulock(mtx);
        cv.wait(ulock, [&]{return x==3;});
        cout<<"t3 is awake"<<endl;
    });

    while(cin>>x){
        cv.notify_all();  //这里如果用notify_one会只唤醒其中一个，如果数字不是想要的就会导致没反应。应该用notify_all
    }
}

int main(){
    // test1();
    test2();

    system("pause");
    return 0;
}