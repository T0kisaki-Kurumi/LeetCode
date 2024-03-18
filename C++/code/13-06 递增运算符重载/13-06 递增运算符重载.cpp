#include <iostream>
using namespace std;

class MyInt{
    friend ostream& operator<<(ostream& cout, const MyInt& a);
public:
    MyInt():m_Num(0){}

    MyInt& operator++(){
        ++this->m_Num;
        return *this;
    }

    MyInt operator++(int){
        MyInt tmp = *this;
        ++this->m_Num;
        return tmp;
    }

private:
    int m_Num;
};

ostream& operator<<(ostream& cout, const MyInt& a){
    cout<<a.m_Num;
    return cout;
}

void test0(){
    MyInt a;
    cout<<a<<endl;
    cout<<++a<<endl;
    cout<<a++<<endl;
    cout<<a<<endl;
}

int main(){
    test0();

    system("pause");
    return 0;
}