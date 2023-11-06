// 242. 有效的字母异位词

// 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。

// 注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。

 
// 示例 1:
// 输入: s = "anagram", t = "nagaram"
// 输出: true

// 示例 2:
// 输入: s = "rat", t = "car"
// 输出: false

// 提示:

// 1 <= s.length, t.length <= 5 * 104
// s 和 t 仅包含小写字母
 
// 进阶: 如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        int num[26];
        memset(num, 0, sizeof(num));
        int size = s.size();
        for(int i=0; i<size; ++i){
            ++num[s[i]-'a'];
            --num[t[i]-'a'];
        }
        for(int i=0; i<26; ++i){
            // cout<<num[i]<<" ";
            if(num[i]) return false;
        }
        return true;
    }
};

int main(){
    Solution sol;
    string s = "anagram";
    string t = "nagaram";
    cout<< sol.isAnagram(s,t);
    system("pause");
    return 0;
}