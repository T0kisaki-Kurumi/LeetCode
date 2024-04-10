#include <iostream>
#include <vector>
#include <memory>
#include <list>
#include <type_traits>
#include <map>
#include <stdexcept>
#include <unordered_map>
#include <algorithm>
#include <forward_list>
#include <cmath>
#include <queue>

using namespace std;

int main(){
<<<<<<< HEAD
    char *s = "hello world";
    // s[1] = 'H'; 
    cout<<sizeof(s)<<endl;
=======
    int n,k;
    cin>>n>>k;
    int minc = INT_MAX;  //最少人数
    long long mint = INT_MIN;  //最少人数的步骤的时间
    int minIndex; //最少人数的下标
    int c[k];
    long long t[k];
    for(int i=0; i<k; ++i){
        cin>>c[i]>>t[i];
        if(c[i] < minc || (c[i]==minc && t[i]>mint)){
            minc = c[i];
            mint = t[i];
            minIndex = i;
        }
    }
    int num;
    if(n % minc) num = n/minc + 1;
    else num = n/minc;
    
    long long sum = 0;
    for(int i=0; i<minIndex; ++i) sum += t[i];
    sum += num*t[minIndex];
    for(int i=minIndex+1; i<k; ++i) sum +=t[i];
    cout<<sum<<endl;
>>>>>>> 041c1bf7f8094b948cc22e1f8820c31854d04aeb

	// system("pause");
    return 0;
}