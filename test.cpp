#include <iostream>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <unordered_map>
#include <vector>
#include <set>
using namespace std;

bool cmp(const int& a, const int& b){
    return a>b;
}

int main(){
    set<int,cmp> s{2,6,4,7,8,3,1};
    
    system("pause");
}