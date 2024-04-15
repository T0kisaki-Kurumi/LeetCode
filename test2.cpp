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
#include <cmath>
#include <queue>
#include <cstring>

using namespace std;

class A{
public:
    void hello(){
        cout<<"hello"<<endl;
    }
};

int main(){
    shared_ptr<A> a(new A());
    a->hello();

    system("pause");
}