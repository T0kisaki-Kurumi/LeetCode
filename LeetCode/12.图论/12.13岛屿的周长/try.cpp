// 463. 岛屿的周长
// 给定一个 row x col 的二维网格地图 grid ，其中：grid[i][j] = 1 表示陆地， grid[i][j] = 0 表示水域。

// 网格中的格子 水平和垂直 方向相连（对角线方向不相连）。整个网格被水完全包围，但其中恰好有一个岛屿（或者说，一个或多个表示陆地的格子相连组成的岛屿）。

// 岛屿中没有“湖”（“湖” 指水域在岛屿内部且不和岛屿周围的水相连）。格子是边长为 1 的正方形。网格为长方形，且宽度和高度均不超过 100 。计算这个岛屿的周长。

// 示例 1：
// 输入：grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
// 输出：16
// 解释：它的周长是上面图片中的 16 个黄色的边

// 示例 2：
// 输入：grid = [[1]]
// 输出：4

// 示例 3：
// 输入：grid = [[1,0]]
// 输出：4

// 提示：

// row == grid.length
// col == grid[i].length
// 1 <= row, col <= 100
// grid[i][j] 为 0 或 1

#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

class Solution {
public:
    int row = 0;
    int col = 0;

    int check(vector<vector<int>>& grid, int x, int y){
        if(x<0 || x>=row || y<0 || y>=col || grid[x][y]==0) return 1;
        return 0;
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();
        int res = 0;
        for(int i=0; i<row; ++i){
            for(int j=0; j<col; ++j){
                if(grid[i][j] == 1){
                    // cout<<check(grid, i+1, j)<<" ";
                    // cout<<check(grid, i-1, j)<<" ";
                    // cout<<check(grid, i, j+1)<<" ";
                    // cout<<check(grid, i, j-1)<<" "<<endl;
                    res += (check(grid, i+1, j) + check(grid, i-1, j) + check(grid, i, j+1) + check(grid, i, j-1));
                }
            }
        }
        return res;
    }
};

int main(){
    // vector<vector<int>> grid{
    //     {0,1,0,0},
    //     {1,1,1,0},
    //     {0,1,0,0},
    //     {1,1,0,0}
    // };
    vector<vector<int>> grid{
        {1,1}
    };
    Solution sol;
    int res = sol.islandPerimeter(grid);
    cout<<res<<endl;
    system("pause");
    return 0;
}