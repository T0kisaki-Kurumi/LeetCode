#include <iostream>
#include <stack>
using namespace std;

void test1(){
    stack<int> s1;
    s1.push(2);
    stack<int> s2(s1);
    cout<<s2.top()<<endl;
    cout<<s2.size()<<endl;
    s2.pop();
    cout<<s2.empty()<<endl;
}

int main(){
    test1();

    system("pause");
    return 0;
}