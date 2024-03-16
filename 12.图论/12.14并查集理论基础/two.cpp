#include <iostream>
#include <vector>
#define NUM 100

using namespace std;

vector<int> father(NUM);

void init(){
    for(int i=0; i<NUM; ++i){
        father[i] = i;
    }
}

int find(int i){
    return (i == father[i]) ? i : father[i] = find(father[i]);
}

bool isSame(int u, int v){
    u = find(u);
    v = find(v);
    return u == v;
}

void join(int u, int v){
    u = find(u);
    v = find(v);
    if(u != v){
        father[v] = u;
    }
}

int main(){
    init();
    // cout<<father[1]<<" "<<father[2]<<endl;
    cout<<isSame(1,2)<<endl;
    join(1,3);
    join(2,3);
    cout<<isSame(1,2)<<endl;
    system("pause");
    return 0;
}