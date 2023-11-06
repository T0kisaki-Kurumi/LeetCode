#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
#include <string>
using namespace std;

int main(){
	unordered_map<int, string> umap;
    umap.insert(pair<int, string>{1,"666"});
    // for(auto p: umap){
    for(pair<int, string> p: umap){
        cout<<p.first<<" "<<p.second<<endl;
        cout<<typeid(p).name()<<endl;
    }
    system("pause");
}