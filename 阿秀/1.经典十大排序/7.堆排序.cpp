#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int>& nums){
    for(int& i: nums){
        cout<<i<<" ";
    }
    cout<<endl;
}

// 堆排序
// 时间复杂度：平均  最好  最坏
// 空间复杂度：
// 稳定性：
void heapify(vector<int>& nums, int i, int n){
    int max = i;
    int lc = 2*i+1;
    int rc = 2*i+2;
    if(lc<n && nums[max]<nums[lc]) max = lc;
    if(rc<n && nums[max]<nums[rc]) max = rc;
    if(max != i){
        swap(nums[i], nums[max]);
        heapify(nums, max, n);
    }
}

void buildHeap(vector<int>& nums, int n){
    for(int i=(n-1-1)/2; i>=0; --i){
        heapify(nums, i, n);
    }
}

void heapSort(vector<int>& nums){
    int n = nums.size();
    buildHeap(nums, n);
    for(int i=n-1; i>0; --i){
        swap(nums[0], nums[i]);
        heapify(nums, 0, i);
    }
}


int main(){
    vector<int> nums{8,9,1,4,2,3,6,7,5,5};
    printVector(nums);
    heapSort(nums);    
    printVector(nums);
    system("pause");
    return 0;
}