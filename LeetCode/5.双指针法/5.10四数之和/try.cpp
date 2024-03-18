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
        #define ll long long
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int len = nums.size();
        for(int i=0; i<len-3; i++){
            //第一个数字去重
            if(i>0 && nums[i]==nums[i-1]) continue;
            if((ll)nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target) break;
            if((ll)nums[i] + nums[len-3] + nums[len-2] + nums[len-1] < target) continue;
            int sum = target - nums[i];
            for(int j=i+1; j<len-2; j++){
                //第二个数字去重
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                if((ll)nums[j] + nums[j+1] + nums[j+2] > sum) break;
                if((ll)nums[j] + nums[len-2] + nums[len-1] < sum) continue;
                int left = j + 1;
                int right = len - 1;
                while(left < right){
                    int sum3 = nums[j] + nums[left] + nums[right];
                    if(sum3 > sum) right--;
                    else if(sum3 < sum) left++;
                    else{
                        res.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;
                        while(left<right && nums[left]==nums[left-1]) left++;
                        while(left<right && nums[right]==nums[right+1]) right--;
                    }
                }
            }
        }
        return res;
    }
};

int main(){
    vector<int> a = {1,0,-1,0,-2,2};
    int target = 0;
    Solution s;
    vector<vector<int>> res = s.fourSum(a, target);
    for(auto i: res){
        for(int j: i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    system("pause");
    return 0;
}