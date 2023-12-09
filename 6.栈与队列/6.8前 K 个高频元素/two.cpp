// 347. 前 K 个高频元素
// 给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。

// 示例 1:
// 输入: nums = [1,1,1,2,2,3], k = 2
// 输出: [1,2]

// 示例 2:
// 输入: nums = [1], k = 1
// 输出: [1]

// 提示：

// 1 <= nums.length <= 105
// k 的取值范围是 [1, 数组中不相同的元素的个数]
// 题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的

// 进阶：你所设计算法的时间复杂度 必须 优于 O(n log n) ，其中 n 是数组大小。

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    class cmp{
    public:
        bool operator()(const pair<int,int>& a, const pair<int,int>& b){
            return a.second > b.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(const int& i: nums){
            m[i]++;
        }
        vector<pair<int, int>> vec(m.begin(), m.end());
        sort(vec.begin(), vec.end(), cmp());
        vector<int> res(k);
        for(int i=0; i<k; ++i){
            res[i] = vec[i].first;
        }
        return res;
    }
};

int main(){
    vector<int> nums{1,1,1,2,2,3};
    int k = 2;
    Solution s;
    vector<int> res = s.topKFrequent(nums, k);
    for(int i: res){
        cout<<i<<" ";
    }
    system("pause");
    return 0;
}