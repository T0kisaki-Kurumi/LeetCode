#include <iostream>
using namespace std;

class Animal{
public:
    int m_Age;
};

class Sheep: virtual public Animal{
public:

};

class Tuo: virtual public Animal{
public:

};

class SheepTuo: public Sheep, public Tuo{
public:

};

void test1(){
    SheepTuo st;
    // cout<<st.m_Age<<endl;

    int offsetSheep = *(int*)((int*)*(int*)&st + 1);  // 在64位系统上疑似为long long
    cout<<"通过Sheep的虚基类表找到的偏移量："<<offsetSheep<<endl;
    int offsetTuo = *(int*)((int*)*((int*)&st + 1) + 1);
    cout<<"通过Tuo的虚基类表找到的偏移量："<<offsetTuo<<endl;

    Animal* a = (Animal*)((char*)&st + offsetSheep);
    cout<<"age = "<< a->m_Age;

    // SheepTuo *st = new SheepTuo;
    // int offsetSheep = *((long long*)*(long long*)st + 1);
    // cout<<"通过Sheep的虚基类表找到的偏移量："<<offsetSheep<<endl;
}

int main(){
    test1();

    system("pause");
    return 0;
}