#include <iostream>
#include <string>
// #include "Person.h"
#include "Person.hpp"
using namespace std;

void test1(){
    Person<string, int> p1("Tom", 18);
    p1.showPerson();
}

int main(){
    test1();

    system("pause");
    return 0;
}