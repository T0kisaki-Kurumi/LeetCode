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

using namespace std;

class Solution {
public:
    void bfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y){
        int row = grid.size();
        int col = grid[0].size();
        queue<pair<int,int>> q;
        q.push({x,y});
        // visited[x][y] = true;
        while(!q.empty()){
            pair<int,int> cur = q.front();
            q.pop();
            int curx = cur.first;
            int cury = cur.second;
            if(curx<0 || curx>=row || cury<0 || cury>=col) continue;
            if(visited[curx][cury] || grid[curx][cury]=='0') continue;
            visited[curx][cury] = true;
            q.push({curx+1, cury});
            q.push({curx-1, cury});
            q.push({curx, cury+1});
            q.push({curx, cury-1});
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
                    // visited[i][j] = true;
                    bfs(grid, visited, i, j);
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