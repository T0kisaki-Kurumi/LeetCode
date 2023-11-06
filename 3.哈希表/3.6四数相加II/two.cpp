// 454. 四数相加 II

// 给你四个整数数组 nums1、nums2、nums3 和 nums4 ，数组长度都是 n ，请你计算有多少个元组 (i, j, k, l) 能满足：

// 0 <= i, j, k, l < n
// nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
 

// 示例 1：
// 输入：nums1 = [1,2], nums2 = [-2,-1], nums3 = [-1,2], nums4 = [0,2]
// 输出：2
// 解释：
// 两个元组如下：
// 1. (0, 0, 0, 1) -> nums1[0] + nums2[0] + nums3[0] + nums4[1] = 1 + (-2) + (-1) + 2 = 0
// 2. (1, 1, 0, 0) -> nums1[1] + nums2[1] + nums3[0] + nums4[0] = 2 + (-1) + (-1) + 0 = 0

// 示例 2：
// 输入：nums1 = [0], nums2 = [0], nums3 = [0], nums4 = [0]
// 输出：1

// 提示：

// n == nums1.length
// n == nums2.length
// n == nums3.length
// n == nums4.length
// 1 <= n <= 200
// -228 <= nums1[i], nums2[i], nums3[i], nums4[i] <= 228

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int res = 0;
        unordered_map<int, int> sum;
        for(int i: nums1){
            for(int j: nums2){
                ++sum[i+j];
            }
        }
        for(int i: nums3){
            for(int j: nums4){
                if(sum.find(-i-j) != sum.end()){
                    res += sum[-i-j];
                }
            }
        }
        return res;
    }
};

int main(){
    vector<int> s1 = {1,2};
    vector<int> s2 = {-2,-1};
    vector<int> s3 = {-1,2};
    vector<int> s4 = {0,2};
    Solution s;
    cout<<s.fourSumCount(s1,s2,s3,s4);
    system("pause");
    return 0;
}