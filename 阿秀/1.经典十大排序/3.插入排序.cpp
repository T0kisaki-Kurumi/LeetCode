#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int>& nums){
    for(int& i: nums){
        cout<<i<<" ";
    }
    cout<<endl;
}

// 插入排序
// 时间复杂度：平均O(n2)  最好O(n)  最坏O(n2)
// 空间复杂度：O(1)
// 稳定性：稳定
void insertionSort(vector<int>& nums){
    int len = nums.size();
    for(int i=1; i<len; ++i){
        int cur = nums[i];
        int j = i-1;
        while(j>=0 && cur<nums[j]){
            nums[j+1] = nums[j];
            --j;
        }
        nums[j+1] = cur;
        // printVector(nums);
    }
}


int main(){
    vector<int> nums{8,9,1,4,2,3,6,7,5,5};
    printVector(nums);
    insertionSort(nums);    
    printVector(nums);
    system("pause");
    return 0;
}