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
public:
    vector<vector<string>> res;
    vector<string> path;
    bool usedCol[9] = {false};
    bool usedDiagonal1[18] = {false};
    bool usedDiagonal2[18] = {false};

    void backtracking(int curRow, int n){
        if(curRow >= n){
            res.push_back(path);
            return;
        }
        for(int i=0; i<n; ++i){
            if(usedCol[i]) continue; //列
            if(usedDiagonal1[curRow + i]) continue;
            if(usedDiagonal2[n - 1 - curRow + i]) continue;
            usedCol[i] = true;
            usedDiagonal1[curRow + i] = true;
            usedDiagonal2[n - 1 - curRow + i] = true;
            path[curRow][i] = 'Q';
            backtracking(curRow+1, n);
            usedCol[i] = false;
            usedDiagonal1[curRow + i] = false;
            usedDiagonal2[n - 1 - curRow + i] = false;
            path[curRow][i] = '.';
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        string s(n, '.');
        for(int i=0; i<n; ++i){
            path.push_back(s);
        }
        backtracking(0, n);
        return res;
    }
};

int main(){
    int n = 4;
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