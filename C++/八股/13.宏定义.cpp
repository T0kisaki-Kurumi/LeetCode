#include <iostream>
using namespace std;

#define MUL1(x,y) x*y
#define MUL2(x,y) (x)*(y)
#define STRING(x) #x

int main(){
    cout<<MUL1(1+2,3)<<endl;
    cout<<MUL2(1+2,3)<<endl;

    cout<<STRING(hello)<<endl;

    system("pause");
}