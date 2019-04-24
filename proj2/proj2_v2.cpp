#include <bits/stdc++.h>

using namespace std;

//Estrutura do quadrado
struct square {
  string id;
  vector<float> v1;
  vector<float> v2; //Vértice do quadrado oposto ao vértice dado
};

void intersec(square s1, square s2, int flag);

int main() {
  //Criação de um vetor de quadrados
  vector<square> squares;

  //Leitura dos dados do arquivo .dat
  ifstream dat("squares2.dat");
  if (dat.is_open()) {
    string line, id;
    float v1x, v1y, size;
    //Enquanto existirem linhas no arquivo guarda um novo quadrado no vetor
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
  //Percorre o vetor de quadrados e verifica a intersecção de um par de quadrados pela função intersec
  for(int i = 0; i < (int)squares.size(); i++){
    for(int n = i+1; n < (int)squares.size(); n++){
      intersec(squares[i], squares[n], 0);
    }
  }
  return 0;
}

void intersec(square s1, square s2, int flag) {
  float a;
  a = 0.0;
  //Condição de não intersecção
  if((s1.v2[0] <= s2.v1[0] || s2.v2[0] <= s1.v1[0]) || (s1.v2[1] <= s2.v1[1] || s2.v2[1] <= s1.v1[1])) {
    return;
  }else{
    if(s1.v1[0] >= s2.v1[0] && s1.v1[1] >= s2.v1[1] && s2.v2[0] >= s1.v2[0] && s2.v2[1] >= s1.v2[1]){
      cout << "5 ";
      a = (s1.v1[0]- s1.v2[0]) * (s1.v1[1]- s1.v2[1]);
    }else if(s1.v2[0] > s2.v1[0] && s2.v2[1] > s1.v1[1] && s2.v2[0] > s1.v2[0] && s2.v2[1] < s1.v2[1]){
      cout << "1 ";
      a = (s1.v2[0] - s2.v1[0])*(s2.v2[1] - s1.v1[1]);
    }else if(s1.v2[0] > s2.v1[0] && s1.v2[1] > s2.v1[1] && s2.v2[1] > s1.v2[1] && s2.v2[0] > s1.v2[0]){
      cout << "2 ";
      a = (s1.v2[0] - s2.v1[0])*(s1.v2[1] - s2.v1[1]);
    }else if(s1.v1[0] <= s2.v1[0] && s2.v2[0] <= s1.v2[0] && s2.v2[1] > s1.v2[1]){
      cout << "3 ";
      a = (s2.v2[0] - s2.v1[0])*(s1.v2[1] - s2.v1[1]);
    }else if(s1.v1[1] >= s2.v1[1] && s1.v2[1] <= s2.v2[1] && s1.v1[0] < s2.v1[0]){
      cout << "4 ";
      a = (s1.v2[0] - s2.v1[0])*(s1.v2[1] - s1.v1[1]);
    }else{
      if(flag == 0){
        intersec(s2, s1, 1);
      }
      return;
    }
  }
  if(flag == 1){
    cout << s2.id << " intercepts " << s1.id << " with area " << a << "\n";
  }else{
    cout << s1.id << " intercepts " << s2.id << " with area " << a << "\n";
  }
  return;
}
