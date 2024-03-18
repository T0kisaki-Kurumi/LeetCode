// 200. 岛屿数量
// 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。

// 岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。

// 此外，你可以假设该网格的四条边均被水包围。

// 示例 1：
// 输入：grid = [
//   ["1","1","1","1","0"],
//   ["1","1","0","1","0"],
//   ["1","1","0","0","0"],
//   ["0","0","0","0","0"]
// ]
// 输出：1

// 示例 2：
// 输入：grid = [
//   ["1","1","0","0","0"],
//   ["1","1","0","0","0"],
//   ["0","0","1","0","0"],
//   ["0","0","0","1","1"]
// ]
// 输出：3

// 提示：

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 300
// grid[i][j] 的值为 '0' 或 '1'

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<vector<int>> dir{{0,1}, {1,0}, {0,-1}, {-1,0}};

    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y){
        for(auto d: dir){
            int nextx = x + d[0];
            int nexty = y + d[1];
            if(0<=nextx && nextx<grid.size() && 0<=nexty && nexty<grid[0].size() && !visited[nextx][nexty] && grid[nextx][nexty]=='1'){
                visited[nextx][nexty] = true;
                dfs(grid, visited, nextx, nexty);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int res = 0;
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        for(int i=0; i<row; ++i){
            for(int j=0; j<col; ++j){
                if(!visited[i][j] && grid[i][j]=='1'){
                    visited[i][j] = true;
                    dfs(grid, visited, i, j);
                    ++res;
                }
            }
        }
        return res;
    }
};

int main(){
    vector<vector<char>> graph{
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };
    Solution sol;
    int res = sol.numIslands(graph);
    cout<<res<<endl;
    system("pause");
    return 0;
}