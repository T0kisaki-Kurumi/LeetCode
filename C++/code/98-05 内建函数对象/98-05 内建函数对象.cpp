#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;


void test1(){
    int a = negate<int>()(10);
    negate<int> n;
    int b = n(20);
    cout<<a<<" "<<b<<endl;
}

void test2(){
    vector<int> v{1,2,3,4,5};
    sort(v.begin(), v.end(), greater<int>());
    for_each(v.begin(), v.end(), [](int val){cout<<val<<" ";});
    cout<<endl;
}

int main(){
    // test1();
    test2();

    system("pause");
    return 0;
}