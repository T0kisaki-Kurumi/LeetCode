// 51. N 皇后
// 按照国际象棋的规则，皇后可以攻击与之处在同一行或同一列或同一斜线上的棋子。

// n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。

// 给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。

// 每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。

// 示例 1：
// 输入：n = 4
// 输出：[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
// 解释：如上图所示，4 皇后问题存在两个不同的解法。

// 示例 2：
// 输入：n = 1
// 输出：[["Q"]]

// 提示：

// 1 <= n <= 9

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    vector<vector<string>> res;
    vector<string> cur;
    bool isValid(int n, int row, int col){
        for(int i = row-1, j = col-1; i>=0 && j>=0; --i,--j){
            if(cur[i][j] == 'Q') return true;
        }
        for(int i = row-1, j = col+1; i>=0 && j<n; --i,++j){
            if(cur[i][j] == 'Q') return true;
        }
        return false;
    }
    void backtracking(int n, vector<bool>& usedCol, int row){
        if(row >= n){
            res.emplace_back(cur);
        }
        for(int j=0; j<n; ++j){
            if(usedCol[j]) continue;
            if(isValid(n, row, j)) continue;
            usedCol[j] = true;
            cur[row][j] = 'Q';
            backtracking(n, usedCol, row+1);
            usedCol[j] = false;
            cur[row][j] = '.';
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        res.clear();
        cur.clear();
        cur.resize(n, string(n, '.'));
        vector<bool> usedCol(n, false); //记录每一列是否用过
        backtracking(n, usedCol, 0);
        return res;
    }
};

int main(){
    int n = 9;
    Solution s;
    vector<vector<string>> res = s.solveNQueens(n);
    for(auto i: res){
        for(auto j: i){
            cout<<j<<endl;
        }
        cout<<endl;
    }
    system("pause");
    return 0;
}