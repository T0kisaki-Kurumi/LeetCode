#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

class C{
public:
    int x;
    int y;
    C(): x(0), y(0){}
    C(int x): x(x), y(0){}
    C(int x, int y): x(x), y(y){}
};

int main(){
    vector<C> vec;

    vec.push_back(1);
    vec.emplace_back(1);

    // vec.push_back(1,2); // 报错
    vec.emplace_back(1,2);

    for(auto i: vec){
        cout<<i.x<<" "<<i.y<<endl;
    }
    system("pause");
}