#include <iostream>
#include <memory>
#include <vector>

template <typename type>
class Queue {
  struct Node {
    type value;
    std::unique_ptr<Node> next;
  };

  std::unique_ptr<Node> _front;
  Node *_back{nullptr};

public:
  // Descarta elemento da frente da fila.
  void pop();
  // Lê valor do elemento da frente da fila.
  type front() const;
  // Verifica se está vazia.
  bool is_empty() const;
};

class queue_empty{};

// Descarta elemento no topo da pilha.
// Pré-condição: !is_empty()
template <typename type>
void Queue<type>::pop() {
  if(is_empty()){
    throw queue_empty{};
  }
  // Passa o _front para o próximo.
  _front = std::move(_front->next);
  // Se esvaziou fila, atualiza _back.
  if (_front.get() == nullptr) {
    _back = nullptr;
  }
}

// Retorna elemento do topo da pilha.
// Pré-condição: !is_empty()
template <typename type>
type Queue<type>::front() const {
  if(is_empty()){
    throw queue_empty{};
  }
  return _front->value;
}

// Verifica se a pilha está vazia.
template <typename type>
bool Queue<type>::is_empty() const { return _front.get() == nullptr; }

// Alguns testes simples.
int main(int, char const *[]) {
  Queue<int> my_queue;
  try {
    //my_queue.pop();
    int x = my_queue.front();
  } catch(queue_empty &e) {
    std::cout << "Operação inválida, fila vazia";
  }
  std::cout << std::endl;
}
