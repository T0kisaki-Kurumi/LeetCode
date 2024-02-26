#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int>& nums){
    for(int& i: nums){
        cout<<i<<" ";
    }
    cout<<endl;
}

// 选择排序
// 时间复杂度：平均O(n2)  最好O(n2)  最坏O(n2)
// 空间复杂度：O(1)
// 稳定性：不稳定  例如 5 8 5 2

void selectionSort(vector<int>& nums){
    int len = nums.size();
    for(int i=0; i<len-1; ++i){
        for(int j=i+1; j<len; ++j){
            if(nums[j] < nums[i]){
                swap(nums[i], nums[j]);
            }
        }
        // printVector(nums);
    }
}

int main(){
    vector<int> nums{8,9,1,4,2,3,6,7,5,5};
    printVector(nums);
    selectionSort(nums);
    printVector(nums);
    system("pause");
    return 0;
}