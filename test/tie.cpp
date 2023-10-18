#include <iostream>
#include <tuple>
#include <utility>
using namespace std;

int main(){
    int a=1;
    int b=2;
    tie(a,b) = pair<int, int>(b,a);
    cout<<a<<" "<<b;
    system("pause");
    return 0;
}