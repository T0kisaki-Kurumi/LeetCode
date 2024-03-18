#include <iostream>
using namespace std;

class CPU{
public:
    virtual void calculate() = 0;

};

class Videocard{
public:
    virtual void display() = 0;
    
};

class Memory{
public:
    virtual void storage() = 0;
    
};

class Computer{
public:
    Computer(CPU* cpu, Videocard* card, Memory* memory){
        this->cpu = cpu;
        this->card = card;
        this->memory = memory;
    }

    void doWork(){
        this->cpu->calculate();
        this->card->display();
        this->memory->storage();
    }

    ~Computer(){
        if(this->cpu != nullptr){
            delete this->cpu;
            this->cpu = nullptr;
        }
        if(this->card != nullptr){
            delete this->card;
            this->card = nullptr;
        }
        if(this->memory != nullptr){
            delete this->memory;
            this->memory = nullptr;
        }
    }

    CPU* cpu;
    Videocard* card;
    Memory* memory;
};

class IntelCPU: public CPU{
public:
    virtual void calculate(){
        cout<<"Intel的CPU开始计算"<<endl;
    }
};

class IntelVideocard: public Videocard{
public:
    virtual void display(){
        cout<<"Intel的显卡开始显示"<<endl;
    }
};

class IntelMemory: public Memory{
public:
    virtual void storage(){
        cout<<"Intel的内存条开始存储"<<endl;
    }
};

class AMDCPU: public CPU{
public:
    virtual void calculate(){
        cout<<"AMD的CPU开始计算"<<endl;
    }
};

class AMDVideocard: public Videocard{
public:
    virtual void display(){
        cout<<"AMD的显卡开始显示"<<endl;
    }
};

class AMDMemory: public Memory{
public:
    virtual void storage(){
        cout<<"AMD的内存条开始存储"<<endl;
    }
};

void test01(){
    // 第一台电脑
    CPU* cpu1 = new IntelCPU();
    Videocard* card1 = new IntelVideocard();
    Memory* memory1 = new IntelMemory();
    Computer* computer1 = new Computer(cpu1, card1, memory1);
    computer1->doWork();
    delete computer1;
    
    // 第二台电脑
    CPU* cpu2 = new IntelCPU();
    Videocard* card2 = new AMDVideocard();
    Memory* memory2 = new AMDMemory();
    Computer* computer2 = new Computer(cpu2, card2, memory2);
    computer2->doWork();
    delete computer2;
}

int main(){
    test01();

    system("pause");
    return 0;
}