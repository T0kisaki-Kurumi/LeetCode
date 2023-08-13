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
        vector<vector<int>> res;
        int len = nums.size();
        for(int i=0; i<len-3; i++){
            if((long long)nums[i]+nums[i+1]+nums[i+2]+nums[i+3] > target){
                return res;
            }
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            if((long long)nums[i]+nums[len-1]+nums[len-2]+nums[len-3] < target){
                continue;
            }
            int sum1 = target - nums[i];
            for(int j=i+1; j<len-2; j++){
                if((long long)nums[j]+nums[j+1]+nums[j+2] > sum1){
                    break;
                }
                if(j>i+1 && nums[j]==nums[j-1]){
                    continue;
                }
                if((long long)nums[j]+nums[len-1]+nums[len-2] < sum1){
                    continue;
                }
                int sum2 = sum1 - nums[j];
                int left = j + 1;
                int right = len - 1;
                while(left < right){
                    if(nums[left] + nums[right] < sum2){
                        left++;
                    }
                    else if(nums[left] + nums[right] > sum2){
                        right--;
                    }
                    else{
                        res.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;
                        while(left<right && nums[left]==nums[left-1]){
                            left++;
                        }
                        while(left<right && nums[right]==nums[right+1]){
                            right--;
                        }
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