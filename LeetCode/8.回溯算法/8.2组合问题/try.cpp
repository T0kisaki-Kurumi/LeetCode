// 77. 组合
// 给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。

// 你可以按 任何顺序 返回答案。

// 示例 1：
// 输入：n = 4, k = 2
// 输出：
// [
//   [2,4],
//   [3,4],
//   [2,3],
//   [1,2],
//   [1,3],
//   [1,4],
// ]

// 示例 2：
// 输入：n = 1, k = 1
// 输出：[[1]]

// 提示：

// 1 <= n <= 20
// 1 <= k <= n

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(int n, int k, int cur){
        // // 剪枝
        // if(path.size() + (n - cur + 1) < k) return;
        if(path.size() == k){
            res.emplace_back(path);
            return;
        }
        for(int i = cur; i <= n - (k - path.size()) + 1; i++){
            path.emplace_back(i);
            backtracking(n, k, i+1);
            path.pop_back();
        }
        return;
    }

public:
    vector<vector<int>> combine(int n, int k) {
        backtracking(n, k, 1);
        return res;
    }
};

int main(){
    int n = 4;
    int k = 2;
    Solution s;
    vector<vector<int>> res = s.combine(n,k);
    for(auto i: res){
        for(auto j: i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    system("pause");
    return 0;
}