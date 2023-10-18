#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> vec{1, 2, 3};
    cout<<typeid(vec).name()<<endl;
    cout<<typeid(vec.size()).name()<<endl;
    int a = 1;
    cout<<typeid(a).name()<<endl;
    unsigned long long b = 1;
    cout<<typeid(b).name()<<endl;
    system("pause");
    return 0;
}