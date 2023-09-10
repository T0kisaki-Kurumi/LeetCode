// 40. 组合总和 II
// 给定一个候选人编号的集合 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

// candidates 中的每个数字在每个组合中只能使用 一次 。

// 注意：解集不能包含重复的组合。 

// 示例 1:
// 输入: candidates = [10,1,2,7,6,1,5], target = 8,
// 输出:
// [
// [1,1,6],
// [1,2,5],
// [1,7],
// [2,6]
// ]

// 示例 2:
// 输入: candidates = [2,5,2,1,2], target = 5,
// 输出:
// [
// [1,2,2],
// [5]
// ]

// 提示:

// 1 <= candidates.length <= 100
// 1 <= candidates[i] <= 50
// 1 <= target <= 30

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
    void dfs(vector<int>& candidates, int target, int index, vector<bool>& used){
        // if(target < 0) return;
        if(target == 0){
            res.emplace_back(path);
            return;
        }
        for(int i=index; i<candidates.size(); i++){
            if(candidates[i]>target) break;
            if(i>0 && candidates[i]==candidates[i-1] && used[i-1]==false) continue;
            used[i] = true;
            path.emplace_back(candidates[i]);
            dfs(candidates, target-candidates[i], i+1, used);
            used[i] = false;
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<bool> used(candidates.size(), false);
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, used);
        return res;
    }
};

int main(){
    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;
    Solution s;
    vector<vector<int>> res = s.combinationSum2(candidates, target);
    for(auto i: res){
        for(auto j: i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    system("pause");
    return 0;
}