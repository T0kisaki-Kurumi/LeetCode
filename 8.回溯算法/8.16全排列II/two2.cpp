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
public:
    vector<vector<int>> res;
    vector<int> path;
    bool isVisited[10] = {false};

    void backtracking(vector<int>& nums, vector<int>& path, int len){
        if(path.size() == len){
            res.push_back(path);
            return;
        }
        for(int i=0; i<len; ++i){
            if(isVisited[i]) continue;
            if(i>0 && nums[i]==nums[i-1] && !isVisited[i-1]) continue;
            path.push_back(nums[i]);
            isVisited[i] = true;
            backtracking(nums, path, len);
            path.pop_back();
            isVisited[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backtracking(nums, path, nums.size());
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