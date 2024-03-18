// 491. 递增子序列
// 给你一个整数数组 nums ，找出并返回所有该数组中不同的递增子序列，递增子序列中 至少有两个元素 。你可以按 任意顺序 返回答案。

// 数组中可能含有重复元素，如出现两个整数相等，也可以视作递增序列的一种特殊情况。

// 示例 1：
// 输入：nums = [4,6,7,7]
// 输出：[[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]

// 示例 2：
// 输入：nums = [4,4,3,2,1]
// 输出：[[4,4]]

// 提示：

// 1 <= nums.length <= 15
// -100 <= nums[i] <= 100

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(vector<int>& nums, int startIndex, int last){
        if(startIndex >= nums.size()){
            if(path.size()>1){
                res.emplace_back(path);
            }
            return;
        }
        if(nums[startIndex] >= last){
            path.emplace_back(nums[startIndex]);
            backtracking(nums, startIndex+1, nums[startIndex]);
            path.pop_back();
        }
        if(nums[startIndex] != last) backtracking(nums, startIndex+1, last);
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        res.clear();
        path.clear();
        backtracking(nums, 0, INT_MIN);
        return res;
    }
};

int main(){
    vector<int> nums{4,6,7,7};
    Solution s;
    vector<vector<int>> res = s.findSubsequences(nums);
    for(auto i: res){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<'\n';
    }
    system("pause");
    return 0;
}