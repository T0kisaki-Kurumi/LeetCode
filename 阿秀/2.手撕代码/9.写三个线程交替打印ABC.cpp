#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
using namespace std;

mutex mtx;
condition_variable cv;
int flag = 0;
#define PRINT_MAX 10

void printA(){
    unique_lock<mutex> ulk(mtx);
    int count = 0;
    while(count < PRINT_MAX){
        while(flag != 0) cv.wait(ulk);
        cout<<"thread 1: A"<<endl;
        flag = 1;
        ++count;
        this_thread::sleep_for(chrono::milliseconds(1000));
        cv.notify_all();
    }
}

void printB(){
    unique_lock<mutex> ulk(mtx);
    int count = 0;
    while(count < PRINT_MAX){
        while(flag != 1) cv.wait(ulk);
        cout<<"thread 2: B"<<endl;
        flag = 2;
        ++count;
        this_thread::sleep_for(chrono::milliseconds(1000));
        cv.notify_all();
    }
}

void printC(){
    unique_lock<mutex> ulk(mtx);
    int count = 0;
    while(count < PRINT_MAX){
        while(flag != 2) cv.wait(ulk);
        cout<<"thread 3: C"<<endl;
        flag = 0;
        ++count;
        this_thread::sleep_for(chrono::milliseconds(1000));
        cv.notify_all();
    }
}

int main(){
    thread th1(printA);
    thread th2(printB);
    thread th3(printC);

    th1.join();
    th2.join();
    th3.join();

    system("pause");
    return 0;
}