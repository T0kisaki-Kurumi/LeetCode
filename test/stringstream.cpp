#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    string s = "  the sky    is blue  ";
    stringstream stream(s);
    string tmp;
    while(stream >> tmp){
        cout<<tmp<<endl;
    }
    system("pause");
}