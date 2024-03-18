// 剑指 Offer 58 - II. 左旋转字符串
// 字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。请定义一个函数实现字符串左旋转操作的功能。比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"。

// 示例 1：
// 输入: s = "abcdefg", k = 2
// 输出: "cdefgab"

// 示例 2：
// 输入: s = "lrloseumgh", k = 6
// 输出: "umghlrlose"

// 限制：

// 1 <= k < s.length <= 10000

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        string s1 = s.substr(0, n);
        string s2 = s.substr(n, s.size()-n);
        return s2 + s1;
    }    
};

int main(){
    string s = "abcdefg";
    int n = 2;
    Solution sol;
    cout<<sol.reverseLeftWords(s, n);
    system("pause");
    return 0;
}