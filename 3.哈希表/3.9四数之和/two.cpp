// 18. 四数之和
// 给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。请你找出并返回满足下述全部条件且不重复的四元组 [nums[a], nums[b], nums[c], nums[d]] （若两个四元组元素一一对应，则认为两个四元组重复）：

// 0 <= a, b, c, d < n
// a、b、c 和 d 互不相同
// nums[a] + nums[b] + nums[c] + nums[d] == target
// 你可以按 任意顺序 返回答案 。

// 示例 1：
// 输入：nums = [1,0,-1,0,-2,2], target = 0
// 输出：[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

// 示例 2：
// 输入：nums = [2,2,2,2,2], target = 8
// 输出：[[2,2,2,2]]

// 提示：

// 1 <= nums.length <= 200
// -109 <= nums[i] <= 109
// -109 <= target <= 109

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        vector<vector<int>> res;
        for(int i=0; i<size-3; ++i){
            if(i>0 && nums[i]==nums[i-1]) continue;
            if((long long)nums[i]+nums[i+1]+nums[i+2]+nums[i+3] > target) break;
            if((long long)nums[i]+nums[size-1]+nums[size-2]+nums[size-3] < target) continue;
            int target2 = target - nums[i];
            for(int j=i+1; j<size-2; ++j){
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                if((long long)nums[j]+nums[j+1]+nums[j+2] > target2) break;
                if((long long)nums[j]+nums[size-1]+nums[size-2] < target2) continue;
                int target3 = target2 - nums[j];
                int l = j + 1;
                int r = size - 1;
                while(l < r){
                    if(nums[l] + nums[r] < target3){
                        ++l;
                    } else if(nums[l] + nums[r] > target3){
                        --r;
                    } else{
                        res.emplace_back(vector<int>{nums[i], nums[j], nums[l], nums[r]});
                        ++l;
                        --r;
                        while(nums[l]==nums[l-1] && l<r) ++l;
                        while(nums[r]==nums[r+1] && l<r) --r;
                    }
                }
            }
        }
        return res;
    }
};

int main(){
    vector<int> nums = {2,2,2,2,2};
    int target = 8;
    Solution s;
    vector<vector<int>> res = s.fourSum(nums, target);
    for(auto i: res){
        for(auto j: i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    system("pause");
    return 0;
}