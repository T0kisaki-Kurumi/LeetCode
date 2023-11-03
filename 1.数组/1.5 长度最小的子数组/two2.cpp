// 给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的 连续 子数组，并返回其长度。如果不存在符合条件的子数组，返回 0。

// 示例：

// 输入：s = 7, nums = [2,3,1,2,4,3]
// 输出：2
// 解释：子数组 [4,3] 是该条件下的长度最小的子数组。
// 提示：

// 1 <= target <= 10^9
// 1 <= nums.length <= 10^5
// 1 <= nums[i] <= 10^5

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    int minSubArrayLen(int target, vector<int>& nums){
        int size = nums.size();
        int res = INT_MAX;
        int left = 0;
        int right = 0;
        int cur = 0;
        while(cur<target && right<size){
            cur += nums[right++];
        }
        if(cur<target) return 0;
        while(cur>=target){
            cur -= nums[left++];
        }
        res = right - left + 1;
        for(; right<size; ){
            cur += nums[right++];
            cur -= nums[left++];
            while(cur > target){
                res = right - left + 1;
                cur -= nums[left++];
            }
        }
        return res;
    }
};

int main(){
    vector<int> nums{2,3,1,2,4,3};
    int target = 7;
    Solution s;
    int res = s.minSubArrayLen(target, nums);
    cout<<res;
    system("pause");
    return 0;
}