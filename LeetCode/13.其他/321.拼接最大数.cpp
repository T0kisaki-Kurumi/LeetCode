// 321. 拼接最大数
// 给你两个整数数组 nums1 和 nums2，它们的长度分别为 m 和 n。数组 nums1 和 nums2 分别代表两个数各位上的数字。同时你也会得到一个整数 k。

// 请你利用这两个数组中的数字中创建一个长度为 k <= m + n 的最大数，在这个必须保留来自同一数组的数字的相对顺序。

// 返回代表答案的长度为 k 的数组。

// 示例 1：
// 输入：nums1 = [3,4,6,5], nums2 = [9,1,2,5,8,3], k = 5
// 输出：[9,8,6,5,3]

// 示例 2：
// 输入：nums1 = [6,7], nums2 = [6,0,4], k = 5
// 输出：[6,7,6,0,4]

// 示例 3：
// 输入：nums1 = [3,9], nums2 = [8,9], k = 3
// 输出：[9,8,9]

// 提示：

// m == nums1.length
// n == nums2.length
// 1 <= m, n <= 500
// 0 <= nums1[i], nums2[i] <= 9
// 1 <= k <= m + n

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

void printVector(vector<int> v){
    for(int i: v){
        cout<<i<<" ";
    }
    cout<<endl;
}

class Solution {
public:
    vector<int> maxSubSeq(vector<int>& nums, int k){
        int len = nums.size();
        vector<int> res;
        for(int& i: nums){
            while(!res.empty() && len>k && i>res.back()){
                --len;
                res.pop_back();
            }
            res.push_back(i);
        }
        while(len > k){
            res.pop_back();
            --len;
        }
        return res;
    }

    int compare(vector<int>& v1, vector<int>& v2, int index1, int index2){
        int len1 = v1.size();
        int len2 = v2.size();
        while(index1<len1 && index2<len2){
            int res = v1[index1++] - v2[index2++];
            if(res != 0) return res;
        }
        return (len1-index1) - (len2-index2);
    }

    vector<int> merge(vector<int>& v1, vector<int>& v2){
        int len1 = v1.size();
        int len2 = v2.size();
        if(len1 == 0) return v2;
        if(len2 == 0) return v1;
        int index1 = 0;
        int index2 = 0;
        vector<int> res(len1 + len2);
        int cur = 0;
        while(index1<len1 && index2<len2){
            // if(v1[index1] > v2[index2]) res[cur++] = v1[index1++];
            // else if(v1[index1] < v2[index2]) res[cur++] = v1[index2++];
            // else{
            //     int cmp = compare(v1, v2, index1, index2);
            //     if(cmp >= 0) res[cur++] = v1[index1++];
            //     else res[cur++] = v2[index2++];
            // }
            int cmp = compare(v1, v2, index1, index2);
            if(cmp >= 0) res[cur++] = v1[index1++];
            else res[cur++] = v2[index2++];
        }
        while(index1<len1){
            res[cur++] = v1[index1++];
        }
        while(index2<len2){
            res[cur++] = v2[index2++];
        }
        return res;
    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> res;
        int len1 = nums1.size();
        int len2 = nums2.size();
        for(int i=0; i<=k; ++i){
            if(i>len1 || k-i>len2) continue;
            // cout<<i<<endl;
            vector<int> v1 = maxSubSeq(nums1, i);
            vector<int> v2 = maxSubSeq(nums2, k-i);
            vector<int> cur = merge(v1, v2);

            // printVector(v1);
            // printVector(v2);
            // printVector(cur);
            // cout<<endl;
            
            if(compare(cur, res, 0, 0) > 0) res.swap(cur);
        }
        return res;
    }
};

int main(){
    // vector<int> v1{3,4,6,5};
    // vector<int> v2{9,1,2,5,8,3};
    vector<int> v1{6,7};
    vector<int> v2{6,0,4};
    int k = 5;
    Solution s;
    vector<int> res = s.maxNumber(v1, v2, k);
    for(int i: res){
        cout<<i<<" ";
    }
    cout<<endl;

    // vector<int> v1{}

    system("pause");
    return 0;
}