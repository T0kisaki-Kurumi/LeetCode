#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

unordered_set<long long> uset;

int main(){
    int q;
    cin>>q;
    while(q--){
        uset.clear();
        long long k,a,b,l,r;
        cin>>k>>a>>b>>l>>r;
        long long res = k;
        int count = 0;
        for(; res<=r; res*=a){
            if(uset.find(res) != uset.end()) continue;
            long long tmp = res;
            for(; tmp<=r; tmp*=b){
                if(l<=tmp){
                    if(uset.find(tmp)==uset.end()){
                        uset.insert(tmp);
                        ++count;
                    }
                }
            }
        }
        cout<<count<<endl;
    }

    system("pause");
    return 0;
}