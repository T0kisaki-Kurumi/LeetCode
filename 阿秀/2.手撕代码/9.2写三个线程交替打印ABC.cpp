#include <iostream>
#include <mutex>
#include <condition_variable>
#include <thread>

using namespace std;

int flag = 0;
mutex mtx;
condition_variable cv;

int main(){
    thread t1([&]{
        for(int i=0; i<10; ++i){
            unique_lock<mutex> ulock(mtx);
            cv.wait(ulock, [&]{return flag==0;});
            cout<<'A'<<endl;
            flag = 1;
            this_thread::sleep_for(chrono::seconds(1));
            cv.notify_all();
        }
    });
    thread t2([&]{
        for(int i=0; i<10; ++i){
            unique_lock<mutex> ulock(mtx);
            cv.wait(ulock, [&]{return flag==1;});
            cout<<'B'<<endl;
            flag = 2;
            this_thread::sleep_for(chrono::seconds(1));
            cv.notify_all();
        }
    });
    thread t3([&]{
        for(int i=0; i<10; ++i){
            unique_lock<mutex> ulock(mtx);
            cv.wait(ulock, [&]{return flag==2;});
            cout<<'C'<<endl;
            flag = 0;
            this_thread::sleep_for(chrono::seconds(1));
            cv.notify_all();
        }
    });

    t1.join();
    t2.join();
    t3.join();

    system("pause");
    return 0;
}