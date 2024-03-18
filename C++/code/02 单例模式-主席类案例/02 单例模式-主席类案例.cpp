#include <iostream>
using namespace std;

class ChairMan{
public:
    // static ChairMan * getInstance(){
    //     return singleMan;
    // }
    static ChairMan * getInstance();

private:
    ChairMan(){
        cout<<"调用默认构造函数"<<endl;
    }

    ChairMan(const ChairMan & c){
        cout<<"调用拷贝构造函数"<<endl;
    }

    static ChairMan * singleMan;
};

ChairMan * ChairMan::getInstance(){
    return singleMan;
}

ChairMan * ChairMan::singleMan = new ChairMan();


int main(){
    // ChairMan c1 = new ChairMan();
    ChairMan * c1 = ChairMan::getInstance();
    ChairMan * c2 = ChairMan::getInstance();
    cout<<(c1==c2 ? "c1==c2" : "c1!=c2")<<endl;

    // // 拷贝构造
    // ChairMan * c3 = new ChairMan(*c1);
    // cout<<(c1==c3 ? "c1==c3" : "c1!=c3")<<endl;

    system("pause");
    return 0;
}