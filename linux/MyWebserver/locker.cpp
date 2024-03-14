#include "locker.h"
#include <exception>

Locker::Locker(){
    if(pthread_mutex_init(&m_mutex, NULL) != 0){
        throw std::exception();
    }
}

Locker::~Locker(){
    pthread_mutex_destroy(&m_mutex);
}

bool Locker::lock(){
    return pthread_mutex_lock(&m_mutex) == 0;
}

bool Locker::unlock(){
    return pthread_mutex_unlock(&m_mutex) == 0;
}

pthread_mutex_t* Locker::get(){
    return &m_mutex;
}