#include <iostream>
#include <vector>
#include <list>
using namespace std;

template<class T>
void printVector(vector<T>& v){
    for(T& i: v){
        cout<<i<<" ";
    }
    cout<<endl;
}

void test1(){
    vector<int> v;
    for(int i=0; i<100000; ++i){
        v.push_back(i);
    }
    cout<<v.size()<<endl;
    cout<<v.capacity()<<endl;

    v.resize(5);
    cout<<v.size()<<endl;
    cout<<v.capacity()<<endl;

    // 收缩内存
    vector<int>(v).swap(v);
    cout<<v.size()<<endl;
    cout<<v.capacity()<<endl;
}

void test2(){
    vector<int> v;
    v.reserve(100000);
    // cout<<v.capacity()<<endl;
    int num = 0;
    int* p = nullptr;
    for(int i=0; i<100000; ++i){
        v.push_back(i);
        if(p != &v[0]){
            p = &v[0];
            ++num;
        }
    }
    cout<<num<<endl;
}

void test3(){
    vector<int> v{1,2,3,4,5};
    for(vector<int>::reverse_iterator it=v.rbegin(); it!=v.rend(); ++it){
        cout<<*it<<" ";
    }
    cout<<endl;
}

void test4(){
    vector<int> v{1,2,3,4,5};
    vector<int>::iterator it1 = v.begin();
    it1++;
    it1--;
    it1+2;

    list<int> l{1,2,3,4,5};
    list<int>::iterator it2 = l.begin();
    it2++;
    it2--;
    // it2+2;
}

int main(){
    // test1();
    // test2();
    test3();
    // test4();

    system("pause");
    return 0;
}