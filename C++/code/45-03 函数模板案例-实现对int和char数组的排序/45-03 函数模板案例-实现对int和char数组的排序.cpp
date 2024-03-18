#include <iostream>
using namespace std;

template<typename T>
void mySwap(T& a, T& b){
    T tmp = a;
    a = b;
    b = tmp;
}

template<typename T>
void mySort(T arr[], int len){
    for(int i=0; i<len; ++i){
        int min = i;
        for(int j=i+1; j<len; ++j){
            if(arr[j] < arr[min]) min = j;
        }
        if(min != i){
            mySwap(arr[i], arr[min]);
        }
    }
}

template<class T>
void printArray(T arr[], int len){
    for(int i=0; i<len; ++i){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void test1(){
    int a[5] = {5,4,3,2,1};
    mySort(a, sizeof(a)/sizeof(int));
    printArray(a, sizeof(a)/sizeof(int));

    char b[5] = {'5','4','3','2','1'};
    mySort(b, sizeof(b)/sizeof(char));
    printArray(b, sizeof(b)/sizeof(char));

    char c[] = "NJUST";
    cout<<sizeof(c)/sizeof(char)<<endl;
    mySort(c, sizeof(c)/sizeof(char));
    printArray(c, sizeof(c)/sizeof(char));
}

int main(){
    test1();

    system("pause");
    return 0;
}