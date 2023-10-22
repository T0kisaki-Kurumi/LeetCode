#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int a=1, b=2, c=3;
	int m = max(max(a,b),c);
	// int m1 = max(a,b,c);
	int m1 = max({a,b,c});
	cout<<m1;
    system("pause");
}