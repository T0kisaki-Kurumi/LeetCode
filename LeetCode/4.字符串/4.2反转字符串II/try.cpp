// 541. 反转字符串 II
// 给定一个字符串 s 和一个整数 k，从字符串开头算起，每计数至 2k 个字符，就反转这 2k 字符中的前 k 个字符。

// 如果剩余字符少于 k 个，则将剩余字符全部反转。
// 如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。

// 示例 1：
// 输入：s = "abcdefg", k = 2
// 输出："bacdfeg"

// 示例 2：
// 输入：s = "abcd", k = 2
// 输出："bacd"

// 提示：

// 1 <= s.length <= 104
// s 仅由小写英文组成
// 1 <= k <= 104

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        int len = s.length();
        string res = "";
        int cur = 0;
        int flag = 1; //0反转 1不反转
        while(1){
            cur += k;
            int end = cur>=len?len:cur;
            if(flag){
                for(int i=end-1; i>=cur-k; i--){
                    res += s[i];
                }
                flag = 1-flag;
            } else{
                for(int i=cur-k; i<=end-1; i++){
                    res += s[i];
                }
                flag = 1-flag;
            }
            if(end == len) break;
        }
        return res;
    }
};

int main(){
    string s = "abcdefg";
    int k = 2;
    Solution sol;
    cout<<sol.reverseStr(s, k);
    system("pause");
    return 0;
}