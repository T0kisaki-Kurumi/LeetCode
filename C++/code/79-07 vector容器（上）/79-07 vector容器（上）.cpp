#include <iostream>
#include <vector>
using namespace std;

void test1(){
    vector<int> v;
    // cout<<v.capacity()<<endl;
    for(int i=0; i<10; ++i){
        v.push_back(i);
        cout<<v.size()<<" "<<v.capacity()<<endl;
    }
}

template<class T>
void printVector(vector<T>& v){
    for(T& i: v){
        cout<<i<<" ";
    }
    cout<<endl;
}

void test2(){
    vector<int> v1;
    vector<int> v2(10, 6);
    printVector(v2);
    vector<int> v3(v2.begin()+5, v2.end());
    printVector(v3);
    vector<int> v4;
    v4.assign(v2.begin(), v2.begin()+5);
    printVector(v4);
}

void test3(){
    vector<int> v1{1,2,3};
    vector<int> v2{4,5};
    v1.swap(v2);
    printVector(v1);
    printVector(v2);
}

void test4(){
    vector<int> v1{1,2,3};
    cout<<v1.size()<<endl;
    printVector(v1);
    v1.resize(5);
    cout<<v1.size()<<endl;
    printVector(v1);
    v1.resize(10, 6);
    cout<<v1.size()<<endl;
    printVector(v1);
}

int main(){
    // test1();
    // test2();
    // test3();
    test4();

    system("pause");
    return 0;
}