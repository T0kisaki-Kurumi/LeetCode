// 827. 最大人工岛
// 给你一个大小为 n x n 二进制矩阵 grid 。最多 只能将一格 0 变成 1 。

// 返回执行此操作后，grid 中最大的岛屿面积是多少？

// 岛屿 由一组上、下、左、右四个方向相连的 1 形成。

// 示例 1:
// 输入: grid = [[1, 0], [0, 1]]
// 输出: 3
// 解释: 将一格0变成1，最终连通两个小岛得到面积为 3 的岛屿。

// 示例 2:
// 输入: grid = [[1, 1], [1, 0]]
// 输出: 4
// 解释: 将一格0变成1，岛屿的面积扩大为 4。

// 示例 3:
// 输入: grid = [[1, 1], [1, 1]]
// 输出: 4
// 解释: 没有0可以让我们变成1，面积依然为 4。

// 提示：

// n == grid.length
// n == grid[i].length
// 1 <= n <= 500
// grid[i][j] 为 0 或 1

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void printVector(vector<vector<int>>& vec){
    for(auto i: vec){
        for(int j: i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

class Solution {
public:
    int row = 0;
    int col = 0;
    int curArea = 0;
    int curMark = 0;

    void dfs(vector<vector<int>>& grid, vector<vector<int>>& mark, int x, int y){
        if(x<0 || x>=row || y<0 || y>=col) return;
        if(grid[x][y]==0 || mark[x][y]!=0) return;
        mark[x][y] = curMark;
        ++curArea;
        dfs(grid, mark, x+1, y);
        dfs(grid, mark, x-1, y);
        dfs(grid, mark, x, y+1);
        dfs(grid, mark, x, y-1);
    }

    int largestIsland(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();
        int res = 0;
        bool isAllGrid = true;
        vector<vector<int>> mark(row, vector<int>(col,0));
        unordered_map<int, int> areaMap;
        areaMap[0] = 0;
        for(int i=0; i<row; ++i){
            for(int j=0; j<col; ++j){
                if(grid[i][j] == 0) isAllGrid = false;
                if(grid[i][j]!=0 && mark[i][j]==0){
                    ++curMark;
                    curArea = 0;
                    dfs(grid, mark, i, j);
                    areaMap[curMark] = curArea;
                }
            }
        }
        // printVector(mark);
        // for(int i=0; i<=5; ++i) cout<<areaMap[i]<<" ";
        // cout<<curMark;
        
        if(isAllGrid) return row*col;
        unordered_set<int> visited; //如果某个点周围有大于等于2个属于同一个岛的地区，避免重复计算
        int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        for(int i=0; i<row; ++i){
            for(int j=0; j<col; ++j){
                if(grid[i][j] == 0){ //对原本是海洋的地方填海
                    int area = 1;
                    visited.clear();
                    for(int d=0; d<4; ++d){
                        int x = i + dir[d][0];
                        int y = j + dir[d][1];
                        if(x<0 || x>=row || y<0 || y>=col) continue;
                        if(visited.find(mark[x][y]) != visited.end()) continue;
                        visited.insert(mark[x][y]);
                        area += areaMap[mark[x][y]];
                    }
                    res = max(res, area);
                }
            }
        }
        return res;
    }
};

int main(){
    vector<vector<int>> graph{
        {0,1,0,0,0,0,0,0},
        {1,1,1,0,0,0,1,1},
        {0,1,1,1,0,1,1,1},
        {0,0,0,0,1,0,0,0},
        {0,0,0,0,1,0,0,0},
        {0,0,1,0,0,0,0,0},
        {0,1,1,0,0,1,1,0}
    }; //15
    Solution sol;
    int res = sol.largestIsland(graph);
    cout<<res;
    system("pause");
    return 0;
}