#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int>& nums){
    for(int& i: nums){
        cout<<i<<" ";
    }
    cout<<endl;
}

void quickSort(vector<int>& nums, int begin, int end){
    if(begin >= end) return;
    int l = begin, r = end;
    int key = nums[l];
    while(l < r){
        while(l < r && nums[r] >= key) --r;
        if(l < r){
            nums[l++] = nums[r];
        }
        while(l < r && nums[l] <= key) ++l;
        if(l < r){
            nums[r--] = nums[l];
        }
    }
    nums[l] = key;
    quickSort(nums, begin, l-1);
    quickSort(nums, l+1, end);
}

void mergeSort(vector<int>& nums, vector<int>& tmp, int begin, int end){
    if(begin >= end) return;
    int mid = begin + (end - begin) / 2;
    mergeSort(tmp, nums, begin, mid);
    mergeSort(tmp, nums, mid+1, end);
    int index1 = begin;
    int index2 = mid + 1;
    int indexTmp = begin;
    while(index1 <= mid && index2 <= end){
        tmp[indexTmp++] = nums[index1] <= nums[index2] ? nums[index1++] : nums[index2++];
    }
    while(index1 <= mid){
        tmp[indexTmp++] = nums[index1++];
    }
    while(index2 <= end){
        tmp[indexTmp++] = nums[index2++];
    }
}

void down(vector<int>& nums, int cur, int n){
    int max = cur;
    int lc = 2*cur+1;
    int rc = 2*cur+2;
    if(lc<n && nums[lc]>nums[max]) max = lc;
    if(rc<n && nums[rc]>nums[max]) max = rc;
    if(cur != max) {
        swap(nums[cur], nums[max]);
        down(nums, max, n);
    }
}

void buildHeap(vector<int>& nums){
    int n = nums.size();
    for(int i = (n-1 -1) / 2; i>=0; --i){
        down(nums, i, n);
    }
}

void heapSort(vector<int>& nums){
    buildHeap(nums);
    for(int i=nums.size()-1; i>0; --i){
        swap(nums[i], nums[0]);
        down(nums, 0, i);
    }
}

int main(){
    vector<int> nums{8,9,1,4,2,3,6,7,5,5};
    printVector(nums);

    // quickSort(nums, 0, nums.size()-1);

    // vector<int> tmp(nums);
    // mergeSort(nums, tmp, 0, nums.size()-1);
    // nums.assign(tmp.begin(), tmp.end());

    heapSort(nums);

    printVector(nums);
    system("pause");
    return 0;
}