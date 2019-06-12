// Um código artifial demonstrando o uso de exceções.
// Exceções são usadas para indicar a ocorrência de uma situação "excepcional",
// isto e, uma situação que não faz parte do fluxo normal de execução do
// programa mas que em princípio permitem que o programa continue depois de
// tomar certas previdências.

// Elas funcionam dividindo o gerenciamento do erro em duas partes, detecção e
// tratamento:
// 1. Quando o erro é detectado, sinalizamos a presença do erro com o uso de
//    um throw de uma exceção.
// 2. No local onde sabemos fazer o tratamento, usamos uma construção try/catch
//    para indicar como lidar com o erro.

#include <iostream>

// Cada tipo de erro deve ser associado com um tipo de dados.
// Geralmente usados struct ou class.

// Aqui definimos um erro para uma escolha de opção inválida.
// O erro carrega uma informação sobre o valor errado (isto é opcional).
struct EscolhaInvalida {
  int escolhido;
};

// Outro tipo de erro que teremos é a informação de um valor fora de faixa,
// que representaremos pelo erro ValorInvalido:
struct ValorInvalido {
  int val;
};

// Dos erros do tipo valor inválido, temos dois subtipos: um número que deveria
// ser não-negativo mas é negativo é um deles:
struct NumeroNegativo : public ValorInvalido {};

// Outro valor inválido é quando queremos uma faixa específica, mas o valor
// fornecido é fora da faixa. Indicamos isso pela exceção ForaDaFaixa:
struct ForaDaFaixa : public ValorInvalido {};

// No código abaixo, note como ao realizar um throw, a execução da função é
// interrompida, e a execução vai para o código do catch correspondente ao
// tipo da exceção lançada.

// Esta função quer um valor não-negativo no argumento.
// Se passa um negativo, ela não sabe o que fazer, e simplesmente lança uma
// exceção.
void f0(int x) {
  std::cout << "Em f0\n";
  if (x < 0) {
    // Temos um valor negativo, então vamos lançar uma exceção NumeroNegativo
    // e deixar o restante do código que fez esta chamada cuidar do problema.
    throw NumeroNegativo{{x}};
  }
  std::cout << "Saindo de f0\n";
}

// Esta função quer um valor dentro da faixa 0 a 10 (inclusive).
// Se o argumento está fora da faixa, lança uma exceção ForaDaFaixa.
void f1(int x) {
  std::cout << "Em f1\n";
  if (x < 0 || x > 10) {
    // Valor errado. Lança exceção.
    throw ForaDaFaixa{{x}};
  }
  std::cout << "Saindo de f1\n";
}

void processa(int escolha) {
  switch (escolha) {
  case 0:
    std::cout << "Lidando com 0\n";
    std::cout << "Valor para a f0: ";
    int x;
    std::cin >> x;
    // A função f0 pode lançar exceção, e este código sabe lidar com isso,
    // então colocamos a chamada entre try/catch
    try {
      // Tenta executar f0(x)
      f0(x);
      // Se funcionou, vai direto para depois dos catch.
    } catch (NumeroNegativo &e) {
      // Se f0 lançou (throw) exceção NumeroNegativo, entra neste código.
      std::cout << "f0 falhou por numero negativo: " << e.val << std::endl;
    }
    break;
  case 1:
    std::cout << "Lidando com 0\n";
    std::cout << "Valor para a f1: ";
    int y;
    std::cin >> y;
    // Função f1 pode lançar exceção, mas este código não sabe lidar com o
    // problema, então ele não usa try/catch e deixa o código do main lidar
    // com isso.
    f1(y);
    break;
  default:
    // Se o usuário escolheu um valor diferente de 0 ou 1, não sabemos o que
    // fazer, então fazemos um throw e deixamos o main cuidar disso.
    throw EscolhaInvalida{escolha};
  }
}

int main(int, char const *[]) {
  std::cout << "Escolha um valor inteiro [0 ou 1]: ";
  int escolha;
  std::cin >> escolha;
  // O processa pode lançar exceções, então chamamos dentro de try/catch
  try {
    processa(escolha);
  } catch (EscolhaInvalida &e) {
    // Uma exceção é a EscolhaInvalida (escolha != 0 ou 1) na chamada.
    std::cout << "Que parte do [0 ou 1] voce nao entendeu?\n";
    std::cout << "Voce escolheu " << e.escolhido << std::endl;
    return 1;
  } catch (ForaDaFaixa &e) {
    // Outro erro é se um valor fora da faixa foi passado para f1 por
    // processa. Como f1 faz um throw e processa não usa try/catch para ele,
    // a exceção é entregue para o try da chamada de processa, e acaba aqui.
    std::cout << "Valor " << e.val << " esta fora da faixa\n";
  }
  // Outra opção é captura (catch) pela classe base de ForaDaFaixa.
  // Isto é especialmente útil quando queremos fazer o mesmo tipo de tratamento
  // para diversos tipos de erro relacionados.
  // } catch (ValorInvalido &e) {
  //   std::cout << "Valor " << e.val << " é inválido\n";
  // }
  std::cout << "Acabou!\n";
  return 0;
}
