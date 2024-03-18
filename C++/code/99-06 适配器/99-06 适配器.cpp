#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

class MyPrint: public binary_function<int, int, void>{
public:
    void operator()(int x, int start) const{
        cout<<x<<" "<<start<<" "<<x + start<<endl;
    }
};

void test1(){
    vector<int> v{1,2,3,4,5};
    int offset = 100;
    for_each(v.begin(), v.end(), bind2nd(MyPrint(), offset));
    for_each(v.begin(), v.end(), bind1st(MyPrint(), offset));
}

class GreaterThan3: public unary_function<int, bool>{
public:
    bool operator()(int val) const{
        return val>3;
    }
};

class GreaterThanNum: public binary_function<int, int, bool>{
public:
    bool operator()(int val, int num) const{
        return val>num;
    }
};

void test2(){
    vector<int> v{3,2,3,4,5};
    vector<int>::iterator pos1 = find_if(v.begin(), v.end(), GreaterThan3());
    cout<<*pos1<<endl;
    vector<int>::iterator pos2 = find_if(v.begin(), v.end(), not1(GreaterThan3()));
    cout<<*pos2<<endl;
    vector<int>::iterator pos3 = find_if(v.begin(), v.end(), not1(bind2nd(GreaterThanNum(), 3)));
    cout<<*pos3<<endl;
    vector<int>::iterator pos4 = find_if(v.begin(), v.end(), not1(bind2nd(greater<int>(), 3)));
    cout<<*pos4<<endl;
    sort(v.begin(), v.end(), not2(greater<int>())); //从小到大排序
    for(int i: v){
        cout<<i<<" ";
    }
    cout<<endl;
}

void myPrint1(int val){
    cout<<val<<endl;
}

void myPrint2(int val, int num){
    cout<<val + num<<endl;
}

void test3(){
    vector<int> v{3,2,3,4,5};
    for_each(v.begin(), v.end(), myPrint1);
    for_each(v.begin(), v.end(), bind2nd(ptr_fun(myPrint2), 100));
}

class Person{
public:
    Person(int age): age(age){}

    void printPerson(){
        cout<<this->age<<endl;
    }

    int age;
};

void test4(){
    vector<Person> v{{1},{2},{3}};
    for_each(v.begin(), v.end(), [](Person& p){cout<<p.age<<endl;});
    for_each(v.begin(), v.end(), mem_fun_ref(&Person::printPerson));
}

int main(){
    // test1();
    // test2();
    // test3();
    test4();

    system("pause");
    return 0;
}