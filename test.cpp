#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(){
	vector<int> nums1{2,3,4,6,5,2,4};
	fill(nums1.begin(), nums1.end(), 0);
	for(int i: nums1){
		cout<<i<<" ";
	}
	string s[10];
	fill(s,s+10,"尹康华");
	for(string ss:s){
		cout<<ss<<endl;
	}
	cout<<endl;
    system("pause");
}