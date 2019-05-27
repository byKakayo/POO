#include "limited_counter.hpp"
#include <iostream>

void test_value(std::string test, int got, int expected) {
  if (got == expected) {
    std::cout << "OK " << test << std::endl;
  } else {
    std::cerr << "ERROR " << test << ": Got " << got << " but expected "
              << expected << std::endl;
  }
}

int main(int, char const *[]) {
  Limited_Counter c1(1, 10);
  test_value("initial value", c1.value(), 1);
  ++c1;
  test_value("up by one", c1.value(), 2);
  --c1;
  test_value("down by one", c1.value(), 1);
  c1 += 5;
  test_value("up by value in limit", c1.value(), 6);
  c1 -= 3;
  test_value("down by value in limit", c1.value(), 3);
  c1 += -2;
  test_value("up by negative value in limit", c1.value(), 1);
  c1 -= -7;
  test_value("dowm by negative value in limit", c1.value(), 8);
  for (int i = 0; i < 100; ++i) {
    c1++;
  }
  test_value("up out of limit", c1.value(), 10);
  for (int i = 0; i < 100; ++i) {
    c1--;
  }
  test_value("down out of limit", c1.value(), 1);
  c1 += 37;
  test_value("up by out of limit", c1.value(), 10);
  c1 -= 130;
  test_value("down by out of limit", c1.value(), 1);
  c1 += -100;
  test_value("up by negative out of limit", c1.value(), 1);
  c1 -= -300;
  test_value("down by negative out of limit", c1.value(), 10);

  Limited_Counter c2(15);
  test_value("default initial value", c2.value(), 0);
  --c2;
  test_value("default minimum value", c2.value(), 0);
  test_value("pre increment result", (++c2).value(), 1);
  test_value("pre increment effect", c2.value(), 1);
  test_value("pos increment result", (c2++).value(), 1);
  test_value("pos increment effect", c2.value(), 2);
  test_value("pre decrement result", (--c2).value(), 1);
  test_value("pre decrement effect", c2.value(), 1);
  test_value("pos decrement result", (c2--).value(), 1);
  test_value("pos decrement effect", c2.value(), 0);
  test_value("+= result", (c2 += 5).value(), 5);
  test_value("-= result", (c2 -= 2).value(), 3);
  ++(c2 += 3);
  test_value("+= return reference", c2.value(), 7);
  --(c2 -= 2);
  test_value("-= return reference", c2.value(), 4);
}
