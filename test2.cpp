#include <iostream>
#include <vector>
#include <memory>
#include <list>
#include <type_traits>
#include <map>
#include <stdexcept>
#include <unordered_map>
#include <algorithm>
#include <forward_list>
#include <cmath>
#include <queue>
#include <cstring>

using namespace std;

// long long mult[21];

int main(){
    // memset(mult, 0, sizeof(mult));
    // mult[1] = 1;
    // for(int i=2; i<21; ++i){
    //     mult[i] = mult[i-1]*i;
    // }
    // cout<<mult[20]<<endl;
    // cout<<LONG_LONG_MAX<<endl;
    int n;
    cin>>n;
    int next[n+1];
    for(int i=1; i<=n; ++i){
        cin>>next[i];
    }
    bool vis[n+1];
    memset(vis, false, sizeof(vis));

    long long res = 0;
    for(int i=1; i<=n; ++i){
        if(vis[i]) continue;
        int num = 0;
        int cur = i;
        while(!vis[next[cur]]){
            ++num;
            cur = next[cur];
            vis[cur] = true;
        }
        // cout<<mult[num]<<endl;
        // res += mult[num];
        res += num*num;
    }

    cout<<res<<endl;

	// system("pause");
    return 0;
}