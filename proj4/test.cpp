#include "limited_counter.hpp"
#include <iostream>

int main(){
  Limited_Counter c1(1, 10);
  ++c1;
  c1++;
  std::cout << c1.value() << "\n";
  --c1;
  c1--;
  std::cout << c1.value() << "\n";
  c1 += 1;
  std::cout << c1.value() << "\n";
  c1 -= 1;
  std::cout << c1.value() << "\n";
}
