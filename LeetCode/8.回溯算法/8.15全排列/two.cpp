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
public:
    vector<vector<int>> res;
    vector<int> path;
    bool isVisted[7] = {false};

    void backtracking(vector<int>& nums, vector<int>& path, int len){
        if(path.size() == len){
            res.push_back(path);
            return;
        }
        for(int i=0; i<len; ++i){
            if(isVisted[i]) continue;
            path.push_back(nums[i]);
            isVisted[i] = true;
            backtracking(nums, path, len);
            path.pop_back();
            isVisted[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        backtracking(nums, path, nums.size());
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