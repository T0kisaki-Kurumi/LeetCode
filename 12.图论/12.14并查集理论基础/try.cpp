#include <iostream>
#include <vector>

using namespace std;

int n = 100;
vector<int> father(n);

// 初始化
void init(){
    for(int i=0; i<n; ++i){
        father[i] = i;
    }
}

// 寻根，同时实现路径压缩
int find(int u){
    return u == father[u] ? u : father[u] = find(father[u]);
}

// 判断两个节点是否有相同的根
bool isSame(int u, int v){
    u = find(u);
    v = find(v);
    return u == v;
}

// 将两个节点加入同一个集合
void join(int u, int v){
    u = find(u);
    v = find(v);
    if(u == v) return;
    father[v] = u;
}

int main(){
    init();
    // cout<<father[1]<<" "<<father[2]<<endl;
    cout<<isSame(1,2)<<endl;
    join(1,3);
    join(2,3);
    cout<<isSame(1,2)<<endl;
    system("pause");
    return 0;
}