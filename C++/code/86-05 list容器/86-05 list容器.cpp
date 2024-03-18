#include <iostream>
#include <list>
using namespace std;

template<class T>
void printList(const list<T>& L){
    for(class list<T>::const_iterator it=L.begin(); it!=L.end(); ++it){
        cout<<*it<<" ";
    }
    cout<<endl;
}

void test1(){
    list<int> myList{1,2,3,4,5};
    myList.insert(myList.begin(), 6);
    printList(myList);
    list<int>::iterator it = myList.begin();
    ++it; ++it; ++it;
    auto new_it = myList.erase(myList.begin(), it);
    cout<<*new_it<<" "<<endl;
}

bool cmp(int a, int b){
    return a>b;
}

void test2(){
    list<int> myList{1,4,1,3,1,2};
    myList.remove(1);
    printList(myList);
    myList.sort();
    printList(myList);
    myList.sort(cmp);
    printList(myList);
}

int main(){
    // test1();
    test2();

    system("pause");
    return 0;
}