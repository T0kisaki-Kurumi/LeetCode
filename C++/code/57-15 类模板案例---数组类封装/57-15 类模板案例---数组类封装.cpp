#include <iostream>
#include <string>
#include "MyArray.hpp"
using namespace std;

class Person{
public:
    Person(){}
    Person(string name, int age):m_Name(name), m_Age(age){}
    string m_Name;
    int m_Age;
};

// ostream& operator<<(ostream& cout, Person& p){
//     cout<<p.m_Name<<" "<<p.m_Age;
//     return cout;
// }

template<class T>
void printArray(MyArray<T>& arr){
    for(int i=0; i<arr.getSize(); ++i){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

template<> void printArray(MyArray<Person>& arr){
    for(int i=0; i<arr.getSize(); ++i){
        cout<<arr[i].m_Name<<" "<<arr[i].m_Age<<endl;
    }
}

// void printIntArray(MyArray<int>& arr){
//     for(int i=0; i<arr.getSize(); ++i){
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;
// }

// void printPersonArray(MyArray<Person>& arr){
//     for(int i=0; i<arr.getSize(); ++i){
//         cout<<arr[i].m_Name<<" "<<arr[i].m_Age<<endl;
//     }
// }

void test1(){
    MyArray<int> intArray(100);
    for(int i=0; i<10; ++i){
        intArray.pushBack(i+100);
    }
    printArray(intArray);
    // printIntArray(intArray);
    intArray.popBack();
    printArray(intArray);
    // printIntArray(intArray);

    MyArray<Person> personArray(10);
    Person p1("aa", 100);
    Person p2("bb", 200);
    Person p3("cc", 300);

    personArray.pushBack(p1);
    personArray.pushBack(p2);
    personArray.pushBack(p3);
    printArray(personArray);
    // printPersonArray(personArray);
}

int main(){
    test1();
    system("pause");
    return 0;
}