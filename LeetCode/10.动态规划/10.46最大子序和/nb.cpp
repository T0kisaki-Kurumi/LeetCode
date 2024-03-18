// 53. 最大子数组和
// 给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

// 子数组 是数组中的一个连续部分。

// 示例 1：
// 输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
// 输出：6
// 解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。

// 示例 2：
// 输入：nums = [1]
// 输出：1

// 示例 3：
// 输入：nums = [5,4,-1,7,8]
// 输出：23

// 提示：

// 1 <= nums.length <= 105
// -104 <= nums[i] <= 104

// 进阶：如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的 分治法 求解。

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    struct Status{
        int iSum, lSum, rSum, mSum;
    };

    Status pushUp(Status l, Status r){
        int iSum = l.iSum + r.iSum;
        int lSum = max(l.lSum, l.iSum + r.lSum);
        int rSum = max(r.rSum, r.iSum + l.rSum);
        int mSum = max(max(l.mSum, r.mSum), l.rSum + r.lSum);
        Status res{iSum, lSum, rSum, mSum};
        return res;
    }

    Status getSum(vector<int>& nums, int l, int r){
        if(l == r){
            Status res{nums[l], nums[l], nums[l], nums[l]};
            return res;
        }
        int m = (l+r)>>1;
        Status lSub = getSum(nums, l, m);
        Status rSub = getSum(nums, m+1, r);
        return pushUp(lSub, rSub);
    }

    int maxSubArray(vector<int>& nums) {
        return getSum(nums, 0, nums.size()-1).mSum;
    }
};

int main(){
    vector<int> nums{-2,1,-3,4,-1,2,1,-5,4};
    Solution sol;
    cout<<sol.maxSubArray(nums);
    system("pause");
    return 0;
}