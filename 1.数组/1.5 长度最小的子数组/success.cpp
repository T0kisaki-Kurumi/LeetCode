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
        int curSum = 0;
        int minLen = INT32_MAX;
        int size = nums.size();
        for(int left=0, right=0; right<size; right++){
            curSum += nums[right];
            while(curSum >= target){
                if(right-left+1 < minLen){
                    minLen = right-left+1;
                }
                curSum -= nums[left++];
            }
        }
        return minLen == INT32_MAX ? 0 : minLen;
    }
};

int main(){
    vector<int> nums{1,4,4};
    int target = 4;
    Solution s;
    int res = s.minSubArrayLen(target, nums);
    cout<<res;
    system("pause");
    return 0;
}