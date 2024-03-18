// 279. 完全平方数
// 给你一个整数 n ，返回 和为 n 的完全平方数的最少数量 。

// 完全平方数 是一个整数，其值等于另一个整数的平方；换句话说，其值等于一个整数自乘的积。例如，1、4、9 和 16 都是完全平方数，而 3 和 11 不是。

// 示例 1：
// 输入：n = 12
// 输出：3 
// 解释：12 = 4 + 4 + 4

// 示例 2：
// 输入：n = 13
// 输出：2
// 解释：13 = 4 + 9

// 提示：

// 1 <= n <= 104

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// https://leetcode.cn/problems/perfect-squares/solutions/822940/wan-quan-ping-fang-shu-by-leetcode-solut-t99c/

class Solution {
public:
    // 判断是否为完全平方数
    bool isPerfectSquare(int x) {
        int y = sqrt(x);
        return y * y == x;
    }

    // 判断是否能表示为 4^k*(8m+7)
    bool checkAnswer4(int x) {
        while (x % 4 == 0) {
            x /= 4;
        }
        return x % 8 == 7;
    }

    int numSquares(int n) {
        if (isPerfectSquare(n)) {
            return 1;
        }
        if (checkAnswer4(n)) {
            return 4;
        }
        for (int i = 1; i * i <= n; i++) {
            int j = n - i * i;
            if (isPerfectSquare(j)) {
                return 2;
            }
        }
        return 3;
    }
};

int main(){
    int n = 12;
    Solution sol;
    cout<<sol.numSquares(n);
    system("pause");
    return 0;
}