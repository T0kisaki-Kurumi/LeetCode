#include <iostream>
#include <vector>

using namespace std;

int main(){
    for(int i=0; i<10; ++i){
        cout<<i<<" \n"[i == 10-1];
    }

    vector<int> v{1,2,3,4,5};
    while(!v.empty()){
        cout<<v.back()<<" \n"[v.size() == 1];
        v.pop_back();
    }

    system("pause");
    return 0;
}