// 题目描述
// 塔子哥需要多个业务节点之间选择最快的逃生节点集，并考虑每个节点的剩余业务容量。
// 业务节点之间的关系可以看作一个图。塔子哥有一个网络时延表，表示每个节点到其他节点的通信延迟，即塔子哥从某节点逃到另一节点所需要的时间;
// 还有一个剩余业务容量表，表示每个节点的剩余业务容量。
// 在一个节点故障时，需要选择一个或多个逃生节点，确保逃生路径的时延最小，并且逃生节点集各节点剩余容量的总和足够容纳故障节点的业务量，
// 当故障节点与多个节点最短距离相同，优先选择编号较小的节点容灾，如果逃生节点集中多个节点最短距离相同时按编号从小到大的顺序排列。

// 输入描述
// 第1行n表示业务节点数， 2<=n<=10000，节点编号从 0 开始，依次递增；

// 第2到1+n行表示业务节点间的网络时延矩阵表 delayMatrix， delayMatrix[i][j]表示节点 i 到节点 j 的通信时延;

// 1）如果节点 i 和节点 j 之间没有直接相连的边，则 delayMatrix[i][j] 为 -1，第i个节点和它自己也没有边，所以 delayMatrix[i][i] 也为 -1

// 2）节点间有边时延范围为 1<=delayMatrix[i][j]<=1000，矩阵元素间使用空格分割，另外输入保证 delayMatrix[i][j] = delayMatrix[j][i]

// 第2+n行表示各业务节点的剩余容量表 remainingCapacity，其中 remainingCapacity[i] 表示节点 i 的剩余业务容量，业务量的范围 1<=remainingCapacity[i]<=100，数组元素间使用空格分割；

// 第3+n行表示故障业务节点编号 faultyNode，表示发生故障的节点，取值范围为  0<=faultyNode<=n-1；

// 第4+n行表示受损业务节点需要迁移的业务量, 受损业务量的范围 (0,1000] 。

// 输出描述
// 返回符合条件的逃生路径节点编号列表，用空格分隔。当所有节点都不够故障节点业务容灾时候，输出所有容灾节点。

// 样例

// 输入
// 4
// -1 5 -1 8
// 5 -1 1 3
// -1 1 -1 4
// 8 3 4 -1
// 10 20 15 25
// 2
// 12

// 输出
// 1

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(vector<int>& a, vector<int>& b){
    if(a[0] == b[0]) return a[1] < b[1];
    return a[0] < b[0];
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> delay(n, vector<int>(n));
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            cin>>delay[i][j];
            if(delay[i][j] == -1) delay[i][j] = 1e9;
        }
    }
    vector<int> capacity(n);
    for(int i=0; i<n; ++i) cin>>capacity[i];
    int start, need;
    cin>>start>>need;
    
    vector<int> dis(n, 1e9);
    vector<bool> vis(n, false);

    dis[start] = 0;
    for(int i=0; i<n-1; ++i){  //执行n-1次，每次计算出到某个节点的最短距离
        int cur;  //记录当前未访问的且离已访问节点集合最近的一个节点的序号
        int curDis = 1e9;  //记录当前未访问的且离已访问节点集合最近的一个节点到已访问节点集合的距离
        for(int j=0; j<n; ++j){
            if(!vis[j] && dis[j]<curDis){
                cur = j;
                curDis = dis[j];
            }
        }
        for(int j=0; j<n; ++j){
            dis[j] = min(dis[j], dis[cur] + delay[cur][j]);  // 更新所有与新加入已访问节点集合的节点相邻的节点的距离
        }
        vis[cur] = true;
    }
    // for(int i=0; i<n; ++i){
    //     cout<<i<<" "<<dis[i]<<endl;
    // }
    vector<vector<int>> ans;
    for(int i=0; i<n; ++i){
        if(i == start) continue;
        ans.emplace_back(vector<int>{dis[i], i, capacity[i]});  //不太确定排序规则
    }
    sort(ans.begin(), ans.end(), cmp);
    vector<int> res;
    int curCap = 0;
    for(vector<int>& v: ans){
        res.emplace_back(v[1]);
        curCap += v[2];
        if(curCap > need) break;
    }
    int len = res.size();
    for(int i=0; i<len; ++i){
        cout<<res[i]<<" \n"[i == len-1];
    }

    system("pause");
    return 0;
}