#pragma once
#include <iostream>
using namespace std;

template<class T>
class MyArray{
public:
    explicit MyArray(int capacity){
        this->m_Capacity = capacity;
        this->m_Size = 0;
        pAddress = new T[capacity];
    }

    MyArray(const MyArray& arr){
        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;
        this->pAddress = new T[this->m_Capacity];
        for(int i=0; i<m_Size; ++i){
            this->pAddress[i] = arr.pAddress[i];
        }
    }

    MyArray& operator=(const MyArray& arr){
        if(this->pAddress != nullptr){
            delete[] this->pAddress;
            this->pAddress = nullptr;
        }
        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;
        this->pAddress = new T[this->m_Capacity];
        for(int i=0; i<m_Size; ++i){
            this->pAddress[i] = arr.pAddress[i];
        }
    }

    // []运算符重载
    T& operator[](int index){
        return this->pAddress[index];
    }

    // 尾插法
    void pushBack(const T& val){
        if(this->m_Size == this->m_Capacity){
            cout<<"超出容量，插入失败！"<<endl;
            return;
        }
        this->pAddress[this->m_Size] = val;
        this->m_Size++;
    }

    // 尾删法
    void popBack(){
        if(this->m_Size == 0){
            return;
        }
        this->m_Size--;
    }

    // 返回数组大小
    int getSize(){
        return this->m_Size;
    }

    ~MyArray(){
        if(this->pAddress != nullptr){
            delete[] this->pAddress;
            this->pAddress = nullptr;
        }
    }

private:
    T* pAddress;
    int m_Capacity;
    int m_Size;
};