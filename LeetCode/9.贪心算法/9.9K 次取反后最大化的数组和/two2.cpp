// 1005. K 次取反后最大化的数组和
// 给你一个整数数组 nums 和一个整数 k ，按以下方法修改该数组：

// 选择某个下标 i 并将 nums[i] 替换为 -nums[i] 。
// 重复这个过程恰好 k 次。可以多次选择同一个下标 i 。

// 以这种方式修改数组后，返回数组 可能的最大和 。

// 示例 1：
// 输入：nums = [4,2,3], k = 1
// 输出：5
// 解释：选择下标 1 ，nums 变为 [4,-2,3] 。

// 示例 2：
// 输入：nums = [3,-1,0,2], k = 3
// 输出：6
// 解释：选择下标 (1, 2, 2) ，nums 变为 [3,1,0,2] 。

// 示例 3：
// 输入：nums = [2,-3,-1,5,-4], k = 2
// 输出：13
// 解释：选择下标 (1, 4) ，nums 变为 [2,3,-1,5,4] 。

// 提示：

// 1 <= nums.length <= 104
// -100 <= nums[i] <= 100
// 1 <= k <= 104

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;

class Solution {
public:
    static bool cmp(int a, int b){
        return abs(a)>abs(b);
    }

    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), cmp);
        int cur = 0;
        int len = nums.size();
        while(k>0 && cur<len){
            if(nums[cur] < 0){
                --k;
                nums[cur] = -nums[cur];
            }
            ++cur;
        }
        if(k==0) return accumulate(nums.begin(), nums.end(), 0);
        if(k % 2 == 1) nums[len-1] = -nums[len-1];
        return accumulate(nums.begin(), nums.end(), 0);
    }
};

int main(){
    vector<int> nums = {-4,-2,-3};
    int k = 4;
    Solution sol;
    int res = sol.largestSumAfterKNegations(nums, k);
    cout<<res;
    system("pause");
    return 0;
}