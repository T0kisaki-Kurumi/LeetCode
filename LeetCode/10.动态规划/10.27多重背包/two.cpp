#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int bag(vector<int> weight, vector<int> value, vector<int> nums, int bagweight) {
        int num = weight.size();
        vector<int> dp(bagweight+1);
        for(int i=0; i<num; ++i){
            int curNum = nums[i];
            for(int j=weight[i]; j<=bagweight; ++j){
                for(int k=1; k<=curNum; ++k){
                    if(j-k*weight[i] >= 0){
                        dp[j] = max(dp[j], dp[j-k*weight[i]] + k*value[i]);
                    }
                    
                }
            }
        }
        return dp[bagweight];
    }
};

int main(){
    vector<int> weight{1,3,4};
    vector<int> value{15,20,30};
    vector<int> nums = {2,3,2};
    int bagweight = 10;
    Solution sol;
    cout<<sol.bag(weight, value, nums, bagweight);
    system("pause");
    return 0;
}