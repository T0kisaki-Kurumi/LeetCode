#include <iostream>
#include <set>
using namespace std;

template <class T>
void printSet(set<T>& s){
    for(class set<T>::iterator it=s.begin(); it!=s.end(); ++it){
        cout<<*it<<" ";
    }
    cout<<endl;
}

void test1(){
    set<int> s;
    s.insert(1);
    s.insert(22);
    s.insert(3);
    s.insert(1);
    s.insert(5);
    printSet(s);

    s.erase(s.begin());
    printSet(s);
    s.erase(3);
    printSet(s);
    s.erase(3);
    printSet(s);
}

void test2(){
    set<int> s{1,2,3,4,5};
    set<int>::iterator pos = s.find(33);
    if(pos != s.end()){
        cout<<"找到元素"<<endl;
    }
    else{
        cout<<"没找到"<<endl;
    }

    cout<<s.count(10)<<endl;
    cout<<s.count(2)<<endl;
}

void test3(){
    set<int> s{10,20,30,40,50};
    auto lower = s.lower_bound(30);
    if(lower != s.end()) cout<<*lower<<endl;
    else cout<<"没有大于等于它的"<<endl;
    auto upper = s.upper_bound(30);
    if(upper != s.end()) cout<<*upper<<endl;
    else cout<<"没有大于它的"<<endl;
    
    auto equal = s.equal_range(30);
    cout<<*(equal.first)<<" "<<*(equal.second)<<endl;
}

int main(){
    // test1();
    // test2();
    test3();

    system("pause");
    return 0;
}