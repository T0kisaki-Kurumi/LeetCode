#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int bag(const vector<int> weight, const vector<int> value, int bagweight) {
        int num = weight.size();
        vector<int> dp(bagweight+1, 0);
        for(int i=0; i<num; ++i){
            for(int j=bagweight; j>=weight[i]; --j){
                dp[j] = max(dp[j], dp[j-weight[i]] + value[i]);
            }
        }
        return dp.back();
    }
};

int main(){
    vector<int> weight{1,3,4};
    vector<int> value{15,20,30};
    int bagweight = 4;
    Solution sol;
    cout<<sol.bag(weight, value, bagweight);
    system("pause");
    return 0;
}