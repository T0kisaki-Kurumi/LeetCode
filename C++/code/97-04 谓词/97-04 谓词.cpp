#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class GreaterThan2{
public:
    bool operator()(int val){
        return val>2;
    }
};

bool GreaterThan3(int val){
    return val>3;
}

void test1(){
    vector<int> v{1,2,3,4,5,1};
    vector<int>::iterator it1 = find_if(v.begin(), v.end(), GreaterThan2());
    cout<<*it1<<endl;
    vector<int>::iterator it2 = find_if(v.begin(), v.end(), GreaterThan3);
    cout<<*it2<<endl;
    vector<int>::iterator it3 = find_if(v.begin(), v.end(), [](int val)->bool {return val > 4;});
    cout<<*it3<<endl;

}

int main(){
    test1();

    system("pause");
    return 0;
}