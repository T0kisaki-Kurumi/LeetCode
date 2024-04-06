// 给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。
// 如果数组中不存在目标值 target，返回 [-1, -1]。
// 你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题。

// 示例 1：
// 输入：nums = [5,7,7,8,8,10], target = 8
// 输出：[3,4]

// 示例 2：
// 输入：nums = [5,7,7,8,8,10], target = 6
// 输出：[-1,-1]

// 示例 3：
// 输入：nums = [], target = 0
// 输出：[-1,-1]

// 提示：

// 0 <= nums.length <= 105
// -109 <= nums[i] <= 109
// nums 是一个非递减数组
// -109 <= target <= 109

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    pair<int, int> binaryFind(vector<int>& nums, int target, int l, int r, int len){
        if(l > r) return {-1, -1};
        if(nums[r] < target || nums[l] > target) return {-1, -1};
        if(nums[l]==target && nums[r]==target) return {l, r};
        int mid = l + (r - l) / 2;
        pair<int, int> p;
        if(nums[mid] < target){
            p = binaryFind(nums, target, mid+1, r, len);
        }
        else if(nums[mid] > target){
            p = binaryFind(nums, target, l, mid-1, len);
        }
        else{
            int left = binaryFind(nums, target, l, mid-1, len).first;
            int right = binaryFind(nums, target, mid+1, r, len).second;
            p.first = left==-1 ? mid : left;
            p.second = right==-1 ? mid : right;
        }
        return p;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int len = nums.size();
        pair<int, int> p = binaryFind(nums, target, 0, len-1, len);
        return vector<int>{p.first, p.second};
    }
};

int main(){
    vector<int> nums{5,7,7,8,8,10};
    Solution sol;
    vector<int> res = sol.searchRange(nums,8);
    for(auto i: res){
        cout<<i<<" ";
    }
    cout<<endl;
    system("pause");
    return 0;
}