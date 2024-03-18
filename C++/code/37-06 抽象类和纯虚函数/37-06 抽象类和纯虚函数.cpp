#include <iostream>
#include <string>
using namespace std;

// class Calculator{
// public:
//     int getResult(string op){
//         if(op == "+"){
//             return m_A + m_B;
//         }
//         else if(op == "-"){
//             return m_A - m_B;
//         }
//         else if(op == "*"){
//             return m_A * m_B;
//         }
//     }

//     int m_A;
//     int m_B;
// };

class AbStractCalculator{
public:
    // virtual int getResult(){
    //     return 0; //也可以什么都不写
    // }

    // 纯虚函数
    virtual int getResult() = 0;

    int m_A;
    int m_B;
};

int AbStractCalculator::getResult(){
    return 0;
}

class AddCalculator: public AbStractCalculator{
public:
    virtual int getResult(){
        return m_A + m_B;
    }
};

class SubCalculator: public AbStractCalculator{
public:
    virtual int getResult(){
        return m_A - m_B;
    }
};

class MultCalculator: public AbStractCalculator{
public:
    virtual int getResult(){
        return m_A * m_B;
    }
};

void test1() {
    AbStractCalculator* c = new AddCalculator;
    c->m_A = 10;
    c->m_B = 20;
    cout<<c->getResult()<<endl;
    delete c;

    c = new SubCalculator;
    c->m_A = 10;
    c->m_B = 20;
    cout<<c->getResult()<<endl;
    delete c;
    
    // AbStractCalculator a;
}

int main(){
    test1();

    system("pause");
    return 0;
}