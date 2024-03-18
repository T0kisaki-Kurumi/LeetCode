#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class cmp2{
public:
    bool operator()(int x, int y){
        return x<y;
    }
};

class Solution{
public:
    static bool cmp1(int a, int b){
        return a>b;
    }

    void solve(){
        vector<int> v{1,2,3,4,5};
        sort(v.begin(), v.end(), cmp1);
        for(int i: v){
            cout<<i<<" ";
        }
        cout<<endl;
        sort(v.begin(), v.end(), cmp2());
        for(int i: v){
            cout<<i<<" ";
        }
        cout<<endl;
    }
};
 
int main(){
    Solution s;
    s.solve();

    system("pause");
    return 0;
}