#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>
using namespace std;

int main(){
	vector<int> nums1{2,3,4,6,5,2,4};
	unordered_set<int> s1(nums1.begin(), nums1.end()); 
	for(int i: s1){
		cout<<i<<" ";
	}
	cout<<endl;
    system("pause");
}