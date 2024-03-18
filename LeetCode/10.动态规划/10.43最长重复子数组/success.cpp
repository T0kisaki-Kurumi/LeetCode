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
        int res = 0;
        vector<int> dp(nums2.size()+1, 0); //dp表示nums2中的前j个数字与nums1所有数字的最长重复子数组长度，且第j个数组不包含在这个子数组中时dp[j]为0
        for(int i=1; i<=nums1.size(); ++i){
            for(int j=nums2.size(); j>0; --j){ //倒序避免累加
                if(nums1[i-1] == nums2[j-1]){
                    dp[j] = dp[j-1] + 1;
                    res = max(res, dp[j]);
                }
                else dp[j] = 0; //一定要置零，不然的话下一轮遍历会叠加出错
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