// 63. 不同路径 II
// 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。

// 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish”）。

// 现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？

// 网格中的障碍物和空位置分别用 1 和 0 来表示。

// 示例 1：
// 输入：obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
// 输出：2
// 解释：3x3 网格的正中间有一个障碍物。
// 从左上角到右下角一共有 2 条不同的路径：
// 1. 向右 -> 向右 -> 向下 -> 向下
// 2. 向下 -> 向下 -> 向右 -> 向右

// 示例 2：
// 输入：obstacleGrid = [[0,1],[0,0]]
// 输出：1

// 提示：

// m == obstacleGrid.length
// n == obstacleGrid[i].length
// 1 <= m, n <= 100
// obstacleGrid[i][j] 为 0 或 1

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), 0));
        for(int i=0; i<obstacleGrid.size() && obstacleGrid[i][0]==0; ++i){
            dp[i][0] = 1;
        }
        for(int j=0; j<obstacleGrid[0].size() && obstacleGrid[0][j]==0; ++j){
            dp[0][j] = 1;
        }
        for(int i=1; i<obstacleGrid.size(); ++i){
            for(int j=1; j<obstacleGrid[0].size(); ++j){
                if(obstacleGrid[i][j]) dp[i][j] = 0;
                else dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        // for(auto i:dp){
        //     for(int j:i){
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }
        return dp[obstacleGrid.size()-1][obstacleGrid[0].size()-1];
    }
};

int main(){
    // vector<vector<int>> obstacleGrid{{0,0,0},{0,1,0},{0,0,0}};
    vector<vector<int>> obstacleGrid{{0,1},{0,0}};
    Solution sol;
    cout<<sol.uniquePathsWithObstacles(obstacleGrid);
    system("pause");
    return 0;
}