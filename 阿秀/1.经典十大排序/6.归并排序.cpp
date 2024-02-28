#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

void printVector(vector<int>& nums){
    for(int& i: nums){
        cout<<i<<" ";
    }
    cout<<endl;
}

// 归并排序
// 时间复杂度：平均O(nlogn)  最好O(nlogn)  最坏O(nlogn)
// 空间复杂度：O(n)
// 稳定性：稳定
void mergeSort(vector<int>& nums, vector<int>& tmp, int low, int high){
    if(low >= high) return;
    int mid = low + ((high - low) >> 1);
    // int mid = (low + high) / 2;
    int begin1=low, end1=mid, begin2=mid+1, end2=high;
    mergeSort(nums, tmp, begin1, end1);
    mergeSort(nums, tmp, begin2, end2);
    int cur = low;
    while(begin1<=end1 && begin2<=end2){
        tmp[cur++] = nums[begin1]<=nums[begin2] ? nums[begin1++] : nums[begin2++];
    }
    while(begin1 <= end1){
        tmp[cur++] = nums[begin1++];
    }
    while(begin2 <= end2){
        tmp[cur++] = nums[begin2++];
    }
    for(int i=low; i<=high; ++i){
        nums[i] = tmp[i];
    }
    // printVector(tmp);
}

void mergeSort2(vector<int>& nums, vector<int>& tmp, int low, int high){
    if(low >= high) return;
    int mid = low + ((high - low) >> 1);
    // int mid = (low + high) / 2;
    int begin1=low, end1=mid, begin2=mid+1, end2=high;
    mergeSort2(tmp, nums, begin1, end1);
    mergeSort2(tmp, nums, begin2, end2);
    int cur = low;
    while(begin1<=end1 && begin2<=end2){
        tmp[cur++] = nums[begin1]<=nums[begin2] ? nums[begin1++] : nums[begin2++];
    }
    while(begin1 <= end1){
        tmp[cur++] = nums[begin1++];
    }
    while(begin2 <= end2){
        tmp[cur++] = nums[begin2++];
    }
    for(int i=low; i<=high; ++i){
        nums[i] = tmp[i];
    }
    // printVector(tmp);
}


int main(){
    vector<int> nums{8,9,1,4,2,3,6,7,5,5};
    printVector(nums);
    // vector<int> tmp(nums.size());
    // while(count--) mergeSort(nums, tmp, 0, nums.size()-1);
    vector<int> tmp(nums);
    mergeSort2(nums, tmp, 0, nums.size()-1);
    nums.assign(tmp.begin(), tmp.end());
    printVector(nums);
    system("pause");
    return 0;
}