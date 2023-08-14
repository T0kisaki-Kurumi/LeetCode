// 239. 滑动窗口最大值
// 给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。

// 返回 滑动窗口中的最大值 。

// 示例 1：
// 输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
// 输出：[3,3,5,5,6,7]
// 解释：
// 滑动窗口的位置                最大值
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       3
//  1 [3  -1  -3] 5  3  6  7       3
//  1  3 [-1  -3  5] 3  6  7       5
//  1  3  -1 [-3  5  3] 6  7       5
//  1  3  -1  -3 [5  3  6] 7       6
//  1  3  -1  -3  5 [3  6  7]      7

// 示例 2：
// 输入：nums = [1], k = 1
// 输出：[1]

// 提示：

// 1 <= nums.length <= 105
// -104 <= nums[i] <= 104
// 1 <= k <= nums.length

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    void pushD(deque<int>& dq, int k){
        // 注意这里是大于不是大于等于，因为可能有相等的最大数字
        while(!dq.empty() && k>dq.back()){
            dq.pop_back();
        }
        dq.push_back(k);
    }

    void popD(deque<int>& dq, int k){
        if(dq.front() == k){
            dq.pop_front();
        }
    }

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> res(nums.size() - k + 1);
        // 初始化dq
        for(int i=0; i<k; i++){
            pushD(dq, nums[i]);
        }
        res[0] = dq.front();
        for(int i=k; i<nums.size(); i++){
            popD(dq, nums[i - k]);
            pushD(dq, nums[i]);
            res[i - k + 1] = dq.front();
        }
        return res;
    }
};

int main(){
    vector<int> nums = {1, -1};
    int k = 1;
    Solution sol;
    vector<int> res = sol.maxSlidingWindow(nums, k);
    for(int i: res){
        cout<<i<<" ";
    }
    system("pause");
    return 0;
}