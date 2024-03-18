# pragma once
# include <iostream>
using namespace std;

class MyArray{
public:
    // 无参构造函数
    MyArray();

    // 有参构造函数，使用explicit防止隐式类型转换。capacity为用户指定容量大小初始化
    explicit MyArray(int capacity);

    // 拷贝构造函数
    MyArray(const MyArray & arr);

    // 根据位置添加元素
    void setData(int pos, int val);

    // 获得指定位置的元素
    int getData(int pos);

    // 在尾部插入一个元素
    void pushBack(int val);

    // 获得当前数组长度
    int getSize();

    // 获得数组容量
    int getCapacity();

    // 析构函数
    ~MyArray();

private:
    int m_Capacity; // 数组可容纳的元素个数
    int m_Size; // 数组当前的元素个数
    int *pAddress; // 指向存储数据的空间的指针
};