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
        int len1 = s.size();
        int len2 = t.size();
        if(len2 > len1) return 0;
        vector<int> dp(len2 + 1);
        dp[0] = 1;
        for(int i=1; i<=len1; ++i){
            for(int j=len2; j>0; --j){
                if(s[i-1] == t[j-1]){
                    dp[j] = (dp[j] + dp[j-1]) % 1000000007;
                }
            }
        }
        return dp[len2];
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