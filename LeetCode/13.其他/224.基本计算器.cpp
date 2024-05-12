// 224. 基本计算器
// 给你一个字符串表达式 s ，请你实现一个基本计算器来计算并返回它的值。

// 注意:不允许使用任何将字符串作为数学表达式计算的内置函数，比如 eval() 。

// 示例 1：
// 输入：s = "1 + 1"
// 输出：2

// 示例 2：
// 输入：s = " 2-1 + 2 "
// 输出：3

// 示例 3：
// 输入：s = "(1+(4+5+2)-3)+(6+8)"
// 输出：23

// 提示：

// 1 <= s.length <= 3 * 105
// s 由数字、'+'、'-'、'('、')'、和 ' ' 组成
// s 表示一个有效的表达式
// '+' 不能用作一元运算(例如， "+1" 和 "+(2 + 3)" 无效)
// '-' 可以用作一元运算(即 "-1" 和 "-(2 + 3)" 是有效的)
// 输入中不存在两个连续的操作符
// 每个数字和运行的计算将适合于一个有符号的 32位 整数

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <cmath>

using namespace std;

class Solution {
public:
    void calc(stack<int>& nums, stack<char>& ops){
        int b = nums.top(); 
        nums.pop();
        int a = nums.top();
        nums.pop();
        char op = ops.top();
        ops.pop();
        if(op == '+'){
            nums.push(a + b);
        }
        else if(op == '-'){
            nums.push(a - b);
        }
        else if(op == '*'){
            nums.push(a * b);
        }
        else if(op == '/'){
            nums.push(a / b);
        }
        else if(op == '%'){
            nums.push(a % b);
        }
        else if(op == '^'){
            nums.push(pow(a,b));
        }
    }

    unordered_map<char, int> umap;
    void initMap(){
        umap['+'] = 1;
        umap['-'] = 1;
        umap['*'] = 2;
        umap['/'] = 2;
        umap['%'] = 2;
        umap['^'] = 3;
    }

    int calculate(string s) {
        while(1){
            auto pos = s.find(" ");
            if(pos == string::npos) break;
            s.replace(pos, 1, "");
        }
        // cout<<s<<endl;

        stack<int> nums;
        stack<char> ops;
        nums.push(0);
        int len = s.size();
        for(int i=0; i<len; ++i){
            char c = s[i];
            if(c == '('){
                ops.push('(');
            }
            else if(c == ')'){
                while(!ops.empty()){
                    char op = ops.top();
                    if(op == '('){
                        ops.pop();
                        break;
                    }
                    else{
                        calc(nums, ops);
                    }
                }
            }
            else if('0'<=c && c<='9'){
                int num = 0;
                int cur = i;
                while(cur<len && '0'<=s[cur] && s[cur]<='9'){
                    num *= 10;
                    num += (s[cur]-'0');
                    ++cur;
                }
                nums.push(num);
                i = cur - 1; // 因为for循环i还要+1
            }
            else{
                if(i>0 && (s[i-1]=='(' || s[i-1]=='+' || s[i-1]=='-')) nums.push(0);
                while(!ops.empty() && ops.top()!='('){
                    if(umap[ops.top()] >= umap[c]){
                        calc(nums, ops);
                    }
                    else break;
                }
                ops.push(c);
            }
        }
        while(!ops.empty() && ops.top()!='(') calc(nums, ops);
        return nums.top();
    }
};

int main(){
    string str = "(1 +( 4+5 +2 )-3) +(6  + 8)";
    Solution s;
    cout<<s.calculate(str)<<endl;

    system("pause");
    return 0;
}