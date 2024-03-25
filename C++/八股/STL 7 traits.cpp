#include <iostream>
 
template <class T>
struct MyIter {
    typedef T value_type; // 内嵌型别声明
    T* ptr;
    MyIter(T* p = 0) : ptr(p) {}
    T& operator*() const { return *ptr; }
};

// class type
template <class T>
struct iterator_traits {
    typedef typename T::value_type value_type;
};

// 偏特化1
template <class T>
struct iterator_traits<T*> {
    typedef T value_type;
};

// 偏特化2
template <class T>
struct iterator_traits<const T*> {
    typedef T value_type;
};
 
template <class I>
typename iterator_traits<I>::value_type
// 首先询问iterator_traits<I>::value_type,如果传递的I为指针,则进入特化版本,iterator_traits直接回答;如果传递进来的I为class type,就去询问T::value_type.
func(I ite) {
    std::cout << "normal version" << std::endl;
    return *ite;
}

int main() {
    // ...
    MyIter<int> ite(new int(8));
    std::cout << func(ite)<<std::endl;
    char *p = new char(52);
    std::cout<<func(p)<<std::endl;
    const double k = 3.6;
    std::cout<<func(&k)<<std::endl;

    system("pause");
}