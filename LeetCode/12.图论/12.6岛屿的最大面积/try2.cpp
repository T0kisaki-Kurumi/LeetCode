// 695. 岛屿的最大面积
// 给你一个大小为 m x n 的二进制矩阵 grid 。

// 岛屿 是由一些相邻的 1 (代表土地) 构成的组合，这里的「相邻」要求两个 1 必须在 水平或者竖直的四个方向上 相邻。你可以假设 grid 的四个边缘都被 0（代表水）包围着。

// 岛屿的面积是岛上值为 1 的单元格的数目。

// 计算并返回 grid 中最大的岛屿面积。如果没有岛屿，则返回面积为 0 。

// 示例 1：
// 输入：grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
// 输出：6
// 解释：答案不应该是 11 ，因为岛屿只能包含水平或垂直这四个方向上的 1 。

// 示例 2：
// 输入：grid = [[0,0,0,0,0,0,0,0]]
// 输出：0

// 提示：

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 50
// grid[i][j] 为 0 或 1

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int cur = 0;
    int row = 0;
    int col = 0;

    void dfs(vector<vector<int>>& grid, int x, int y){
        if(x<0 || x>=row || y<0 || y>=col) return;
        if(grid[x][y]==0) return;
        grid[x][y] = 0;
        ++cur;
        dfs(grid, x+1, y);
        dfs(grid, x-1, y);
        dfs(grid, x, y+1);
        dfs(grid, x, y-1);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();
        int res = 0;
        for(int i=0; i<row; ++i){
            for(int j=0; j<col; ++j){
                cur = 0;
                dfs(grid, i, j);
                res = max(res, cur);
            }
        }
        return res;
    }
};

int main(){
    vector<vector<int>> graph{
        {0,0,1,0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,1,1,0,1,0,0,0,0,0,0,0,0},
        {0,1,0,0,1,1,0,0,1,0,1,0,0},
        {0,1,0,0,1,1,0,0,1,1,1,0,0},
        {0,0,0,0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,1,1,1,0,0,0},
        {0,0,0,0,0,0,0,1,1,0,0,0,0}
    };
    Solution sol;
    int res = sol.maxAreaOfIsland(graph);
    cout<<res<<endl;
    system("pause");
    return 0;
}