#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int>& v) // 左值引用参数
{
    for (auto i : v) cout << i << " ";
    cout << endl;
}

void printVector(vector<int>&& v) // 右值引用参数
{
    for (auto i : v) cout << i << " ";
    cout << endl;
}
 
int main(){
    vector<int> v1 = {1, 2, 3, 4, 5};
    vector<int> v2 = {6, 7, 8, 9, 10};

    printVector(v1); // 左值引用参数
    printVector(move(v2)); // 右值引用参数

    cout<<v1[0]<<endl;
    cout<<v2[0]<<endl;

    system("pause");
    return 0;
}