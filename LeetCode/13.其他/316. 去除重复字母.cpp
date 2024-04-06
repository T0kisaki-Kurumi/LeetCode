// 316. 去除重复字母

// 给你一个字符串 s ，请你去除字符串中重复的字母，使得每个字母只出现一次。需保证 返回结果的
// 字典序
// 最小（要求不能打乱其他字符的相对位置）。

// 示例 1：
// 输入：s = "bcabc"
// 输出："abc"

// 示例 2：
// 输入：s = "cbacdcbc"
// 输出："acdb"

// 提示：

// 1 <= s.length <= 104
// s 由小写英文字母组成

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        string res;
        int count[26] = {0};
        for(char& c: s){
            ++count[c-'a'];
        }
        bool use[26] = {false};
        for(char& c: s){
            if(!use[c-'a']){
                while(!res.empty() && c<res.back() && count[res.back()-'a']>1){
                    --count[res.back()-'a'];
                    use[res.back()-'a'] = false;
                    res.pop_back();
                }
                res.push_back(c);
                use[c-'a'] = true;
            }
            else{
                --count[c-'a'];
            }
        }
        return res;
    }
};

int main(){
    string str = "bbcaac";
    Solution s;
    cout<<s.removeDuplicateLetters(str)<<endl;

    system("pause");
    return 0;
}