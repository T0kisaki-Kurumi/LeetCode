#include <iostream>
#include <vector>
#include <memory>
#include <list>
#include <type_traits>
#include <map>
#include <stdexcept>
#include <unordered_map>
#include <forward_list>
#include <cmath>
#include <queue>

using namespace std;

class cmp{
public:
	bool operator()(const pair<int,int>& a, const pair<int,int>& b){
		return a.second > b.second;
	}
};

int main(){
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
	pq.push({3,3});
	pq.push({3,4});
	pq.push({3,5});
	pq.push({3,3});
	pq.push({3,1});
	while(!pq.empty()){
		cout<<pq.top().second;
		pq.pop();
	}

	system("pause");
    return 0;
}