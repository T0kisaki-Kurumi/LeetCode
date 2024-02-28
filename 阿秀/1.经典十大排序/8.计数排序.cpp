#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printVector(vector<int>& nums){
    for(int& i: nums){
        cout<<i<<" ";
    }
    cout<<endl;
}

// 计数排序
// 时间复杂度：平均O(n+k)  最好O(n+k)  最坏O(n+k)
// 空间复杂度：O(n+k)
// 稳定性：稳定
void countSort(vector<int>& nums, vector<int>& tmp){
    int maxNum = *max_element(nums.begin(), nums.end());
    vector<int> hashMap(maxNum+1);
    for(int& i: nums){
        ++hashMap[i];
    }
    for(int i=1; i<=maxNum; ++i){
        hashMap[i] += hashMap[i-1];
    }
    // 逆序保持稳定性
    for(int i=nums.size()-1; i>=0; --i){
        tmp[hashMap[nums[i]]-1] = nums[i];
        --hashMap[nums[i]];
    }
}


int main(){
    vector<int> nums{0,5,7,9,6,3,4,5,2,8,6,9,2,1};
    printVector(nums);
    vector<int> tmp(nums.size());
    countSort(nums, tmp);
    nums.assign(tmp.begin(), tmp.end());
    printVector(nums);
    system("pause");
    return 0;
}