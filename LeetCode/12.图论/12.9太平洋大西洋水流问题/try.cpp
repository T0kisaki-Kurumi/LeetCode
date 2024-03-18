// 417. 太平洋大西洋水流问题
// 有一个 m × n 的矩形岛屿，与 太平洋 和 大西洋 相邻。 “太平洋” 处于大陆的左边界和上边界，而 “大西洋” 处于大陆的右边界和下边界。

// 这个岛被分割成一个由若干方形单元格组成的网格。给定一个 m x n 的整数矩阵 heights ， heights[r][c] 表示坐标 (r, c) 上单元格 高于海平面的高度 。

// 岛上雨水较多，如果相邻单元格的高度 小于或等于 当前单元格的高度，雨水可以直接向北、南、东、西流向相邻单元格。水可以从海洋附近的任何单元格流入海洋。

// 返回网格坐标 result 的 2D 列表 ，其中 result[i] = [ri, ci] 表示雨水从单元格 (ri, ci) 流动 既可流向太平洋也可流向大西洋 。

// 示例 1：
// 输入: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
// 输出: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]

// 示例 2：
// 输入: heights = [[2,1],[1,2]]
// 输出: [[0,0],[0,1],[1,0],[1,1]]

// 提示：

// m == heights.length
// n == heights[r].length
// 1 <= m, n <= 200
// 0 <= heights[r][c] <= 105

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int row = 0;
    int col = 0;

    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int x, int y, int pre){
        if(x<0 || x>=row || y<0 || y>=col) return;
        if(visited[x][y]) return;
        if(heights[x][y] < pre) return;
        visited[x][y] = true;
        dfs(heights, visited, x+1, y, heights[x][y]);
        dfs(heights, visited, x-1, y, heights[x][y]);
        dfs(heights, visited, x, y+1, heights[x][y]);
        dfs(heights, visited, x, y-1, heights[x][y]);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        row = heights.size();
        col = heights[0].size();
        vector<vector<int>> res;
        vector<vector<bool>> visitedPac(row, vector<bool>(col, false));
        vector<vector<bool>> visitedAtl(visitedPac);
        for(int i=0; i<row; ++i){
            dfs(heights, visitedPac, i, 0, -1);
            dfs(heights, visitedAtl, i, col-1, -1);
        }
        for(int j=0; j<col; ++j){
            dfs(heights, visitedPac, 0, j, -1);
            dfs(heights, visitedAtl, row-1, j, -1);
        }
        for(int i=0; i<row; ++i){
            for(int j=0; j<col; ++j){
                if(visitedPac[i][j] && visitedAtl[i][j]){
                    res.emplace_back(vector<int>{i,j});
                }
            }
        }
        return res;
    }
};

int main(){
    vector<vector<int>> graph{
        {1,2,2,3,5},
        {3,2,3,4,4},
        {2,4,5,3,1},
        {6,7,1,4,5},
        {5,1,1,2,4}
    };
    Solution sol;
    vector<vector<int>> res = sol.pacificAtlantic(graph);
    for(auto i: res){
        for(auto j: i){
            cout<<j<<" ";
        }
        cout<<'\n';
    }
    system("pause");
    return 0;
}