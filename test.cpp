#include <iostream>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <unordered_map>
using namespace std;

int main(){
    unordered_map<string, int> umap;
    cout<<umap.size()<<endl;
    umap.insert({"666",111});
    cout<<umap.size()<<endl;


    system("pause");
}