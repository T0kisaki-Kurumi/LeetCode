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
public:
    void backtracking(vector<vector<int>>& res, vector<int>& path, int begin, int end, int num){
        if(num == 0){
            res.push_back(path);
            return;
        }
        for(int i=begin; i<=(end-num+1); ++i){
            path.push_back(i);
            backtracking(res, path, i+1, end, num-1);
            path.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> path;
        backtracking(res, path, 1, n, k);
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