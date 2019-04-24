#include <bits/stdc++.h>

class Limited_Counter {
    int val_min;
    int val_max;
    int val;
  public:
    Limited_Counter(int min = 0, int max): val_min(min), val_max(max), val(min) {}
    void up();
    void down();
    void up_by(int x);
    void down_by(int x);
    int value() const { return val; }
};
