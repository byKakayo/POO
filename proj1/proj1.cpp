#include <bits/stdc++.h>

using namespace std;

int collatz(int n, vector<int>* v) {
  v->push_back(n);
  if(n%2 == 0){
    n = n/2;
  }else{
    n = 3*n+1;
  }
  while(n !=1){
    n = collatz(n, v);
  }
  return n;
}

int main() {
  int n;
  vector<int> v;
  cin >> n;
  n = collatz(n, &v);
  v.push_back(n);
  for (int x : v){
    cout << x << " ";
  }
  cout << "\n";
  return 0;
}
