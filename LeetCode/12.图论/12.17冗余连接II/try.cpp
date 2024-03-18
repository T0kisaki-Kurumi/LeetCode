// 685. 冗余连接 II
// 在本问题中，有根树指满足以下条件的 有向 图。该树只有一个根节点，所有其他节点都是该根节点的后继。该树除了根节点之外的每一个节点都有且只有一个父节点，而根节点没有父节点。

// 输入一个有向图，该图由一个有着 n 个节点（节点值不重复，从 1 到 n）的树及一条附加的有向边构成。附加的边包含在 1 到 n 中的两个不同顶点间，这条附加的边不属于树中已存在的边。

// 结果图是一个以边组成的二维数组 edges 。 每个元素是一对 [ui, vi]，用以表示 有向 图中连接顶点 ui 和顶点 vi 的边，其中 ui 是 vi 的一个父节点。

// 返回一条能删除的边，使得剩下的图是有 n 个节点的有根树。若有多个答案，返回最后出现在给定二维数组的答案。

// 示例 1：
// 输入：edges = [[1,2],[1,3],[2,3]]
// 输出：[2,3]

// 示例 2：
// 输入：edges = [[1,2],[2,3],[3,4],[4,1],[1,5]]
// 输出：[4,1]

// 提示：

// n == edges.length
// 3 <= n <= 1000
// edges[i].length == 2
// 1 <= ui, vi <= n

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void init(vector<int>& father){
        for(int i=0; i<father.size(); ++i){
            father[i] = i;
        }
    }

    int find(vector<int>& father, int u){
        return u==father[u] ? u : father[u]=find(father, father[u]);
    }

    bool isSame(vector<int>& father, int u, int v){
        u = find(father, u);
        v = find(father, v);
        return u == v;
    }

    void join(vector<int>& father, int u, int v){
        u = find(father, u);
        v = find(father, v);
        if(u == v) return;
        father[v] = u; //注意这边一定是v的父节点为u，因为edge中是第0个指向第1个
    }

    bool isTreeAfterRemove(vector<vector<int>>& edges, vector<int>& father, int deleteEdge){
        init(father);
        for(int i=0; i<edges.size(); ++i){
            if(i == deleteEdge) continue;
            if(isSame(father, edges[i][0], edges[i][1])) return false;
            join(father, edges[i][0], edges[i][1]);
        }
        return true;
    }

    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> father(n+1); //有几条边就有几个点，因为树中边比节点少一个，冗余一条边之后就相等，下标又是从1开始，所以+1
        vector<int> inDegree(n+1, 0);
        vector<int> deleteEdges; //记录入度为2的点的两条入边
        for(int i=0; i<n; ++i){
            ++inDegree[edges[i][1]];
        }
        bool isFirst = true;
        for(int i=n-1; i>=0; --i){ //一定要倒序遍历，因为要找到最后一个能删除的
            if(inDegree[edges[i][1]] == 2){
                if(isFirst){
                    if(isTreeAfterRemove(edges, father, i)) return edges[i];
                    else isFirst = false;
                }
                else return edges[i];
            }
        }
        init(father);
        for(int i=0; i<edges.size(); ++i){
            if(isSame(father, edges[i][0], edges[i][1])) return edges[i];
            join(father, edges[i][0], edges[i][1]);
        }
        return {};
    }
};

int main(){
    int n = 6;
    vector<vector<int>> edges{{1,2}, {2,3}, {3,4}, {4,1}, {1,5}};
    // vector<vector<int>> edges{{1,2}, {1,3}, {2,3}};
    Solution sol;
    vector<int> res = sol.findRedundantDirectedConnection(edges);
    for(auto i: res){
        cout<<i<<" ";
    }
    cout<<endl;
    system("pause");
    return 0;
}