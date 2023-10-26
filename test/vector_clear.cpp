#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<bool> vec{true, false};
    cout<<vec.size()<<endl;
    vec.clear();
    cout<<vec.size()<<endl;
    system("pause");
    return 0;
}