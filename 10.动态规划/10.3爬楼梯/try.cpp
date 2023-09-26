// 70. 爬楼梯
// 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

// 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

// 示例 1：
// 输入：n = 2
// 输出：2
// 解释：有两种方法可以爬到楼顶。
// 1. 1 阶 + 1 阶
// 2. 2 阶

// 示例 2：
// 输入：n = 3
// 输出：3
// 解释：有三种方法可以爬到楼顶。
// 1. 1 阶 + 1 阶 + 1 阶
// 2. 1 阶 + 2 阶
// 3. 2 阶 + 1 阶

// 提示：

// 1 <= n <= 45

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n);
        int a = 1;
        int b = 2;
        if(n <= 2) return n;
        for(int i=3; i<=n; ++i){
            int sum = a + b;
            a = b;
            b = sum;
        }
        return b;
    }
};

int main(){
    int n = 4;
    Solution sol;
    cout<<sol.climbStairs(n);
    system("pause");
    return 0;
}