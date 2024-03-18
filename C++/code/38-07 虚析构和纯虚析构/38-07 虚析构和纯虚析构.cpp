#include <iostream>
#include <cstring>
using namespace std;

class Animal{
public:
    Animal(){
        cout<<"调用Animal的构造函数"<<endl;
    }

    // virtual ~Animal(){
    //     cout<<"调用Animal的析构函数"<<endl;
    // }

    virtual ~Animal() = 0;

    virtual void speak(){
        cout<<"动物说话"<<endl;
    }
};

Animal::~Animal(){
    cout<<"调用Animal的析构函数"<<endl;
}

class Cat: public Animal{
public:
    Cat(char* name){
        cout<<"调用Cat的构造函数"<<endl;
        this->m_Name = new char[strlen(name) + 1];
        strcpy(this->m_Name, name);
    }

    void speak(){
        cout<<m_Name<<"小猫喵喵"<<endl;
    }

    ~Cat(){
        cout<<"调用Cat的析构函数"<<endl;
        if(this->m_Name != nullptr){
            delete[] this->m_Name;
            this->m_Name = nullptr;
        }
    }

    char* m_Name;
};

void test1(){
    Animal* a = new Cat("Tom");
    a->speak();
    delete a;

    // Animal a;
}

int main(){
    test1();

    system("pause");
    return 0;
}