#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int>& nums){
    for(int& i: nums){
        cout<<i<<" ";
    }
    cout<<endl;
}

// 冒泡排序
// 时间复杂度：平均O(n2)  最好O(n2)  最坏O(n2)
// 空间复杂度：O(1)
// 稳定性：稳定
void bubbleSort(vector<int>& nums){
    int len = nums.size();
    for(int i=0; i<len-1; ++i){
        for(int j=0; j<len-1-i; ++j){
            if(nums[j] > nums[j+1]){
                swap(nums[j], nums[j+1]);
            }
        }
        // printVector(nums);
    }
}

// 优化冒泡排序
// 时间复杂度：平均O(n2)  最好O(n)  最坏O(n2)
// 空间复杂度：O(1)
// 稳定性：稳定
void bubbleSort2(vector<int>& nums){
    int len = nums.size();
    bool flag;
    for(int i=0; i<len-1; ++i){
        flag = true;
        for(int j=0; j<len-1-i; ++j){
            if(nums[j] > nums[j+1]){
                swap(nums[j], nums[j+1]);
                flag = false;
            }
        }
        // printVector(nums);
        if(flag) return;
    }
}

int main(){
    vector<int> nums{8,9,1,4,2,3,6,7,5,5};
    printVector(nums);
    // bubbleSort(nums);
    bubbleSort2(nums);
    printVector(nums);
    system("pause");
    return 0;
}