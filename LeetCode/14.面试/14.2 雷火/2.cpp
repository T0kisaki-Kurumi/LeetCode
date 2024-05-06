#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Miss{
    int value;
    int limit;

    Miss(int val, int limit): value(val), limit(limit){};
};

class cmp{
public:
    bool operator()(Miss& a, Miss& b){
        if(a.value == b.value) return a.limit>b.limit;
        return a.value<b.value;
    }
};

// vector<long long> num(100001);

int main() {
    // int n,m; //n个任务 m天时间
    // cin>>n>>m;
    // // long long num[m];  //每天的减负券个数
    // // memset(num, 0, sizeof(num));
    // vector<long long> num(m+10, 0);
    // int used = 0; //已使用的减负券个数
    // priority_queue<Miss, vector<Miss>, cmp> pq;
    // int value, limit;
    // int c;
    // for(int i=0; i<n; ++i){
    //     cin>>value>>limit;
    //     pq.push(Miss(value, limit));
    // }
    // // cin>>c;
    // // num[0] = c;
    // for(int i=1; i<=m;++i){
    //     cin>>c;
    //     num[i] = num[i-1] + c;
    // }
    // for(int i=m+1; i<num.size(); ++i) num[i]= num[m];
    // // for(int i=0; i<=m; ++i) cout<<num[i]<<" ";
    // int res = 0;
    // while(!pq.empty()){
    //     int curV = pq.top().value;
    //     int curL = pq.top().limit;
    //     pq.pop();
    //     if(num[curL]-used > 0){
    //         res += curV;
    //         ++used;
    //     }
    // }
    // cout<<res<<endl;

    cout<<INT_MAX<<endl;


    system("pause");


    return 0;
}
// 64 位输出请用 printf("%lld")