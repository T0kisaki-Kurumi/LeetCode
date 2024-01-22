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
#include <cstring>

using namespace std;

class Solution {
public:
    void backtracking(vector<vector<int>>& res, vector<int>& cur, int pos, int target, vector<int>& candidates, bool used[]){
        if(target == 0){
            res.push_back(cur);
            return;
        }
        for(int i=pos; i<candidates.size() && candidates[i]<=target; ++i){
            if(i>0 && candidates[i]==candidates[i-1] && !used[i-1]) continue;
            cur.push_back(candidates[i]);
            used[i] = true;
            backtracking(res, cur, i+1, target-candidates[i], candidates, used);
            cur.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        bool used[candidates.size()];
        memset(used, false, sizeof(used));
        vector<vector<int>> res;
        vector<int> cur;
        backtracking(res, cur, 0, target, candidates, used);
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