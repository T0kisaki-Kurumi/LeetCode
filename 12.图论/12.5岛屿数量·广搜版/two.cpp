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
#include <queue>
#include <cstring>

using namespace std;

class Solution {
public:
    int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    void bfs(vector<vector<char>>& grid, int x, int y, int row, int col, vector<vector<bool>>& visited){
        queue<pair<int, int>> q;
        q.push({x, y});
        visited[x][y] = true;
        pair<int, int> tmp;
        while(!q.empty()){
            tmp = q.front(); q.pop();
            int curx = tmp.first;
            int cury = tmp.second;
            for(int i=0; i<4; ++i){
                int nextx = curx + dir[i][0];
                int nexty = cury + dir[i][1];
                if(nextx>=0 && nextx<row && nexty>=0 && nexty<col && grid[nextx][nexty]=='1' && !visited[nextx][nexty]){
                    q.push({nextx, nexty});
                    visited[nextx][nexty] = true;  //一定要在这里改，不然可能会重复入队列
                }
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
                if(grid[i][j] == '1' && !visited[i][j]){
                    ++res;
                    bfs(grid, i, j, row, col, visited);
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