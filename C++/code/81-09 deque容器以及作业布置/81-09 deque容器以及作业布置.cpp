#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

template<class T>
void printDeque(const deque<T>& d){
    for(class deque<T>::const_iterator it = d.begin(); it != d.end(); ++it){
        cout<<*it<<" ";
    }
    cout<<endl;
}

void test1(){
    deque<int> d{1,2,3,4,5};
    printDeque(d);
    cout<<d[3]<<endl;
    d.push_front(6);
    cout<<d[3]<<endl;
}

void test2(){
    deque<int> d(10000,1);
    for_each(d.begin(), d.end(), [](int& x){cout<<&x<<endl;});
}

int main(){
    // test1();
    test2();

    system("pause");
    return 0;
}