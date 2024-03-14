#include <pthread.h>

struct msg{
    struct msg* m_next;

};

struct msg* workq; //消息队列
pthread_cond_t qready = PTHREAD_COND_INITIALIZER;
pthread_mutex_t qlock = PTHREAD_MUTEX_INITIALIZER;

void process_msg(){
    struct msg* mp;
    for(;;){
        pthread_mutex_lock(&qlock);
        // 用while而不是if，循环判断条件，避免虚假唤醒（调用一次signal唤醒所有等待线程，但只有其中一个线程可以继续下去）
        while(NULL == workq){
            pthread_cond_wait(&qready, &qlock);
        }
        mp = workq;
        workq = mp->m_next;
        /* 不要在这个地方处理获取到的mq，会导致阻塞 */
        pthread_mutex_unlock(&qlock);
        /* 在这儿处理mq */
    }
}

void enqueue_msg(struct msg* mp){
    pthread_mutex_lock(&qlock);
    mp->m_next = workq;
    workq = mp;
    pthread_mutex_unlock(&qlock);
    pthread_cond_signal(&qready); //调用一次会唤醒所有的等待线程，但只有一个线程会处理
}