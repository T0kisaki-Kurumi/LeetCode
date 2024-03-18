#include "MyArray.h"

MyArray::MyArray(){
    cout<<"调用默认构造函数"<<endl;
    this->m_Capacity = 100;
    this->m_Size = 0;
    this->pAddress = new int[this->m_Capacity];
}

MyArray::MyArray(int capacity){
    cout<<"调用有参构造函数"<<endl;
    this->m_Capacity = capacity;
    this->m_Size = 0;
    this->pAddress = new int[this->m_Capacity];
}

MyArray::MyArray(const MyArray &arr){
    cout<<"调用拷贝构造函数"<<endl;
    // this->m_Size = arr.getSize();   // 不能这样写，因为arr是一个常对象，只能调用常函数
    this->m_Size = arr.m_Size; // 拷贝构造函数中，由于两者类型相同，可以直接调用私有成员
    this->m_Capacity = arr.m_Capacity;

    // this->pAddress = arr.pAddress;  // 不能这样写，否则就变成浅拷贝了，没有产生新的对象
    this->pAddress = new int[this->m_Capacity];

    // 不要忘记数组中的元素也要拷贝
    for(int i=0; i<arr.m_Size; ++i){
        this->pAddress[i] = arr.pAddress[i];
    }
}

void MyArray::setData(int pos, int val){
    this->pAddress[pos] = val;
}

int MyArray::getData(int pos){
    return this->pAddress[pos];
}

void MyArray::pushBack(int val){
    this->pAddress[this->m_Size] = val;
    ++this->m_Size;
    // 不用处理m_Size超出m_Capacity的情况，模拟真实的数组越界（程序直接崩，其他函数情况相同）
}

int MyArray::getSize(){
    return this->m_Size;
}

int MyArray::getCapacity(){
    return this->m_Capacity;
}

int& MyArray::operator[](int index){
    return this->pAddress[index];
}

MyArray::~MyArray(){
    cout<<"调用析构函数"<<endl;
    if(this->pAddress != nullptr){
        delete[] this->pAddress; // 释放数组空间
        this->pAddress = nullptr; // 防止野指针
    }
}