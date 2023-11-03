// 977.有序数组的平方
// 力扣题目链接(opens new window)

// 给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。

// 示例 1：

// 输入：nums = [-4,-1,0,3,10]
// 输出：[0,1,9,16,100]
// 解释：平方后，数组变为 [16,1,0,9,100]，排序后，数组变为 [0,1,9,16,100]
// 示例 2：

// 输入：nums = [-7,-3,2,3,11]
// 输出：[4,9,9,49,121]

#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    vector<int> sortedSquares(vector<int>& nums){
        int size = nums.size();
        vector<int> res(size);
        int cur = size - 1;
        int left = 0;
        int right = size - 1;
        while(left <= right){
            int sqrLeft = nums[left]*nums[left];
            int sqrRight = nums[right]*nums[right];
            if(sqrLeft >= sqrRight){
                res[cur--] = sqrLeft;
                ++left;
            } else{
                res[cur--] = sqrRight;
                --right;
            }
        }
        return res;
    }
};

int main(){
    vector<int> nums{-7,-3,2,3,11};
    Solution s;
    vector<int> res = s.sortedSquares(nums);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    system("pause");
    return 0;
}