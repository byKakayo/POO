#include <bits/stdc++.h>

using namespace std;


int main() {
  ifstream file("testefile.dat");
  if (file.is_open()) {
    std::string line;
    while (getline(file, line)) {
        // using printf() in all tests for consistency
        printf("%s", line.c_str());
        cout << "\n";
    }
    file.close();
  }
  return 0;
}
