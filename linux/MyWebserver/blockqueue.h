#ifndef BLOCKQUEUE_H
#define BLOCKQUEUE_H

#include <pthread.h>
#include <exception>
#include <sys/time.h>
#include <list>

template<class T>
class BlockQueue{
private:
    std::list<T> m_blockqueue;  //链表实现队列
    pthread_mutex_t m_mutex;    //锁
    pthread_cond_t m_cond;      //条件变量
    int m_max_size;             //最大长度（容量）
    int m_size;                 //当前长度

public:
    BlockQueue(int max_size = 1000);
    ~BlockQueue();

    // 入队列
    bool push(const T& item);

    // 出队列
    bool pop(T& item);

    // 设置等待时长的出队列
    bool pop(T& item, int seconds);

    // 判断队列是否已满
    bool full();
};

template<class T>
BlockQueue<T>::BlockQueue(int max_size){
    if(max_size < 0){
        exit(-1);
    }
    m_max_size = max_size;
    m_size = 0;

    // 初始化锁和条件变量
    if(pthread_mutex_init(&m_mutex, nullptr)){
        throw std::exception();
    }
    if(pthread_cond_init(&m_cond, nullptr)){
        throw std::exception();
    }
}

template<class T>
BlockQueue<T>::~BlockQueue(){
    pthread_mutex_destroy(&m_mutex);
    pthread_cond_destroy(&m_cond);
}

template<class T>
bool BlockQueue<T>::push(const T& item){
    pthread_mutex_lock(&m_mutex);
    if(m_size >= m_max_size){
        pthread_cond_signal(&m_cond);
        pthread_mutex_unlock(&m_mutex);
        return false; //push失败
    }

    m_blockqueue.push_back(item);
    ++m_size;
    pthread_cond_signal(&m_cond);
    pthread_mutex_unlock(&m_mutex);
    return true;
}

template<class T>
bool BlockQueue<T>::pop(T& item){
    pthread_mutex_lock(&m_mutex);
    // 使用while避免虚假唤醒
    while(m_size <= 0){
        if(pthread_cond_wait(&m_cond, &m_mutex) != 0){
            pthread_mutex_unlock(&m_mutex);
            return false;
        }
    }
    item = m_blockqueue.front();
    m_blockqueue.pop_front();
    --m_size;
    pthread_mutex_unlock(&m_mutex);
    return true;
}

template<class T>
bool BlockQueue<T>::pop(T& item, int seconds){
    timeval now;
    timespec t;
    gettimeofday(&now, nullptr);
    t.tv_sec = now.tv_sec + seconds;
    t.tv_nsec = now.tv_usec * 1000;  // now中是纳秒，t中是微秒

    pthread_mutex_lock(&m_mutex);
    while(m_size <= 0){
        if(pthread_cond_timedwait(&m_cond, &m_mutex, &t) != 0){
            pthread_mutex_unlock(&m_mutex);
            return false;
        }
    }

    item = m_blockqueue.front();
    m_blockqueue.pop_front();
    --m_size;
    pthread_mutex_unlock(&m_mutex);
    return true;
}

template<class T>
bool BlockQueue<T>::full(){
    return m_size >= m_max_size;
}

#endif