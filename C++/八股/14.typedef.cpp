#include <iostream>
using namespace std;

// 一、给已定义的变量类型起个别名
struct __person
{
    char    name[20];
    uint8_t age;
    uint8_t height;
};
typedef __person person_t;
// //以上两段代码也可合并为一段，如下：
// typedef struct __person
// {
//     char    name[20];
//     uint8_t age;
//     uint8_t height;
// }person_t;

// 二、定义函数指针类型
typedef int (*pFunc_t)(char *frame, int len); //定义了一个函数指针类型pFunc_t, 返回值为int，形参为char*、int

// 三、定义数组指针类型
typedef int(*pArr_t)[5]; //定义一个指针类型，该类型的指针可以指向含5个int元素的一维数组

// 四、定义数组类型
typedef int arr_t[5];

int func(char* c, int l){
    return 123;
};

typedef int * pint;
#define PINT int *
int i1 = 1, i2 = 2;
const pint p1 = &i1;	// 常量指针，相当于 int * const p;
const PINT p2 = &i2;	// 指针常量，相当于 const int *p；或 int const *p；

int main(){
    arr_t arr;
    pArr_t pa = &arr;
    pFunc_t pf1 = func;
    cout<<(*pf1)("1", 1)<<endl;
    pFunc_t pf2 = &func;
    cout<<(*pf2)("1", 1)<<endl;

    system("pause");
}