#include <iostream>
#include <vector>
#include <memory>
#include <list>
#include <type_traits>
#include <map>
#include <stdexcept>
#include <unordered_map>
#include <algorithm>
#include <forward_list>
#include <cmath>
#include <queue>
#include <cstring>

using namespace std;

// long long mult[21];

int main(){
    long long AB = dp[i-2][0];
    long long BA = dp[i-2][1];
    long long AC = dp[i-2][0] - dp[i-3][1];

    long long OA = dp[i-1][0];
    long long OB = dp[i-1][1]; 
    long long OC = dp[i-1][2]; 
    long long OD = dp[i-1][3]; 
    
    //A
    dp[i][0] = (OA + OB + OC + OD) % MOD;

    //B
    dp[i][1] = (OA + OB + (OC-AC) + OD) % MOD;

    //C
    dp[i][2] = ((OA-BA) + (OB-AB) + OC + OD) % MOD;

    //D
    dp[i][3] = (OA + OB + OC + OD) % MOD;
}