// 37. 解数独
// 编写一个程序，通过填充空格来解决数独问题。

// 数独的解法需 遵循如下规则：

// 数字 1-9 在每一行只能出现一次。
// 数字 1-9 在每一列只能出现一次。
// 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图）
// 数独部分空格内已填入了数字，空白格用 '.' 表示。

// 示例 1：
// 输入：board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
// 输出：[["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
// 解释：输入的数独如上图所示，唯一有效的解决方案如下所示：

// 提示：

// board.length == 9
// board[i].length == 9
// board[i][j] 是一位数字或者 '.'
// 题目数据 保证 输入数独仅有一个解

#include <iostream>
#include <vector>
#include <string>
#include<windows.h>

using namespace std;

class Solution {
private:
    bool backtracking(vector<vector<char>>& board) {
        for(int i=0; i<9; ++i){
            for(int j=0; j<9; ++j){
                if(board[i][j] == '.'){
                    cout<<"当前："<<i<<","<<j<<endl;
                    for(char k='1'; k<='9'; ++k){
                        if(isValid(i, j, k, board)){
                            board[i][j] = k;
                            printBorad(board);
                            Sleep(1500);
                            cout<<endl;
                            if(backtracking(board)) return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    bool isValid(int row, int col, char k, const vector<vector<char>>& board){
        // for(int i=0; i<9; ++i){
        //     if(board[row][i] == k || board[i][col] == k) return false;
        // }
        for(int i=0; i<9; ++i){
            if(board[row][i] == k){
                cout<<row<<","<<col<<" 是 "<<k<<" 不行，和"<<row<<","<<i<<"相同"<<endl;
                return false;
            }
        }
        for(int i=0; i<9; ++i){
            if(board[i][col] == k){
                cout<<row<<","<<col<<" 是 "<<k<<" 不行，和"<<i<<","<<col<<"相同"<<endl;
                return false;
            }
        }
        int rowBlock = (row/3)*3;
        int colBlock = (col/3)*3;
        for(int i=rowBlock; i<rowBlock+3; ++i){
            for(int j=colBlock; j<colBlock+3; ++j){
                if(board[i][j] == k){
                    cout<<row<<","<<col<<" 是 "<<k<<" 不行，和"<<i<<","<<j<<"相同"<<endl;
                    return false;
                }
            }
        }
        return true;
    }
    void printBorad(const vector<vector<char>>& board){
        for(auto i: board){
            for(auto j: i){
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtracking(board);
    }
};

int main(){
    vector<vector<char>> board = {vector<char>{'5','3','.','.','7','.','.','.','.'},vector<char>{'6','.','.','1','9','5','.','.','.'},vector<char>{'.','9','8','.','.','.','.','6','.'},vector<char>{'8','.','.','.','6','.','.','.','3'},vector<char>{'4','.','.','8','.','3','.','.','1'},vector<char>{'7','.','.','.','2','.','.','.','6'},vector<char>{'.','6','.','.','.','.','2','8','.'},vector<char>{'.','.','.','4','1','9','.','.','5'},vector<char>{'.','.','.','.','8','.','.','7','9'}};
    Solution s;
    s.solveSudoku(board);
    for(auto i: board){
        for(auto j: i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    system("pause");
    return 0;
}