#include <bits/stdc++.h>

using namespace std;

//Estrutura do quadrado
struct square {
  string id;
  vector<double> v1; //Vértice dado do quadrado
  vector<double> v2; //Vértice do quadrado oposto ao vértice dado
};

void intersec(square s1, square s2, int flag);

int main() {
  //Criação de um vetor de quadrados
  vector<square> squares;

  //Leitura dos dados do arquivo .dat
  ifstream dat("squares.dat");
  if (dat.is_open()) {
    string line, id;
    double v1x, v1y, size;
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
  //intersec(squares[10], squares[12], 0);
  return 0;
}

void intersec(square s1, square s2, int flag) {
  double a, x;
  a = 0.0;
  //Condição de não intersecção
  if((s1.v2[0] <= s2.v1[0] || s2.v2[0] <= s1.v1[0]) || (s1.v2[1] <= s2.v1[1] || s2.v2[1] <= s1.v1[1])) {
    return;
  }else{
    x = s1.v2[0] - s1.v1[0];
    //Condição s1 dentro de s2
    if(s1.v1[0] >= s2.v1[0] && s1.v2[0] <= s2.v2[0] && s1.v1[1] >= s2.v1[1] && s1.v2[1] <= s2.v2[1]){
      a = x *(s1.v2[1] - s1.v1[1]);
    }else if(s2.v2[0] > s1.v2[0] && s2.v1[0] > s1.v1[0]){ //Condição de s2 a direita de s1
      x = s1.v2[0] - s2.v1[0];
      if(s2.v1[1] > s1.v1[1] && s2.v2[1] > s1.v2[1]){ //Condição de s2 superior a s1
        a = x * (s1.v2[1] - s2.v1[1]);
      }else if(s2.v1[1] < s1.v1[1]){ //Condição do vértice inferior de s2 abaixo do vértice inferior de s1
        if(s1.v2[1] > s2.v2[1]){ //Condição de s1 cuperior a s2
          a = x * (s2.v2[1] - s1.v1[1]);
        }else{ //s1 interno a s2 lateralmente
          a = x * (s1.v2[1] - s1.v1[1]);
        }
      }else if(s2.v2[1] <= s1.v2[1]){ // Condição de s2 interno a s1 lateralmente
        a = x * (s2.v2[1] - s2.v1[1]);
      }
    }else if(s2.v2[1] > s1.v2[1] && s2.v2[0] <= s1.v2[0] && s1.v1[0] <= s2.v1[0]){//Condição de s2 superiormente interno a s1
      a = (s2.v2[0] - s2.v1[0])*(s1.v2[1] - s2.v1[1]);
    }else if(s2.v2[1] > s1.v2[1] && s1.v1[0] > s2.v1[0] && s1.v2[0] < s2.v2[0]){//Condição de s1 inferiormente interno a s2
      a = x * (s1.v2[1] - s2.v1[1]);
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
