#include <iostream>
#include <vector>
using namespace std;

int count = 0;

int qux(int n){
    ++count;
    if(n<=0) return 0;
    else return qux(n-2)+qux(n-3)+1;
}

int main() {
    qux(qux(5));
    cout<<count<<endl;
    system("pause");
}
// 64 位输出请用 printf("%lld")