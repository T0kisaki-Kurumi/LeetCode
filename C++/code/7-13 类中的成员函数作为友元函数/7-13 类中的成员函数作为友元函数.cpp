#include <iostream>
#include <string>
using namespace std;

class Building;

// 友元类
class GoodGay{
public:
    GoodGay();
    void visit();
    void visit2();
private:
    Building * building;
};

class Building{
    friend void GoodGay::visit();
public:
    string m_SittingRoom;
    Building();
private:
    string m_Bedroom;
};

// 类外实现
GoodGay::GoodGay(){
    this->building = new Building;
}

void GoodGay::visit(){
    cout<<this->building->m_SittingRoom<<endl;
    cout<<this->building->m_Bedroom<<endl;
}

void GoodGay::visit2(){
    cout<<this->building->m_SittingRoom<<endl;
    // cout<<this->building->m_Bedroom<<endl;
}

Building::Building(){
    this->m_SittingRoom = "客厅";
    this->m_Bedroom = "卧室";
}

int main(){
    GoodGay gg;
    gg.visit();
    gg.visit2();
    system("pause");
    return 0;
}