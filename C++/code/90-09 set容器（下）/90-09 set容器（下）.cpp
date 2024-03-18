#include <iostream>
#include <set>
#include <string>
using namespace std;

template <class T>
void printSet(set<T>& s){
    for(class set<T>::iterator it=s.begin(); it!=s.end(); ++it){
        cout<<*it<<" ";
    }
    cout<<endl;
}

template <class T1, class T2>
void printSet(set<T1, T2>& s){
    for(class set<T1, T2>::iterator it=s.begin(); it!=s.end(); ++it){
        cout<<*it<<" ";
    }
    cout<<endl;
}

void test1(){
    set<int> s;
    pair<set<int>::iterator, bool> ret1 = s.insert(2);
    pair<set<int>::iterator, bool> ret2 = s.insert(2);
    cout<<*(ret1.first)<<" "<<ret1.second<<endl;
    cout<<*(ret2.first)<<" "<<ret2.second<<endl;

    multiset<int> ms;
    multiset<int>::iterator ret3 = ms.insert(114);
    multiset<int>::iterator ret4 = ms.insert(114);
    cout<<*ret3<<endl;
    cout<<*ret4<<endl;
}

class cmp{
public:
    bool operator()(const int& v1, const int& v2){
        return v1 > v2;
    }
};

void test2(){
    set<int> s{5,4,3,2,1};
    printSet(s);

    set<int, cmp> s2{5,4,3,2,1};
    printSet(s2);

}

class Person{
public:
    Person(string name, int age): name(name), age(age){}
    string name;
    int age;
};

class Person_cmp{
public:
    bool operator()(const Person& p1, const Person& p2){
        return p1.age > p2.age;
    }
};

void test3(){
    set<Person, Person_cmp> sp;
    Person p1("111",1);
    Person p2("222",2);
    Person p3("333",3);
    sp.insert(p1);
    sp.insert(p2);
    sp.insert(p3);
    for(auto& p: sp){
        cout<<p.age<<" "<<p.name<<endl;
    }
}

int main(){
    // test1();
    // test2();
    test3();

    system("pause");
    return 0;
}