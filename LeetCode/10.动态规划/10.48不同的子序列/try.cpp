// 115. 不同的子序列
// 给你两个字符串 s 和 t ，统计并返回在 s 的 子序列 中 t 出现的个数，结果需要对 109 + 7 取模。

// 示例 1：
// 输入：s = "rabbbit", t = "rabbit"
// 输出：3
// 解释：
// 如下所示, 有 3 种可以从 s 中得到 "rabbit" 的方案。
// rabbbit
// rabbbit
// rabbbit

// 示例 2：
// 输入：s = "babgbag", t = "bag"
// 输出：5
// 解释：
// 如下所示, 有 5 种可以从 s 中得到 "bag" 的方案。 
// babgbag
// babgbag
// babgbag
// babgbag
// babgbag

// 提示：

// 1 <= s.length, t.length <= 1000
// s 和 t 由英文字母组成

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int sLen = s.size();
        int tLen = t.size();
        if(sLen < tLen) return 0;
        vector<vector<int>> dp(sLen+1, vector<int>(tLen+1));
        for(int i=0; i<=sLen; ++i){
            dp[i][0] = 1;
        }
        for(int j=1; j<=tLen; ++j){
            dp[0][j] = 0;
        }
        for(int i=1; i<=sLen; ++i){
            for(int j=1; j<=tLen; ++j){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % 1000000007;
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[sLen][tLen];
    }
};

int main(){
    string s = "babgbag";
    string t = "bag";
    Solution sol;
    cout<<sol.numDistinct(s, t);
    system("pause");
    return 0;
}