#include <iostream>
#include <queue>
using namespace std;

void test1(){
    queue<int> q;
    q.push(1);
    q.push(2);
    cout<<q.front()<<" "<<q.back()<<endl;
    cout<<q.size()<<endl;
    q.pop();
    q.pop();
    cout<<q.empty()<<endl;

}

int main(){
    test1();

    system("pause");
    return 0;
}