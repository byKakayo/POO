#include <iostream>
#include "limited_counter.hpp"


void test_value(std::string test, int got, int expected) {
  if (got == expected) {
    std::cout << "OK " << test << std::endl;
  }
  else {
    std::cerr << "ERROR " << test
              << ": Got " << got << " but expected " << expected << std::endl;
  }
}

int main(int, char const *[]) {
  Limited_Counter c1(1, 10);
  test_value("initial value", c1.value(), 1);
  c1.up();
  test_value("up by one", c1.value(), 2);
  c1.down();
  test_value("down by one", c1.value(), 1);
  c1.up_by(5);
  test_value("up by value in limit", c1.value(), 6);
  c1.down_by(3);
  test_value("down by value in limit", c1.value(), 3);
  c1.up_by(-2);
  test_value("up by negative value in limit", c1.value(), 1);
  c1.down_by(-7);
  test_value("dowm by negative value in limit", c1.value(), 8);
  for (int i = 0; i < 100; ++i) {
    c1.up();
  }
  test_value("up out of limit", c1.value(), 10);
  for (int i = 0; i < 100; ++i) {
    c1.down();
  }
  test_value("down out of limit", c1.value(), 1);
  c1.up_by(37);
  test_value("up by out of limit", c1.value(), 10);
  c1.down_by(130);
  test_value("down by out of limit", c1.value(), 1);
  c1.up_by(-100);
  test_value("up by negative out of limit", c1.value(), 1);
  c1.down_by(-300);
  test_value("down by negative out of limit", c1.value(), 10);

  Limited_Counter c2(15);
  test_value("default initial value", c2.value(), 0);
  c2.down();
  test_value("default minimum value", c2.value(), 0);
}
