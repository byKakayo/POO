#include <bits/stdc++.h>

#define nmax 100000 //Define até qual valor será testada a maior sequência
//Dá ruim no 113383
using namespace std;

int collatz(int n){ //Função com a regra da sequência de collatz
  if(n%2 == 0){     //Se n for par
    n = n/2;
  }else{            //Se n for ímpar
    n = 3*n+1;
  }
  return n;
}

int main() {
  int count,p,n,nElem; //Inicializa as variáveis
  count = 1;           //Variável responsável por contar quantos elementos existem na sequência
  p = 0;               //Variável responsável por armazenar o número atual com a maior sequência
  nElem = 0;           //Variável responsável por armazenar o valor atual da maior sequência
  for(int i = 1; i < nmax; i++) { //Percorre os valores de 1 até o valor definido por nmax
    n = i;
    while(n !=1){                 //Chama a função que calcula o próximo valor da sequência de collatz até que chegue a 1
      n = collatz(n);             //Atualiza o número da sequência
      count++;                    //Adiciona 1 ao contador a cada chamada da função
    }
    if(count > nElem) {           //Se a quantidade de elementos da sequência for maior que o valor guardado ...
      nElem = count;              //Atualiza o valor da maior sequência
      p = i;                      //Atualiza o número cuja sequência seja maior
    }
    count = 1;                    //Define o contador para a sequência do próximo número
  }
  cout << "Número de maior sequência entre 1 e 100.000: " << p << "\n";
  cout << "Quantidade de números na sequência: " << nElem << "\n";
}
