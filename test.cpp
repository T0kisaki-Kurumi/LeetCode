#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int func(int a[]){
    cout<<a[3]<<endl;
    return 0;
}

void func2(int a[][3]){
    cout<<a[1][2]<<endl;
}

int main(){
<<<<<<< HEAD
	cout<<__cplusplus<<endl;
=======
	int a[5] = {0,1,2,3,4};
    int b[3][3] = {1,2,3,4,5,6,7,8,9};
    func(a);
    // cout<<b[1][2]<<endl;
>>>>>>> 69cb3eb147a8ca7e4e3d61bdc1b843bb98fa5b3e

    system("pause");
}