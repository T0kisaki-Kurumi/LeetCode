// 47. 全排列 II
// 给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。

// 示例 1：
// 输入：nums = [1,1,2]
// 输出：
// [[1,1,2],
//  [1,2,1],
//  [2,1,1]]

// 示例 2：
// 输入：nums = [1,2,3]
// 输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

// 提示：

// 1 <= nums.length <= 8
// -10 <= nums[i] <= 10
#include <iostream>
#include <vector>
#include <algorithm>

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
            if(i>0 && nums[i]==nums[i-1]){
                if(!used[i-1]) continue;
            }
            if(used[i]) continue;
            used[i] = true;
            path.emplace_back(nums[i]);
            backtracking(nums);
            path.pop_back();
            used[i] = false;
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        res.clear();
        path.clear();
        sort(nums.begin(), nums.end());
        used.resize(nums.size(), false);
        backtracking(nums);
        return res;
    }
};

int main(){
    vector<int> nums{1,1,2};
    Solution s;
    vector<vector<int>> res = s.permuteUnique(nums);
    for(auto i: res){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<'\n';
    }
    system("pause");
    return 0;
}