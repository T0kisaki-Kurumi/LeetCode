#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int bag(const vector<int> weight, const vector<int> value, int bagweight) {
        vector<vector<int>> dp(weight.size(), vector<int>(bagweight+1, 0));
        for(int i=weight[0]; i<=bagweight; ++i){
            dp[0][i] = value[0];
        }
        for(int i=1; i<weight.size(); ++i){
            for(int j=1; j<=bagweight; ++j){
                if(j < weight[i]) dp[i][j] = dp[i-1][j];
                else dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]] + value[i]);
            }
        }
        for(auto i:dp){
            for(int j:i){
                cout<<j<<" ";
            }
            cout<<endl;
        }
        return dp.back().back();
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