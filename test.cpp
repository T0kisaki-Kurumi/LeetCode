#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long MOD = 1e9+7;
int l,r;
long long res = 0;

inline void dfs(long long sum, vector<int>& num, int index){
    if(sum > r) return;
    if(index == num.size()){
        if(l<=sum && sum<=r){
            cout<<sum<<endl;
            res += sum;
            res %= MOD;
        }
        return;
    }
    dfs(sum, num, index+1);
    dfs(sum+num[index], num, index+1);
}

int main(){
    int n;
    cin>>n>>l>>r;
    vector<int> num(n);
    for(int i=0; i<n; ++i) cin>>num[i];
    sort(num.begin(), num.end());
    dfs(0, num, 0);
    cout<<res<<endl;

    system("pause");
    return 0;
}