#include <iostream>
// using namespace std;

// alignas 生效的情况

struct Info {
  uint8_t a;
  uint16_t b;
  uint8_t c;
};

struct alignas(4) Info2 {
  uint8_t a;
  uint16_t b;
  uint8_t c;
};

int main(){
    std::cout << sizeof(Info) << std::endl;   // 6  2 + 2 + 2
    std::cout << alignof(Info) << std::endl;  // 2

    std::cout << sizeof(Info2) << std::endl;   // 8  4 + 4
    std::cout << alignof(Info2) << std::endl;  // 4

    system("pause");
}