// 300. 最长递增子序列
// 给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。

// 子序列 是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。

// 示例 1：
// 输入：nums = [10,9,2,5,3,7,101,18]
// 输出：4
// 解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。

// 示例 2：
// 输入：nums = [0,1,0,3,2,3]
// 输出：4

// 示例 3：
// 输入：nums = [7,7,7,7,7,7,7]
// 输出：1

// 提示：

// 1 <= nums.length <= 2500
// -104 <= nums[i] <= 104

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        int res = 1;
        vector<int> dp(1, nums[0]);
        for(int i=1; i<len; ++i){
            if(nums[i] > dp.back()){
                dp.push_back(nums[i]);
            }
            else{
                int cur=-1, l=0, r=dp.size()-1;
                while(l <= r){
                    int mid = l+(r-l)/2;
                    if(dp[mid] < nums[i]){
                        l = mid+1;
                        cur = mid;
                    }
                    else{
                        r = mid-1;
                    }
                }
                dp[cur+1] = nums[i];  //即使dp[0]小于nums[i]也没关系，dp[0]的值是无所谓的
            }
            // for(int j=0; j<dp.size(); ++j){
            //     cout<<dp[j]<<" ";
            // }
            // cout<<endl;
        }
        return dp.size();
    }
};

int main(){
    // vector<int> nums{10,9,2,5,3,7,101,18};
    vector<int> nums{3,5,6,2,5,4,19,5,6,7,12};
    Solution sol;
    cout<<sol.lengthOfLIS(nums);
    system("pause");
    return 0;
}