// 309. 买卖股票的最佳时机含冷冻期
// 给定一个整数数组prices，其中第  prices[i] 表示第 i 天的股票价格 。​

// 设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:

// 卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
// 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

// 示例 1:
// 输入: prices = [1,2,3,0,2]
// 输出: 3 
// 解释: 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出]

// 示例 2:
// 输入: prices = [1]
// 输出: 0

// 提示：

// 1 <= prices.length <= 5000
// 0 <= prices[i] <= 1000

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(2, vector<int>(4)); //0持有 1未持有非冷冻 2卖出 3未持有冷冻
        dp[0][0] = -prices[0];
        for(int i=1; i<prices.size(); ++i){
            dp[i%2][0] = max(dp[(i-1)%2][0], max(dp[(i-1)%2][1] - prices[i], dp[(i-1)%2][3] - prices[i]));
            dp[i%2][1] = max(dp[(i-1)%2][1], dp[(i-1)%2][3]);
            dp[i%2][2] = dp[(i-1)%2][0] + prices[i];
            dp[i%2][3] = dp[(i-1)%2][2];
        }
        vector<int> res = dp[(prices.size()-1)%2];
        return max(res[1], max(res[2], res[3]));
    }
};

int main(){
    vector<int> nums{1,2,3,0,2};
    Solution sol;
    cout<<sol.maxProfit(nums);
    system("pause");
    return 0;
}