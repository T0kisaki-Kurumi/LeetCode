#include <iostream>
#include <string>
using namespace std;
int main(){
    int a = 2;
    static int b = a;
    cout<<b<<endl;

    system("pause");
	return 0;
}