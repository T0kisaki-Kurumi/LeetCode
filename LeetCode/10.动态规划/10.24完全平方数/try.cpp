// 279. 完全平方数
// 给你一个整数 n ，返回 和为 n 的完全平方数的最少数量 。

// 完全平方数 是一个整数，其值等于另一个整数的平方；换句话说，其值等于一个整数自乘的积。例如，1、4、9 和 16 都是完全平方数，而 3 和 11 不是。

// 示例 1：
// 输入：n = 12
// 输出：3 
// 解释：12 = 4 + 4 + 4

// 示例 2：
// 输入：n = 13
// 输出：2
// 解释：13 = 4 + 9

// 提示：

// 1 <= n <= 104

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        // int c=0;
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for(int i=1; i*i<=n; ++i){
            for(int j=i*i; j<=n; ++j){
                dp[j] = min(dp[j], dp[j-i*i]+1);
                // c++;
            }
        }
        // cout<<c<<endl;
        return dp.back();
    }
};

int main(){
    int n = 12;
    Solution sol;
    cout<<sol.numSquares(n);
    system("pause");
    return 0;
}