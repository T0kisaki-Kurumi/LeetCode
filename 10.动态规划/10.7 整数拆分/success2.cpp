// 343. 整数拆分
// 给定一个正整数 n ，将其拆分为 k 个 正整数 的和（ k >= 2 ），并使这些整数的乘积最大化。

// 返回 你可以获得的最大乘积 。

// 示例 1:
// 输入: n = 2
// 输出: 1
// 解释: 2 = 1 + 1, 1 × 1 = 1。

// 示例 2:
// 输入: n = 10
// 输出: 36
// 解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36。

// 提示:

// 2 <= n <= 58

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        if(n==2) return 1;
        if(n==3) return 2;
        int res=1;
        while(n>=3){
            res*=3;
            n-=3;
        }
        if(n==0) return res;
        else if(n==1) return res/3*4;
        else return res*2;
    }
};

int main(){
    int n = 10;
    Solution sol;
    cout<<sol.integerBreak(n);
    system("pause");
    return 0;
}