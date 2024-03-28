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

// A类只能静态分配
class A{
// private:
//     void* operator new(size_t t){};
//     void operator delete(void* p){};

public:
    void* operator new(size_t t) = delete;
    void operator delete(void* p) = delete;

	int x = 1;
};

// B类只能动态分配
class B{
protected:
    B(){}
    ~B(){}
public:
    static B* getInstance(){
        B* obj = new B();
        return obj;
    }

    static void deleteInstance(B* obj){
        delete obj;
    }
};

void test(){
	// A a = new A();
    A a;

    B* b = B::getInstance();
    // delete b;
    B::deleteInstance(b);

}
 
int main(){
	test();

	system("pause");
    return 0;
}