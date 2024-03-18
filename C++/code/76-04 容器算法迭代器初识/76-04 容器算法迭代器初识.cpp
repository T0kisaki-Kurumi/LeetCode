#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void test1(){
    int arr[5] = {1,5,2,7,3};
    int* p = arr;
    for(int i=0; i<5; ++i){
        cout<<*(p++)<<" ";
    }
    cout<<endl;
}

void myPrint(int val){
    cout<<val<<" ";
}

void test2(){
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(5);
    vec.push_back(2);
    vec.push_back(7);
    vec.push_back(3);
    vector<int>::iterator itBegin = vec.begin();
    vector<int>::iterator itEnd = vec.end();
    while(itBegin != itEnd){
        cout<<*(itBegin++)<<" ";
    }
    cout<<endl;

    for(vector<int>::iterator it=vec.begin(); it!=vec.end(); ++it){
        cout<<*it<<" ";
    }
    cout<<endl;

    for_each(vec.begin(), vec.end(), myPrint);
    cout<<endl;
}

class Person{
public:
    Person(string name, int age){
        this->m_Age = age;
        this->m_Name = name;
    }

    string m_Name;
    int m_Age;
};

void myPrint2(Person& p){
    cout<<p.m_Age<<" "<<p.m_Name<<endl;
}

void test3(){
    vector<Person> vec;
    Person p1("Tom", 18);
    Person p2("Jerry", 19);
    vec.push_back(p1);
    vec.push_back(p2);

    for(vector<Person>::iterator it=vec.begin(); it!=vec.end(); ++it){
        cout<<it->m_Age<<" "<<(*it).m_Name<<endl;
    }
    for_each(vec.begin(), vec.end(), myPrint2);
}

void test4(){
    vector<Person*> vec;
    Person p1("Tom", 18);
    Person p2("Jerry", 19);
    vec.push_back(&p1);
    vec.push_back(&p2);
    
    for(vector<Person*>::iterator it=vec.begin(); it!=vec.end(); ++it){
        cout<<(*it)->m_Age<<" "<<(*it)->m_Name<<endl;
    }
}

void test5(){
    vector<vector<int>> vec;
    vector<int> v1{1,2,3};
    vector<int> v2{1,2,3,4,5};
    vector<int> v3{6,6};
    vec.push_back(v1);
    vec.push_back(v2);
    vec.push_back(v3);

    for(vector<vector<int>>::iterator it=vec.begin(); it!=vec.end(); ++it){
        for(vector<int>::iterator vit=(*it).begin(); vit!=(*it).end(); ++vit){
            cout<<*vit<<" ";
        }
        cout<<endl;
    }
}

int main(){
    // test1();
    // test2();
    // test3();
    // test4();
    test5();

    system("pause");
    return 0;
}