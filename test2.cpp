#include <vector>
#include <iostream>
#include <queue>

using namespace std;


class cmp{
public:
  bool operator()(pair<int,int>& a, pair<int,int>& b){
      if(a.second == b.second){
        return a.first > b.first;
      }
      return a.second > b.second;
  }
};

int main()
{
    int n; //节点总数
    cin>>n;
    int delay[n][n];
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cin>>delay[i][j];
        }
    }
    int remain[n];
    for(int i=0; i<n; ++i) cin>>remain[i];
    int node; // 发生故障的节点
    cin>>node;
    int total;
    cin>>total; //需要迁移业务量
    //vector<int> v; //node距离从小到大
    vector<int> d(n, INT32_MAX);
    d[node] = 0;
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
    pq.push({0,node});
    int index = node;
    while(!pq.empty()){
        cout<<pq.top().second<<" "<<pq.top().first<<endl;
        int cur = pq.top().second;
        int dis = pq.top().first;
        pq.pop();
        
        if(cur != index){
            index = cur;
            cout<<cur<<" ";
            total -= remain[cur];
            if(total <=0) break;
        }
        
        if(dis > d[cur]) continue;
        for(int i=0; i<n; ++i){
            if(delay[cur][i] == -1) continue;
            int newdis = dis + delay[cur][i];
            if(newdis < d[i]){
                d[i] = newdis;
                pq.push({newdis, i});
            }
        }
    }
    system("pause");
    return 0;
}