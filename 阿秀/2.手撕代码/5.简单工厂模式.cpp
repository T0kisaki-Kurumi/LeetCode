// 在日常开发中，凡是需要生成复杂对象的地方，都可以尝试考虑使用工厂模式来代替。
// 复杂对象指的是类的构造函数参数过多等对类的构造有影响的情况，因为类的构造过于复杂，如果直接在其他业务类内使用，
// 则两者的耦合过重，后续业务更改，就需要在任何引用该类的源代码内进行更改，光是查找所有依赖就很消耗时间了，更别说要一个一个修改了。

// 工厂模式的定义：
// 是指定义一个创建产品对象的工厂接口，将产品对象的实际创建工作推迟到具体子工厂类当中。这满足创建型模式中所要求的“创建与使用相分离”的特点。

// 简单工厂模式（Simple Factory Pattern） ，又叫作静态工厂方法模式（Static Factory Method Pattern）。
// 我们把被创建的对象称为“产品”，把创建产品的对象称为“工厂”。如果要创建的产品不多，只要一个工厂类就可以完成，这种模式叫“简单工厂模式”。
// 简单来说，简单工厂模式有一个具体的工厂类，可以生成多个不同的产品，属于创建型设计模式。

// 简单工厂模式主要 3个角色
// 简单工厂（SimpleFactory）：是简单工厂模式的核心，负责实现创建所有实例的内部逻辑。工厂类的-建产品类的方法可以被外界直接调用，创建所需的产品对象。
// 抽象产品（Product）：是简单工厂创建的所有对象的父类，负责描述所有实例共有的公共接口。
// 具体产品（ConcreteProduct）：是简单工厂模式的创建目标。

#include <iostream>
using namespace std;

class Product{
public:
    virtual void show() = 0;  // 纯虚函数
};

class ProductA: public Product{
public:
    void show() override{
        cout<<"product A"<<endl;
    }
};

class ProductB: public Product{
public:
    void show() override{
        cout<<"product B"<<endl;
    }
};

class ProductC: public Product{
public:
    void show() override{
        cout<<"product C"<<endl;
    }
};

enum TYPE{
    pA,
    pB,
    pC
};

class Factory{
public:
    Product* createProduct(TYPE t){
        switch(t){
            case pA:
                return new ProductA();
            case pB:
                return new ProductB();
            case pC:
                return new ProductC();
            default:
                return nullptr;
        }
    }
};

int main(){
    Factory f;
    Product* a = f.createProduct(pA);
    a->show();
    Product* b = f.createProduct(pB);
    b->show();
    Product* c = f.createProduct(pC);
    c->show();

    system("pause");
}