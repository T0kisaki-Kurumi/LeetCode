#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

void printVector(vector<int>& nums){
    for(int& i: nums){
        cout<<i<<" ";
    }
    cout<<endl;
}

// 基数排序
// 时间复杂度：平均O(d*(n+r)) || O(n+k)  最好O(d*(n+r)) || O(n+k)  最坏O(d*(n+r)) || O(n+k)
// 空间复杂度：O(n+k)
// 稳定性：稳定
void radixSort(vector<int>& nums){
    int maxNum = *max_element(nums.begin(), nums.end());
    int radixBit = 1;
    while(maxNum > 10){
        ++radixBit;
        maxNum /= 10;
    }
    // cout<<radixBit<<endl;
    vector<queue<int>> buckets(10);
    for(int d=0; d<radixBit; ++d){
        int radix = pow(10, d);
        for(int i: nums){
            int j = (i / radix) % 10; //计算当前位的数字
            buckets[j].push(i);
        }
        int offset = 0;
        for(int i=0; i<10; ++i){
            while(!buckets[i].empty()){
                nums[offset++] = buckets[i].front();
                buckets[i].pop();
            }
        }
        // printVector(nums);
    }
}


int main(){
    vector<int> nums{81,92,53,49,288,355,667,784,53,5};
    // vector<int> nums{9,8,7,6,5,4,3,2,1};
    printVector(nums);
    radixSort(nums);    
    printVector(nums);
    system("pause");
    return 0;
}