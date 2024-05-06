#include <iostream>
using namespace std;

int main() {
    long long p,q,x;  //p老虎 q人类
    cin>>p,q,x;
    long long l=0, r=1e13;
    long long res = -1;
    long long mid;
    while(l <= r){
        mid = l+(r-l)/2;
        long long dayt = mid - p;
        long long dayp = mid - q;
        long long numf = 2*dayt + dayp;
        long long numw = 2*dayp + dayt;
        if(numf + 3*numw <= x){
            res = mid;
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    cout<<res;

    return 0;
}
// 64 位输出请用 printf("%lld")