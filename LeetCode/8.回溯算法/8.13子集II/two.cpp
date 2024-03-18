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

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    bool isVisited[11] = {false};

    void backtracking(vector<int>& nums, int cur, int len){
        res.push_back(path);
        if(cur >= len) return;
        for(int i=cur; i<len; ++i){
            if(i>0 && nums[i]==nums[i-1]){
                if(!isVisited[i-1]) continue;
            }
            path.push_back(nums[i]);
            isVisited[i] = true;
            backtracking(nums, i+1, len);
            path.pop_back();
            isVisited[i] = false;
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backtracking(nums, 0, nums.size());
        return res;
    }
};

int main(){
    vector<int> nums{4,4,4,1,4};
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