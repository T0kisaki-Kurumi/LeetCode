#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int bag(const vector<int> weight, const vector<int> value, int bagweight) {
        vector<int> dp(bagweight+1);
        int len = weight.size();
        for(int i=0; i<len; ++i){
            for(int j=weight[i]; j<=bagweight; ++j){
                dp[j] = max(dp[j], dp[j-weight[i]] + value[i]);
            }
        }
        return dp[bagweight];
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