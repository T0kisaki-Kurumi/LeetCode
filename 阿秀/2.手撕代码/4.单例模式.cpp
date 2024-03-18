#include <iostream> 
#include <pthread.h>

// 饿汉模式
class singleHungry{
public:
    static singleHungry* getInstance();

private:
    singleHungry(){};
    ~singleHungry(){};
    static singleHungry* p;
};

singleHungry* singleHungry::p = new singleHungry();

singleHungry* singleHungry::getInstance(){
    return p;
}

// 线程安全的懒汉模式
class singleLazy{
public:
    static singleLazy* getInstance();

private:
    singleLazy(){pthread_mutex_init(&mutex, nullptr);};
    ~singleLazy(){};
    static pthread_mutex_t mutex;
    static singleLazy* p;
};

singleLazy* singleLazy::p = nullptr;
pthread_mutex_t singleLazy::mutex;

singleLazy* singleLazy::getInstance(){
    if(nullptr == p){
        pthread_mutex_lock(&mutex);
        if(nullptr == p){
            p = new singleLazy();
        }
        pthread_mutex_unlock(&mutex);
    }
    return p;
}

// 基于C++11的线程安全的懒汉模式
class singleLazyC11{
public:
    static singleLazyC11* getInstance();

private:
    singleLazyC11(){};
    ~singleLazyC11(){};
};

singleLazyC11* singleLazyC11::getInstance(){
    // static singleLazyC11 p;
    // return &p;
    static singleLazyC11* p = new singleLazyC11();
    return p; 
}


int main(){
    singleHungry* s1 = singleHungry::getInstance();
    singleHungry* s2 = singleHungry::getInstance();
    std::cout<<(s1==s2)<<std::endl;

    singleLazy* s3 = singleLazy::getInstance();
    singleLazy* s4 = singleLazy::getInstance();
    std::cout<<(s3==s4)<<std::endl;

    singleLazyC11* s5 = singleLazyC11::getInstance();
    singleLazyC11* s6 = singleLazyC11::getInstance();
    std::cout<<(s5==s6)<<std::endl;

    system("pause");
    return 0;
}