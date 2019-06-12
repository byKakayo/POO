#include <iostream>
#include <memory>
#include <vector>

/*******************************************************************************
 * ATENÇÃO:
 * 1. Se precisar uma fila, use std::queue, ao invés de implementar a sua.
 * 2. Esta solução impede a cópia de filas (por cópia ou atribuição), pois um
 *    std::unique_ptr não pode ser copiado. Isto é suficiente para o nosso caso,
 *    então vamos deixar assim. Se necessário. deve-se implementar construtor de
 *    cópia e operador de atribuição.
 */

// Representa uma Fila ou FIFO (first in first out), com operações de inserção
// (push), leitura do valor na frente (front), retirada (pop) e verificação se
// está vazia (is_emty).
class Queue {
  struct Node {
    int value;
    std::unique_ptr<Node> next;
  };

  std::unique_ptr<Node> _front;
  Node *_back{nullptr};

public:
  // Insere v no fim da fila.
  void push(int v);
  // Descarta elemento da frente da fila.
  void pop();
  // Lê valor do elemento da frente da fila.
  int front() const;
  // Verifica se está vazia.
  bool is_empty() const;
};

// Insere v na pilha.
void Queue::push(int v) {
  Node *new_node = new Node{v, nullptr};
  if (_back) {
    // Já tem algo na fila. Põe no fim.
    _back->next.reset(new_node);
  } else {
    // Primeiro valor inserido. Ajusta _front.
    _front.reset(new_node);
  }
  // Em qualquer caso, _back aponta para o novo nó.
  _back = new_node;
}

// Descarta elemento no topo da pilha.
// Pré-condição: !is_empty()
void Queue::pop() {
  // Passa o _front para o próximo.
  _front = std::move(_front->next);
  // Se esvaziou fila, atualiza _back.
  if (_front.get() == nullptr) {
    _back = nullptr;
  }
}

// Retorna elemento do topo da pilha.
// Pré-condição: !is_empty()
int Queue::front() const { return _front->value; }

// Verifica se a pilha está vazia.
bool Queue::is_empty() const { return _front.get() == nullptr; }

// Alguns testes simples.
int main(int, char const *[]) {
  Queue my_queue;
  for (int i = 0; i < 4; ++i) {
    my_queue.push(i);
  }
  std::cout << "Primeiro na fila: " << my_queue.front() << std::endl;
  my_queue.pop();
  for (int i = 0; i < 3; ++i) {
    my_queue.push(3 * i);
  }

  std::cout << "Fila atual: ";
  while (!my_queue.is_empty()) {
    auto x = my_queue.front();
    my_queue.pop();
    std::cout << x << " ";
  }
  std::cout << std::endl;
}
