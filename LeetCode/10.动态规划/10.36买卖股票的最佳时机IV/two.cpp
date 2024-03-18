// 188. 买卖股票的最佳时机 IV
// 给你一个整数数组 prices 和一个整数 k ，其中 prices[i] 是某支给定的股票在第 i 天的价格。

// 设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。也就是说，你最多可以买 k 次，卖 k 次。

// 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

// 示例 1：
// 输入：k = 2, prices = [2,4,1]

// 输出：2
// 解释：在第 1 天 (股票价格 = 2) 的时候买入，在第 2 天 (股票价格 = 4) 的时候卖出，这笔交易所能获得利润 = 4-2 = 2 。

// 示例 2：
// 输入：k = 2, prices = [3,2,6,5,0,3]
// 输出：7
// 解释：在第 2 天 (股票价格 = 2) 的时候买入，在第 3 天 (股票价格 = 6) 的时候卖出, 这笔交易所能获得利润 = 6-2 = 4 。
//      随后，在第 5 天 (股票价格 = 0) 的时候买入，在第 6 天 (股票价格 = 3) 的时候卖出, 这笔交易所能获得利润 = 3-0 = 3 。

// 提示：

// 1 <= k <= 100
// 1 <= prices.length <= 1000
// 0 <= prices[i] <= 1000

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int len = prices.size();
        if(len == 1) return 0;
        vector<vector<int>> dp(2, vector<int>(2*k+1));
        for(int i=0; i<k; ++i){
            dp[0][2*i+1] = -prices[0];
        }
        // for(int i: dp[0]){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        for(int i=1; i<len; ++i){
            for(int j=1; j<2*k+1; ++j){
                if(j%2 == 1) dp[i%2][j] = max(dp[(i-1)%2][j], dp[(i-1)%2][j-1] - prices[i]);
                else dp[i%2][j] = max(dp[(i-1)%2][j], dp[(i-1)%2][j-1] + prices[i]);
            }
            // for(int i: dp[i%2]){
            //     cout<<i<<" ";
            // }
            // cout<<endl;
        }
        return dp[(len-1)%2][2*k];
    }
};

int main(){
    int k = 2;
    // vector<int> nums{3,2,6,5,0,3};
    vector<int> nums{2,4,1};
    Solution sol;
    cout<<sol.maxProfit(k, nums);
    system("pause");
    return 0;
}