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

void insertionSort(vector<int>& nums){
    int len = nums.size();
    for(int i=1; i<len; ++i){
        int cur = nums[i];
        int j = i - 1;
        while(j>=0 && nums[j]>cur){
            nums[j+1] = nums[j];
            --j;
        }
        nums[j+1] = cur;
    }
}

// 桶排序
// 时间复杂度：平均  最好  最坏
// 空间复杂度：
// 稳定性：
void bucketSort(vector<int>& nums){
    int n = nums.size();
    int bucketSize = 3;
    int maxNum = *max_element(nums.begin(), nums.end());
    int minNum = *min_element(nums.begin(), nums.end());
    // 注意这里的桶的个数的计算方法
    int bucketNum = (maxNum - minNum) / bucketSize + 1;
    vector<vector<int>> buckets(bucketNum, vector<int>());
    for(int& i: nums){
        int bucketIndex = (i - minNum) / bucketSize;
        buckets[bucketIndex].push_back(i);
    }
    for(int i=0; i<bucketNum; ++i){
        // printVector(buckets[i]);
        insertionSort(buckets[i]);
        // printVector(buckets[i]);
    }
    int offset = 0;
    for(int i=0; i<bucketNum; ++i){
        copy(buckets[i].begin(), buckets[i].end(), nums.begin()+offset);
        offset += buckets[i].size();
    }
}


int main(){
    vector<int> nums{8,9,1,4,2,3,6,7,5,5};
    printVector(nums);
    bucketSort(nums);    
    printVector(nums);
    system("pause");
    return 0;
}