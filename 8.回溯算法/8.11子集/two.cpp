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

using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    void backtracking(vector<int>& nums, int cur, int len){
        res.push_back(path);
        if(cur >= len) return;
        for(int i=cur; i<len; ++i){
            path.push_back(nums[i]);
            backtracking(nums, i+1, len);
            path.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int len = nums.size();
        backtracking(nums, 0, len);
        return res;
    }
};

int main(){
    vector<int> nums{1,2,3};
    Solution s;
    vector<vector<int>> res = s.subsets(nums);
    for(auto i: res){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<'\n';
    }
    system("pause");
    return 0;
}