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
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> tmp(k+1);
        int cur = 1;
        for_each(tmp.begin(), tmp.end()-1, [&cur](int& val){val = cur++;});
        tmp[k] = n+1;
        cur = 0;
        while(cur < k){
            cur = 0;
            res.emplace_back(tmp.begin(), tmp.end()-1);
            while(cur<k && tmp[cur]+1==tmp[cur+1]){
                tmp[cur] = cur + 1;
                ++cur;
            }
            ++tmp[cur];
        }
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