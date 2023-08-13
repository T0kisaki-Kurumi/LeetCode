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
        int numSpace = 0;
        for(auto i: s){
            if(i == ' '){
                numSpace++;
            }
        }
        int left = s.size()-1;
        s.resize(s.size()+2*numSpace);
        int right = s.size()-1;
        while(left>=0){
            if(s[left] == ' '){
                s[right--] = '0';
                s[right--] = '2';
                s[right--] = '%';
                left--;
            } else{
                s[right--] = s[left--];
            }
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