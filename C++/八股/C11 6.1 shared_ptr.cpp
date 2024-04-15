#include <iostream>
#include <memory>
#include <vector>

class Frame {
public:
    ~Frame(){std::cout<<"~Frame()"<<std::endl;}
};

void test(){
    std::shared_ptr<Frame> f(new Frame());              // 裸指针直接初始化
    //   std::shared_ptr<Frame> f1 = new Frame();            // Error，explicit禁止隐式初始化
    std::shared_ptr<Frame> f2(f);                       // 拷贝构造函数
    std::shared_ptr<Frame> f3 = f;                      // 拷贝构造函数
    f2 = f;                                             // copy赋值运算符重载
    std::cout << f3.use_count() << " " << f3.unique() << std::endl;

    std::shared_ptr<Frame> f4(std::move(new Frame()));        // 移动构造函数
    //   std::shared_ptr<Frame> f5 = std::move(new Frame());       // Error，explicit禁止隐式初始化
    std::shared_ptr<Frame> f6(std::move(f4));                 // 移动构造函数
    std::shared_ptr<Frame> f7 = std::move(f6);                // 移动构造函数
    std::cout << f7.use_count() << " " << f7.unique() << std::endl;

    std::shared_ptr<Frame[]> f8(new Frame[10]());             // Error，管理动态数组时，需要指定删除器
    std::shared_ptr<Frame> f9(new Frame[10](), std::default_delete<Frame[]>());

    auto f10 = std::make_shared<Frame>();               // std::make_shared来创建


    // 删除器，默认为 std::default_delete
    auto del1 = [](Frame* f){
        std::cout << "delete1" << std::endl;
        delete f;
    };
    auto del2 = [](Frame* f){
        std::cout << "delete2" << std::endl;
        delete f;
    };
    std::shared_ptr<Frame> df1(new Frame(), del1);
    std::shared_ptr<Frame> df2(new Frame(), del2);
    std::vector<std::shared_ptr<Frame>> v;
    v.push_back(df1);
    v.push_back(df2);
}

int main(){
    test();

    system("pause");
    return 0;
}
