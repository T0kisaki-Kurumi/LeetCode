// 373. 查找和最小的 K 对数字

// 给定两个以 非递减顺序排列 的整数数组 nums1 和 nums2 , 以及一个整数 k 。

// 定义一对值 (u,v)，其中第一个元素来自 nums1，第二个元素来自 nums2 。

// 请找到和最小的 k 个数对 (u1,v1),  (u2,v2)  ...  (uk,vk) 。

// 示例 1:
// 输入: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
// 输出: [1,2],[1,4],[1,6]
// 解释: 返回序列中的前 3 对数：
//      [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]

// 示例 2:
// 输入: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
// 输出: [1,1],[1,1]
// 解释: 返回序列中的前 2 对数：
//      [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]

// 提示:

// 1 <= nums1.length, nums2.length <= 105
// -109 <= nums1[i], nums2[i] <= 109
// nums1 和 nums2 均为 升序排列
// 1 <= k <= 104
// k <= nums1.length * nums2.length

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    class cmp{
        
    };

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
        int len1 = nums1.size();
        int len2 = nums2.size();

    }
};

int main(){
    vector<int> v1{1,7,11};
    vector<int> v2{2,4,6};
    int k = 3;
    Solution s;
    vector<vector<int>> res = s.kSmallestPairs(v1, v2, k);
    for(auto v: res){
        for(int i: v){
            cout<<i<<" ";
        }
        cout<<endl;
    }

    system("pause");
    return 0;
}