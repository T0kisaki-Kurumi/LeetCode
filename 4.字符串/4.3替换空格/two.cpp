// 剑指 Offer 05. 替换空格
// 请实现一个函数，把字符串 s 中的每个空格替换成"%20"。

// 示例 1：
// 输入：s = "We are happy."
// 输出："We%20are%20happy."

// 限制：

// 0 <= s 的长度 <= 10000

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        int size = s.size();
        int l = size - 1;
        for(char c: s){
            if(c == ' ') size += 2;
        }
        s.resize(size);
        int r = size - 1;
        while(l >= 0){
            if(s[l] == ' '){
                s[r--] = '0';
                s[r--] = '2';
                s[r--] = '%';
            } else{
                s[r--] = s[l];
            }
            l--;
        }
        return s;
    }
};

int main(){
    string s = "We are happy.";
    Solution sol;
    cout<<sol.replaceSpace(s);
    system("pause");
    return 0;
}