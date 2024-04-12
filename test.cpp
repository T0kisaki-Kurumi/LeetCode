#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main(){
<<<<<<< HEAD
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
=======
<<<<<<< HEAD
    char *s = "hello world";
    // s[1] = 'H'; 
    cout<<sizeof(s)<<endl;
=======
    int n,k;
    cin>>n>>k;
    int minc = INT_MAX;  //最少人数
    long long mint = INT_MIN;  //最少人数的步骤的时间
    int minIndex; //最少人数的下标
    int c[k];
    long long t[k];
    for(int i=0; i<k; ++i){
        cin>>c[i]>>t[i];
        if(c[i] < minc || (c[i]==minc && t[i]>mint)){
            minc = c[i];
            mint = t[i];
            minIndex = i;
>>>>>>> f14b7e25eb794b3e7e0136913d25087d757fe818
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
<<<<<<< HEAD
    system("pause");
=======
    int num;
    if(n % minc) num = n/minc + 1;
    else num = n/minc;
    
    long long sum = 0;
    for(int i=0; i<minIndex; ++i) sum += t[i];
    sum += num*t[minIndex];
    for(int i=minIndex+1; i<k; ++i) sum +=t[i];
    cout<<sum<<endl;
>>>>>>> 041c1bf7f8094b948cc22e1f8820c31854d04aeb

	// system("pause");
>>>>>>> f14b7e25eb794b3e7e0136913d25087d757fe818
    return 0;
}