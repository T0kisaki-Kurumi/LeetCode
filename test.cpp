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
#include <typeinfo>

using namespace std;

class A{
public:
	A(){cout<<"构造"<<endl;}
	~A(){cout<<"析构"<<endl;}
};

A func(){
	A a;
	return a;
}

void test(){
	// A&& a = func();
	const A& a = func();
	system("pause");
}
 
int main(){
	int a[5];
	for(int i: a){
		cout<<i<<" ";
	}
	cout<<endl;

	system("pause");
    return 0;
}