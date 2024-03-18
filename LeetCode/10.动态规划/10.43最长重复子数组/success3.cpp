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
    int maxLength(const vector<int>& nums1, const vector<int>& nums2, int add1, int add2){
        int res = 0;
        int cur = 0;
        for(int i=add1, j=add2; i<nums1.size() && j<nums2.size(); ++i, ++j){
            if(nums1[i] == nums2[j]){
                res = max(res, ++cur);
            }
            else cur = 0;
        }
        return res;
    }

    int findLength(vector<int>& nums1, vector<int>& nums2) {
        // 滑动窗口法
        int n1 = nums1.size();
        int n2 = nums2.size();
        int res = 0;
        for(int i=0; i<n1; ++i){
            res = max(res, maxLength(nums1, nums2, i, 0));
        }
        for(int i=1; i<n2; ++i){
            res = max(res, maxLength(nums1, nums2, 0, i));
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