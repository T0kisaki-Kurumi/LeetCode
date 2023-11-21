// 54. 替换数字（第八期模拟笔试）
// 时间限制：1.000S  空间限制：128MB

// 题目描述
// 给定一个字符串 s，它包含小写字母和数字字符，请编写一个函数，将字符串中的字母字符保持不变，而将每个数字字符替换为number。 例如，对于输入字符串 "a1b2c3"，函数应该将其转换为 "anumberbnumbercnumber"。

// 输入描述
// 输入一个字符串 s,s 仅包含小写字母和数字字符。

// 输出描述
// 打印一个新的字符串，其中每个数字字符都被替换为了number

// 输入示例
// a1b2c3

// 输出示例
// anumberbnumbercnumber

// 提示信息
// 数据范围：
// 1 <= s.length < 10000。

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string replaceNumber(string s) {
        int size = s.size();
        int l = size;
        int count = 0;
        for(char& c: s){
            if('0'<=c && c<='9') ++count;
        }
        size += count * 5;
        s.resize(size);
        int r = size;
        while(l >= 0){
            if('0'<=s[l] && s[l]<='9'){
                s[r--] = 'r';
                s[r--] = 'e';
                s[r--] = 'b';
                s[r--] = 'm';
                s[r--] = 'u';
                s[r--] = 'n';
            }
            else{
                s[r--] = s[l];
            }
            --l;
        }
        return s;
    }
};

int main(){
    string s = "a1b2c3";
    Solution sol;
    cout<<sol.replaceNumber(s)<<endl;
    system("pause");
    return 0;
}