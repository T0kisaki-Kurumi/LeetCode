#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int bag(vector<int> weight, vector<int> value, vector<int> nums, int bagweight) {
        for(int i=0; i<nums.size(); ++i){
            while(nums[i]>1){
                weight.emplace_back(weight[i]);
                value.emplace_back(value[i]);
                nums[i]--;
            }
        }
        int num = weight.size();
        vector<int> dp(bagweight+1, 0);
        for(int i=0; i<num; ++i){
            for(int j=weight[i]; j<=bagweight; ++j){
                dp[j] = max(dp[j], dp[j-weight[i]] + value[i]);
            }
        }
        return dp.back();
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