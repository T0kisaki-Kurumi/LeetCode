// 718. 最长重复子数组
// 给两个整数数组 nums1 和 nums2 ，返回 两个数组中 公共的 、长度最长的子数组的长度 。

// 示例 1：
// 输入：nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
// 输出：3
// 解释：长度最长的公共子数组是 [3,2,1] 。

// 示例 2：
// 输入：nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
// 输出：5

// 提示：

// 1 <= nums1.length, nums2.length <= 1000
// 0 <= nums1[i], nums2[i] <= 100

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        int res = 0;
        vector<vector<int>> dp(len1+1, vector<int>(len2+1, 0));
        for(int i=0; i<len1; ++i){
            for(int j=0; j<len2; ++j){
                if(nums1[i] == nums2[j]) dp[i+1][j+1] = dp[i][j]+1;
                res = max(res, dp[i+1][j+1]);
            }
        }
        return res;
    }
};

int main(){
    vector<int> nums1{1,2,3,2,1};
    vector<int> nums2{3,2,1,4,7};
    Solution sol;
    cout<<sol.findLength(nums1, nums2);
    system("pause");
    return 0;
}