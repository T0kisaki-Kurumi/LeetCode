#include <iostream>
#include <memory>
#include <vector>

class Frame
{
};

void myDeleter(Frame *p)
{
    std::cout << "invoke deleter(Frame*)" << std::endl;
    delete p;
}

void test(){
    std::unique_ptr<Frame> f(new Frame()); // 裸指针直接初始化
    // std::unique_ptr<Frame> f1 = new Frame(); // Error，explicit禁止隐式初始化
    // std::unique_ptr<Frame> f2(f);            // Error，禁止拷贝构造函数
    // std::unique_ptr<Frame> f3 = f;           // Error，禁止拷贝构造函数
    // f1 = f;                                  // Error，禁止copy赋值运算符重载

    std::unique_ptr<Frame> f4(std::move(new Frame())); // 移动构造函数
    // std::unique_ptr<Frame> f5 = std::move(new Frame()); // Error，explicit禁止隐式初始化
    std::unique_ptr<Frame> f6(std::move(f4));  // 移动构造函数
    std::unique_ptr<Frame> f7 = std::move(f6); // move赋值运算符重载

    std::unique_ptr<Frame[]> f8(new Frame[10]()); // 指向数组

    // auto f9 = std::make_unique<Frame>(); // std::make_unique来创建，C++14后支持


    // 删除器，默认为 std::default_delete
    // void (*pf)(Frame*) = myDeleter;
    // std::unique_ptr<Frame, decltype(pf)> df1(new Frame(), *pf);
    std::unique_ptr<Frame, decltype(&myDeleter)> df1(new Frame(), myDeleter);

    auto del = [](Frame *p)
    {
        std::cout << "invoke deleter([](Frame *))" << std::endl;
        delete p;
    };
    std::unique_ptr<Frame, decltype(del)> df2(new Frame(), del);
}

int main()
{
    test();

    system("pause");
    return 0;
}
