#include <iostream>
#include <string>

int main(int argc, char const *argv[]) {
  std::string nome;
  std::int idade;
  std::cout << "Entrada:" << '\n';
  std::cin >> nome;
  std::cout << nome << '\n';
  return 0;
}

//using namespace std; -> não é necessário do uso do std:: antes do comandos
