// 216. 组合总和 III
// 找出所有相加之和为 n 的 k 个数的组合，且满足下列条件：

// 只使用数字1到9
// 每个数字 最多使用一次 
// 返回 所有可能的有效组合的列表 。该列表不能包含相同的组合两次，组合可以以任何顺序返回。

// 示例 1:
// 输入: k = 3, n = 7
// 输出: [[1,2,4]]
// 解释:
// 1 + 2 + 4 = 7
// 没有其他符合的组合了。

// 示例 2:
// 输入: k = 3, n = 9
// 输出: [[1,2,6], [1,3,5], [2,3,4]]
// 解释:
// 1 + 2 + 6 = 9
// 1 + 3 + 5 = 9
// 2 + 3 + 4 = 9
// 没有其他符合的组合了。

// 示例 3:
// 输入: k = 4, n = 1
// 输出: []
// 解释: 不存在有效的组合。
// 在[1,9]范围内使用4个不同的数字，我们可以得到的最小和是1+2+3+4 = 10，因为10 > 1，没有有效的组合。

// 提示:

// 2 <= k <= 9
// 1 <= n <= 60

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
    void backtracking(int k, int target, int cur){
        if(k == 0){
            if(target == 0) res.emplace_back(path);
            return;
        }
        for(int i=cur; i<=(9-k+1); i++){
            // 1 0   2 1   3 3   4 6
            if(i*k + (k*k-k)/2 > target) break;
            path.emplace_back(i);
            backtracking(k-1, target-i, i+1);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        if(n > 45) return res;
        backtracking(k, n, 1);
        return res;
    }
};

int main(){
    int k = 3;
    int n = 9;
    Solution s;
    vector<vector<int>> res = s.combinationSum3(k,n);
    for(auto i: res){
        for(auto j: i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    system("pause");
    return 0;
}