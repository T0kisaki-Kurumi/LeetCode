#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int>& v){
    for(int i: v){
        cout<<i<<" ";
    }
    cout<<endl;
}

class Solution {
public:
    int bag(const vector<int> weight, const vector<int> value, int bagweight) {
        int num = weight.size();
        vector<int> dp(bagweight+1, 0);
        for(int i=0; i<num; ++i){
            for(int j=bagweight; j>=1; --j){
                if(j>=weight[i]) dp[j] = max(dp[j], dp[j-weight[i]] + value[i]);
                // else dp[j] = dp[j];
            }
            printVector(dp);
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