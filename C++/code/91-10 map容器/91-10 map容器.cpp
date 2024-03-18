#include <iostream>
#include <map>
using namespace std;

template<typename T1, typename T2>
void printMap(map<T1, T2>& m){
    for(typename map<T1, T2>::iterator it=m.begin(); it!=m.end(); ++it){
        cout<<it->first<<" "<<it->second<<endl;
    }
}

template<typename T1, typename T2, typename T3>
void printMap(map<T1, T2, T3>& m){
    for(typename map<T1, T2, T3>::iterator it=m.begin(); it!=m.end(); ++it){
        cout<<it->first<<" "<<it->second<<endl;
    }
}

void test1(){
    map<int, int> m;
    m.insert(pair<int, int>(1, 10));
    m.insert(make_pair(2, 20));
    m.insert(map<int, int>::value_type(3, 30));
    m[4] = 40;
    printMap(m);

    m[5];
    printMap(m);
    cout<<m.at(3)<<endl;
}

void test2(){
    map<int, int> m{{1,10}, {2,20}, {3,30}};
    printMap(m);
    m.erase(2);
    printMap(m);
    m.erase(m.begin());
    printMap(m);
}

void test3(){
    map<int, int> m{{1,10}, {2,20}, {3,30}};
    map<int, int>::iterator pos = m.find(2);
    cout<<pos->first<<" "<<pos->second<<endl;
    cout<<m.count(1)<<endl;

    multimap<int, int> mm{{1,10}, {1,10}, {1,20}};
    multimap<int, int>::iterator pos2 = mm.find(1);
    cout<<pos2->first<<" "<<pos2->second<<endl;
    cout<<mm.count(1)<<endl;
}

void test4(){
    map<int, int> m{{1,10}, {2,20}, {3,30}};
    map<int, int>::iterator pos1 = m.lower_bound(2);
    cout<<pos1->first<<" "<<pos1->second<<endl;
    map<int, int>::iterator pos2 = m.upper_bound(2);
    cout<<pos2->first<<" "<<pos2->second<<endl;
    pair<map<int, int>::iterator, map<int, int>::iterator> ret = m.equal_range(2);
    cout<<ret.first->first<<" "<<ret.second->first<<endl;
}

class cmp{
public:
    bool operator()(int a, int b){
        return a>b;
    }
};

void test5(){
    map<int, int, cmp> m{{1,10}, {2,20}, {3,30}};
    printMap(m);
}

int main(){
    test1();
    // test2();
    // test3();
    // test4();
    // test5();

    system("pause");
    return 0;
}