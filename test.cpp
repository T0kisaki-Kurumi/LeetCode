#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main(){
    int N;
    cin>>N;
    while(N--){
        int m;
        cin>>m;
        long long res = 0;
        map<long long, long long> umap;
        for(int i=0; i<m; ++i){
            long long cur;
            cin>>cur;
            if(umap.find(cur) == umap.end()) umap[cur] = i;
        }
        // for(auto& p: umap){
        //     cout<<p.first<<" "<<p.second<<endl;
        // }
        auto it = umap.begin();
        ++it;
        res += it->second;
        ++it;
        auto slow = umap.begin();
        while(it != umap.end()){
            ++it;
            ++slow;
        }
        res += slow->second;
        cout<<res<<endl;
    }
    system("pause");
    return 0;
}