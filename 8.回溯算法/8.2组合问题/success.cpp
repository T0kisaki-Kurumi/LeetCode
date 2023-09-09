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
    vector<vector<int>> res;
    vector<int> tmp;

    vector<vector<int>> combine(int n, int k) {
        // 二进制枚举
        //初始化tmp
        for(int i=1; i<=k; ++i){
            tmp.emplace_back(i);
        }
        // 加入一个哨兵n+1，当取到最大的k个数字时，j会等于k，跳出循环
        tmp.emplace_back(n+1);
        int j = 0;
        while(j < k){
            res.emplace_back(tmp.begin(), tmp.end()-1);
            j = 0;
            while(j < k && tmp[j] + 1 == tmp[j + 1]){
                tmp[j] = j + 1; //一边找一边置数
                ++j;
            }
            // 找到了这个j
            ++tmp[j];
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