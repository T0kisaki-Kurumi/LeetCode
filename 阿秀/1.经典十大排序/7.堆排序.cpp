#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int>& nums){
    for(int& i: nums){
        cout<<i<<" ";
    }
    cout<<endl;
}



int main(){
    vector<int> nums{8,9,1,4,2,3,6,7,5,5};
    printVector(nums);

    
    printVector(nums);
    system("pause");
    return 0;
}