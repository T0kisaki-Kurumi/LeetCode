// 738. 单调递增的数字
// 当且仅当每个相邻位数上的数字 x 和 y 满足 x <= y 时，我们称这个整数是单调递增的。

// 给定一个整数 n ，返回 小于或等于 n 的最大数字，且数字呈 单调递增 。

// 示例 1:
// 输入: n = 10
// 输出: 9

// 示例 2:
// 输入: n = 1234
// 输出: 1234

// 示例 3:
// 输入: n = 332
// 输出: 299

// 提示:

// 0 <= n <= 109

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string s = to_string(n);
        int nine_flag = s.size();
        for(int i=s.size()-1; i>0; --i){
            if(s[i-1] > s[i]){
                --s[i-1];
                nine_flag = i;
            }
        }
        for(int i=nine_flag; i<s.size(); ++i){
            s[i] = '9';
        }
        return stoi(s);
    }
};

int main(){
    int n = 100;
    Solution sol;
    cout<<sol.monotoneIncreasingDigits(n);
    system("pause");
    return 0;
}