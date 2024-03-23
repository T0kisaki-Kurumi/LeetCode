#include <iostream>
using namespace std;

template<class T>
int cmp(T& a, T& b){
    if(a>b) return 1;
    else if(a==b) return 0;
    else return -1;
}

int main(){
    int a = 1, b = 2;
    double c = 3.3, d = -1.1;
    cout<<cmp(a,b)<<endl;
    cout<<cmp(c,d)<<endl;

    system("pause");
    return 0;
}