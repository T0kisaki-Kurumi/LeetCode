#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;



class Solution{
public:
	static bool cmp(pair<int,int>& a, pair<int,int>& b){
		return a.second < b.second;
	}
	void func(){
		vector<pair<int,int>> a;
		a.emplace_back(pair<int,int>{1,3});
		a.emplace_back(pair<int,int>{2,2});
		a.emplace_back(pair<int,int>{3,1});
		sort(a.begin(), a.end(), cmp);
		for(int i=0; i<3; ++i){
			cout<<a[i].first<<endl;
		}
	}
};

int main(){
	int a = 1;
	int b = 2;
	cout<<(a&b)<<endl;
    system("pause");
}