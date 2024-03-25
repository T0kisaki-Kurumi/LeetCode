#include <iostream>
#include <vector>
#include <memory>
#include <list>
#include <type_traits>
#include <map>
#include <stdexcept>
#include <unordered_map>
#include <forward_list>

using namespace std;
 
int main(){
	forward_list<int> fl{5,4,3,2,1};
	fl.push_front(1);
	cout<<*(fl.begin());


	system("pause");
    return 0;
}