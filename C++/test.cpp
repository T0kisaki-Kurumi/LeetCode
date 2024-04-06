#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include <deque>
#include <stack>
#include <queue>
using namespace std;

class A{
public:
    static int x;
};

int A::x = 1;
 
int main(){
    A a;
    cout<<a.x;

    system("pause");
    return 0;
}