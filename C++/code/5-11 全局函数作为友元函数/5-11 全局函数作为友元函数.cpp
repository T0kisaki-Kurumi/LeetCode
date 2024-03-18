#include <iostream>
#include <string>
using namespace std;

class Building{
    // 声明友元函数，使其可以访问私有成员
    friend void goodGay(Building & building);
    friend void hello(Building & building){cout<<"hello "<<building.m_Bedroom<<endl;}
public:
    string m_SittingRoom;

    Building(){
        this->m_SittingRoom = "客厅";
        this->m_Bedroom = "卧室";
    }

private:
    string m_Bedroom;

};

// 友元全局函数
void goodGay(Building & building){
    cout<<building.m_SittingRoom<<endl;
    cout<<building.m_Bedroom<<endl;
}

int main(){
    Building b;
    goodGay(b);
    hello(b);
    system("pause");
    return 0;
}