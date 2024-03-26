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
    int x;
    virtual void print(){
        cout<<"Base Print"<<endl;
    }
};

class Son: virtual public Base{
public:
    int y;
    virtual void print() override{
        cout<<"Son Print"<<endl;
    }
};
 
int main(){
	

	system("pause");
    return 0;
}