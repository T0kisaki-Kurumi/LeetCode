// 130. 被围绕的区域
// 给你一个 m x n 的矩阵 board ，由若干字符 'X' 和 'O' ，找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。
 

// 示例 1：
// 输入：board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
// 输出：[["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
// 解释：被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 任何不在边界上，或不与边界上的 'O' 相连的 'O' 最终都会被填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。

// 示例 2：
// 输入：board = [["X"]]
// 输出：[["X"]]

// 提示：

// m == board.length
// n == board[i].length
// 1 <= m, n <= 200
// board[i][j] 为 'X' 或 'O'

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int row = 0;
    int col = 0;

    void dfs(vector<vector<char>>& board, int x, int y){
        // cout<<x<<" "<<y<<endl;
        if(x<0 || x>=row || y<0 || y>=col) return;
        if(board[x][y] == 'X' || board[x][y] == 'A') return;
        board[x][y] = 'A';
        dfs(board, x+1, y);
        dfs(board, x-1, y);
        dfs(board, x, y+1);
        dfs(board, x, y-1);
    }

    void solve(vector<vector<char>>& board) {
        row = board.size();
        col = board[0].size();
        int res = 0;
        for(int i=0; i<row; ++i){
            dfs(board, i, 0);
            dfs(board, i, col-1);
        }
        for(int j=0; j<col; ++j){
            dfs(board, 0, j);
            dfs(board, row-1, j);
        }
        for(int i=0; i<row; ++i){
            for(int j=0; j<col; ++j){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                else if(board[i][j] == 'A'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};

int main(){
    // vector<vector<char>> graph{
    //     {'X','X','X','X'},
    //     {'X','X','X','X'},
    //     {'X','X','X','X'},
    //     {'X','O','X','X'}
    // };
    vector<vector<char>> graph{
        {'O','O'},
        {'O','O'}
    };
    Solution sol;
    sol.solve(graph);
    for(auto i: graph){
        for(auto j: i){
            cout<<j<<" ";
        }
        cout<<'\n';
    }
    system("pause");
    return 0;
}