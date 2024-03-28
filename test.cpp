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

class Base{
public:
	Base(): x(1){}
	
	int x;
};

class Son: public Base{
public:
	int y;
};

void test(){
	Son s;
	cout<<s.x<<endl;
	cout<<s.y<<endl;
}
 
int main(){
	test();

	system("pause");
    return 0;
}