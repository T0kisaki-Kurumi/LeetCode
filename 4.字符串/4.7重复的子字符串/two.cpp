// 459. 重复的子字符串
// 给定一个非空的字符串 s ，检查是否可以通过由它的一个子串重复多次构成。

// 示例 1:
// 输入: s = "abab"
// 输出: true
// 解释: 可由子串 "ab" 重复两次构成。

// 示例 2:
// 输入: s = "aba"
// 输出: false

// 示例 3:
// 输入: s = "abcabcabcabc"
// 输出: true
// 解释: 可由子串 "abc" 重复四次构成。 (或子串 "abcabc" 重复两次构成。)

// 提示：

// 1 <= s.length <= 104
// s 由小写英文字母组成

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string ss = s + s;
        // 力扣别用search，巨慢
        auto iter = search(ss.begin()+1, ss.end()-1, s.begin(), s.end());
        return iter!=(ss.end()-1);
    }
};

int main(){
    string s = "abcabcabcabc";
    Solution sol;
    cout<<sol.repeatedSubstringPattern(s);
    system("pause");
    return 0;
}