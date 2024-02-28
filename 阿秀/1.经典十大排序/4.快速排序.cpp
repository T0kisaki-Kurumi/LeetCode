#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int>& nums){
    for(int& i: nums){
        cout<<i<<" ";
    }
    cout<<endl;
}

int count = 0;

// 快速排序
// 时间复杂度：平均O(nlogn)  最好O(nlogn)  最坏O(n2)
// 空间复杂度：O(nlogn)
// 稳定性：不稳定
void quickSort(vector<int>& nums, int low, int high){
    int l=low, r=high;
    if(l >= r) return;
    int key = nums[l];
    while(l < r){
        while(l<r && key<=nums[r]){
            --r;
        }
        if(l < r){
            nums[l++] = nums[r];
            // ++count;
        }
        while(l<r && key>= nums[l]){
            ++l;
        }
        if(l < r){
            nums[r--] = nums[l];
            // ++count;
        }
    }
    nums[l] = key;
    ++count;
    quickSort(nums, low, l-1);
    quickSort(nums, l+1, high);
}

// 第二种写法少用，一次swap相当于三次赋值
void quickSort2(vector<int>& nums, int low, int high){
    if(low >= high) return;
    int key = nums[low];
    int cur = high;
    for(int i=high; i>=low; --i){
        if(nums[i] >= key){
            swap(nums[i], nums[cur--]);
            // ++count;
            // ++count;
            // ++count;
        }
    }
    // printVector(nums);
    quickSort2(nums, low, cur);
    quickSort2(nums, cur+2, high);
}

int main(){
    vector<int> nums{8,9,1,4,2,3,6,7,5,5};
    printVector(nums);
    quickSort(nums, 0, nums.size()-1);
    // quickSort2(nums, 0, nums.size()-1);
    cout<<count<<endl;
    printVector(nums);
    system("pause");
    return 0;
}