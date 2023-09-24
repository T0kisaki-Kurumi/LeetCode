#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<int> vec{1,2,3,4,5};
    sort(vec.begin(), vec.end(), [](int a, int b){return a > b;});
    for(int i: vec){
        cout<<i<<" ";
    }
    cout<<'\n';
    vector<vector<int>> intervals{vector<int>{1,3},vector<int>{2,6},vector<int>{8,10},vector<int>{15,18}};
    sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){return a[0] > b[0];});
    for(auto i: intervals){
        for(int j: i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    system("pause");
}