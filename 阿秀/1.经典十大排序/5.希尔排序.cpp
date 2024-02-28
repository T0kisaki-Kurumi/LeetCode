#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int>& nums){
    for(int& i: nums){
        cout<<i<<" ";
    }
    cout<<endl;
}

// 希尔排序
// 时间复杂度：平均O(n1.3)  最好O(n)  最坏O(n2)
// 空间复杂度：O(1)
// 稳定性：不稳定

void shellSort(vector<int>& nums){
    int len = nums.size();
    int gap = len/2;
    while(gap > 0){
        for(int i=gap; i<len; ++i){
            // 插入排序
            int cur = nums[i];
            int j = i - gap;
            while(j>=0 && nums[j]>cur){
                nums[j+gap] = nums[j];
                j -= gap;
            }
            nums[j+gap] = cur;
        }
        gap /= 2;
    }
}


int main(){
    vector<int> nums{8,9,1,4,2,3,6,7,5,5};
    printVector(nums);
    shellSort(nums);
    
    printVector(nums);
    system("pause");
    return 0;
}