#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int>& nums){
    for(int& i: nums){
        cout<<i<<" ";
    }
    cout<<endl;
}

// 基数排序
// 时间复杂度：平均  最好  最坏
// 空间复杂度：
// 稳定性：



int main(){
    vector<int> nums{8,9,1,4,2,3,6,7,5,5};
    printVector(nums);

    
    printVector(nums);
    system("pause");
    return 0;
}