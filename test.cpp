#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

inline void printHeap(const vector<int>& heap){
    int len = heap.size();
    int layer = 1;
    int cur = 0;
    while(cur < len){
        for(int i=0; i<layer && cur<len; ++i){
            cout<<heap[cur++]<<" \n"[i == layer-1];
        }
        layer *= 2;
    }
}

inline void down(vector<int>& heap, int k, int n){
    int curMax = k;
    int l = k*2+1;
    int r = k*2+2;
    if(l<n && heap[l]>heap[curMax]) curMax = l;
    if(r<n && heap[r]>heap[curMax]) curMax = r;
    if(curMax != k){
        swap(heap[k], heap[curMax]);
        down(heap, curMax, n);
    }
}

inline void up(vector<int>& heap, int k){
    if(k == 0) return;
    int father = (k-1)/2;
    if(heap[father] < heap[k]){
        swap(heap[father], heap[k]);
        up(heap, father);
    }
}

inline void heapify(vector<int>& heap){
    int len = heap.size();
    for(int i=(len-1-1)/2; i>=0; --i) down(heap, i, len);
}

inline void heapSort(vector<int>& heap){
    for(int i=heap.size()-1; i>0; --i){
        swap(heap[i], heap[0]);
        
    }
    
}

int main(){
    vector<int> heap{1,2,3,4,5,6,7,8,9,10};
    heapify(heap);
    printHeap(heap);

    system("pause");
    return 0;
}