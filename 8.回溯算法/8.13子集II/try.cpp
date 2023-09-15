// 90. 子集 II
// 给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。

// 解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。

// 示例 1：
// 输入：nums = [1,2,2]
// 输出：[[],[1],[1,2],[1,2,2],[2],[2,2]]

// 示例 2：
// 输入：nums = [0]
// 输出：[[],[0]]

// 提示：

// 1 <= nums.length <= 10
// -10 <= nums[i] <= 10

// 78. 子集
// 给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。

// 解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。

// 示例 1：
// 输入：nums = [1,2,3]
// 输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

// 示例 2：
// 输入：nums = [0]
// 输出：[[],[0]]

// 提示：

// 1 <= nums.length <= 10
// -10 <= nums[i] <= 10
// nums 中的所有元素 互不相同

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
    vector<bool> isVisited;
    void backtracking(vector<int>& nums, int startIndex){
        res.emplace_back(path);
        if(startIndex >= nums.size()) return;
        for(int i=startIndex; i<nums.size(); ++i){
            if(i>0 && nums[i]==nums[i-1]){
                if(!isVisited[i-1]) continue;
            }
            isVisited[i] = true;
            path.emplace_back(nums[i]);
            backtracking(nums, i+1);
            isVisited[i] = false;
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        res.clear();
        path.clear();
        sort(nums.begin(), nums.end());
        isVisited.resize(nums.size(), false);
        backtracking(nums, 0);
        return res;
    }
};

int main(){
    vector<int> nums{1,2,2};
    Solution s;
    vector<vector<int>> res = s.subsetsWithDup(nums);
    for(auto i: res){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<'\n';
    }
    system("pause");
    return 0;
}