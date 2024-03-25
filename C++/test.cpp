#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include <deque>
#include <stack>
#include <queue>
using namespace std;

template<class T1, class T2>
void func(T1 x, T2 y){
    cout<<"普通"<<endl;
}

template<class T1>
void func<T1, float>(){
    cout<<x<<endl;
}
 
int main(){
    int a = 1;
    float b = 2.5;
    func(a, b);

    system("pause");
    return 0;
}