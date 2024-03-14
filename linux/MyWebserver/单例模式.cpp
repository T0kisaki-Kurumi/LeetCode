#include <stdio.h>
#include <pthread.h>

// 经典的线程安全懒汉模式
class singleLazy1{
private:
    static singleLazy1 *p;  //私有静态指针
    static pthread_mutex_t lock;  //静态锁
    singleLazy1(){
        pthread_mutex_init(&lock, NULL);
    }
    ~singleLazy1(){}

public:
    static singleLazy1* getInstance();
};

pthread_mutex_t singleLazy1::lock;
singleLazy1* singleLazy1::p = NULL;
singleLazy1* singleLazy1::getInstance(){
    if(NULL == p){
        pthread_mutex_lock(&lock);
        if(NULL == p){
            p = new singleLazy1();
        }
        pthread_mutex_unlock(&lock);
    }
    return p;
}

// 使用局部静态对象的线程安全懒汉模式
class singleLazy2{
private:
    singleLazy2();
    ~singleLazy2();

public:
    static singleLazy2* getInstance();
};

singleLazy2* singleLazy2::getInstance(){
    static singleLazy2 obj;
    return &obj;
}

// 饿汉模式
class singleHungry{
private:
    singleHungry();
    ~singleHungry();
    static singleHungry *p;

public:
    static singleHungry* getInstance();
};

singleHungry* singleHungry::p = new singleHungry();

singleHungry* singleHungry::getInstance(){
    return p;
}