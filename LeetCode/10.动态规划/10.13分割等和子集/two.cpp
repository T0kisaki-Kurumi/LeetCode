// 416. 分割等和子集
// 给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。

// 示例 1：
// 输入：nums = [1,5,11,5]
// 输出：true
// 解释：数组可以分割成 [1, 5, 5] 和 [11] 。

// 示例 2：
// 输入：nums = [1,2,3,5]
// 输出：false
// 解释：数组不能分割成两个元素和相等的子集。

// 提示：

// 1 <= nums.length <= 200
// 1 <= nums[i] <= 100

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 == 1) return false;
        sum /= 2;
        int len = nums.size();
        vector<vector<int>> dp(len, vector<int>(sum+1));
        for(int i=nums[0]; i<=sum; ++i){
            dp[0][i] = nums[0];
        }
        for(int i=1; i<len; ++i){
            for(int j=0; j<=sum; ++j){
                if(j>=nums[i]) dp[i][j] = max(dp[i-1][j], dp[i-1][j-nums[i]] + nums[i]);
                else dp[i][j] = dp[i-1][j];
            }
        }
        return dp[len-1][sum] == sum;
    }
};

int main(){
    vector<int> nums{1,5,11,5};
    Solution sol;
    cout<<sol.canPartition(nums);
    system("pause");
    return 0;
}