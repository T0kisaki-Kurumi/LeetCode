// 96. 不同的二叉搜索树
// 给你一个整数 n ，求恰由 n 个节点组成且节点值从 1 到 n 互不相同的 二叉搜索树 有多少种？返回满足题意的二叉搜索树的种数。

// 示例 1：
// 输入：n = 3
// 输出：5

// 示例 2：
// 输入：n = 1
// 输出：1

// 提示：

// 1 <= n <= 19

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        for(int i=1; i<=n; ++i){
            for(int j=0; j<=i-1; ++j){
                dp[i] += (dp[j] * dp[i-1-j]);
            }
        }
        return dp[n];
    }
};

int main(){
    int n = 1;
    Solution sol;
    // for(;n<=19;++n){
    //     cout<<"if(n=="<<n<<") return "<<sol.numTrees(n)<<";"<<endl;
    // }
    cout<<sol.numTrees(n);
    system("pause");
    return 0;
}