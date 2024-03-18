// 46. 全排列
// 给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。

// 示例 1：
// 输入：nums = [1,2,3]
// 输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

// 示例 2：
// 输入：nums = [0,1]
// 输出：[[0,1],[1,0]]

// 示例 3：
// 输入：nums = [1]
// 输出：[[1]]

// 提示：

// 1 <= nums.length <= 6
// -10 <= nums[i] <= 10
// nums 中的所有整数 互不相同

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
    vector<bool> used;
    void backtracking(vector<int>& nums){
        if(path.size() == nums.size()){
            res.emplace_back(path);
            return;
        }
        for(int i=0; i<nums.size(); ++i){
            if(used[i]) continue;
            used[i] = true;
            path.emplace_back(nums[i]);
            backtracking(nums);
            path.pop_back();
            used[i] = false;
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        res.clear();
        path.clear();
        used.resize(nums.size(), false);
        backtracking(nums);
        return res;
    }
};

int main(){
    vector<int> nums{1,2,3};
    Solution s;
    vector<vector<int>> res = s.permute(nums);
    for(auto i: res){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<'\n';
    }
    system("pause");
    return 0;
}