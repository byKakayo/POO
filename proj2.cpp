#include <bits/stdc++.h>

using namespace std;

struct square {
  string id;
  vector<float> v1;
  vector<float> v2;
};

void intersec(square s1, square s2);

int main() {
  vector<square> squares;
  ifstream dat("squares.dat");
  if (dat.is_open()) {
    string line, id;
    float v1x, v1y, size;
    while (getline(dat, line)) {
      square sq;
      istringstream s(line);
      s >> id >> v1x >> v1y >> size;
      sq.id = id;
      sq.v1.push_back(v1x);
      sq.v1.push_back(v1y);
      sq.v2.push_back(v1x + size);
      sq.v2.push_back(v1y + size);
      squares.push_back(sq);
    }
    dat.close();
  }
  //cout << squares[0].id << squares[0].v1[0] << squares[0].v1[1] << squares[0].v2[0] << squares[0].v2[1] <<
  //squares[0].v3[0] << squares[0].v3[1] << squares[0].v4[0] << squares[0].v4[1];
  intersec(squares[0], squares[1]);
  intersec(squares[1], squares[2]);
  intersec(squares[1], squares[3]);
  intersec(squares[5], squares[4]);
  return 0;
}

void intersec(square s1, square s2) {
  float a;
  if((s1.v2[0] <= s2.v1[0] || s2.v2[0] <= s1.v1[0]) || (s1.v2[1] <= s2.v1[1] || s2.v2[1] <= s1.v1[1])) {
    return;
  }else{
    if(s1.v2[0] < s2.v2[0] && s1.v1[0] > s2.v1[0] && s1.v2[1] < s2.v2[1] && s1.v1[1] > s2.v1[1]){ //s1 dentro de s2
      a = (s1.v1[0]- s1.v2[0]) * (s1.v1[1]- s1.v2[1]);
    }else if(s2.v2[0] < s1.v2[0] && s2.v1[0] > s1.v1[0] && s2.v2[1] < s1.v2[1] && s2.v1[1] > s1.v1[1]){ //s2 dentro de s1
      a = (s2.v1[0]- s2.v2[0]) * (s2.v1[1]- s2.v2[1]);
    }else if(s1.v2[0] > s2.v1[0] && s2.v1[1] < s1.v2[1]){
      a = (s1.v2[0] - s2.v1[0])*(s1.v2[1] - s2.v1[1]);
    }else if(s2.v2[0] > s1.v1[0] && s1.v1[1] < s2.v2[1]){
      a = (s2.v2[0] - s1.v1[0])*(s2.v2[1] - s1.v1[1]);
    }
    //calcular a area da intersec
  }
  //a = 0;
  cout << s1.id << " intercepts " << s2.id << " with area " << a << "\n";
  return;
}
