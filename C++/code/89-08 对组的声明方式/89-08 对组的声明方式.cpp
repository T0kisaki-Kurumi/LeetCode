#include <iostream>
using namespace std;

void test1(){
    pair<double, int> p(3.14, 5);
    cout<<p.first<<" "<<p.second<<endl;

    pair<double, int> p2 = make_pair(1.14, 514);
    cout<<p2.first<<" "<<p2.second<<endl;
}

int main(){
    test1();

    system("pause");
    return 0;
}