// 小顶堆功能：
// 1. 插入一个数字
// 2. 求集合中的最小值
// 3. 删除最小值
// 4. 删除任意一个元素
// 5. 修改任意一个元素
// 堆排序 = 求最小值 + 删除最小值

#include <iostream>
#include <vector>

using namespace std;

void printHeap(vector<int>& nums){
    int n = nums.size();
    int layerNum = 1;
    int cur = 0;
    while(cur < n){
        for(int i=cur; i<cur+layerNum && i<n; ++i){
            cout<<nums[i]<<" ";
        }
        cout<<endl;
        cur += layerNum;
        layerNum *= 2;
    }
    cout<<endl;
}

void up(vector<int>& nums, int cur){
    while(cur && nums[(cur-1)/2] > nums[cur]){
        swap(nums[(cur-1)/2], nums[cur]);
        cur = (cur-1) / 2;
    }
}

void down(vector<int>& nums, int cur, int n){
    int lc = cur*2+1;
    int rc = cur*2+2;
    int max = cur;
    if(lc<n && nums[lc]<nums[max]) max = lc;
    if(rc<n && nums[rc]<nums[max]) max = rc;
    if(max != cur){
        swap(nums[max], nums[cur]);
        down(nums, max, n);
    }
}

void buildHeap(vector<int>& nums){
    int n = nums.size();
    for(int i=(n-1 -1)/2; i>=0; --i) down(nums, i, n);
}

// 插入一个数
void insertHeap(vector<int>& nums, int num){
    nums.push_back(num);
    up(nums, nums.size()-1);
}

// 最小值
int minHeap(vector<int>& nums){
    return nums[0];
}

// 删除最小值
void deleteMin(vector<int>& nums){
    nums[0] = nums.back();
    nums.pop_back();
    down(nums, 0, nums.size());
}

// 删除堆中第k个数
void deleteK(vector<int>& nums, int k){
    nums[k] = nums.back();
    nums.pop_back();
    down(nums, k, nums.size());
    up(nums, k);
}

// 修改堆中第k个数
void modifyK(vector<int>& nums, int k, int newNum){
    nums[k] = newNum;
    down(nums, k, nums.size());
    up(nums, k);
}


int main(){
    vector<int> nums{2,4,8,4,2,5,8,9};
    buildHeap(nums);
    printHeap(nums);
    insertHeap(nums, 3);
    printHeap(nums);
    insertHeap(nums, 1);
    printHeap(nums);
    deleteMin(nums);
    printHeap(nums);
    deleteK(nums, 1);
    printHeap(nums);
    modifyK(nums, nums.size()-1, 0);
    printHeap(nums);

    system("pause");
}