#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int bag(const vector<int>& weight, const vector<int>& value, int bagweight) {
        int n = weight.size();
        vector<vector<int>> dp(n, vector<int>(bagweight+1, 0));
        for(int i=weight[0]; i<=bagweight; ++i){
            dp[0][i] = value[0];
        }
        for(int i=1; i<n; ++i){
            for(int j=1; j<=bagweight; ++j){
                if(j >= weight[i]){
                    dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]] + value[i]);
                }
                else dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n-1][bagweight];
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