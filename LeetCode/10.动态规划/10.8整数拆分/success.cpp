// 343. 整数拆分
// 给定一个正整数 n ，将其拆分为 k 个 正整数 的和（ k >= 2 ），并使这些整数的乘积最大化。

// 返回 你可以获得的最大乘积 。

// 示例 1:
// 输入: n = 2
// 输出: 1
// 解释: 2 = 1 + 1, 1 × 1 = 1。

// 示例 2:
// 输入: n = 10
// 输出: 36
// 解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36。

// 提示:

// 2 <= n <= 58

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, 1);
        // dp[2] = 1;
        if(n >= 3) dp[3] = 2;
        for(int i=4; i<=n; ++i){
            for(int j=2; j<=3; ++j){
                dp[i] = max(dp[i], max(j*dp[i-j], j*(i-j)));
            }
        }
        return dp[n];
    }
};

int main(){
    int n = 10;
    Solution sol;
    cout<<sol.integerBreak(n);
    system("pause");
    return 0;
}