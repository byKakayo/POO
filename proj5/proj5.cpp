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
  // Insere v no fim da fila.
  void push(type v);
  // Descarta elemento da frente da fila.
  void pop();
  // Lê valor do elemento da frente da fila.
  type front() const;
  // Verifica se está vazia.
  bool is_empty() const;
};

//Classe de exceção fila vazia
class queue_empty{};

// Insere v na fila.
template <typename type>
void Queue<type>::push(type v) {
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

// Descarta elemento no topo da fila.
// Pré-condição: !is_empty()
template <typename type>
void Queue<type>::pop() {
  if(is_empty()){
    //Exceção
    throw queue_empty{};
  }
  // Passa o _front para o próximo.
  _front = std::move(_front->next);
  // Se esvaziou fila, atualiza _back.
  if (_front.get() == nullptr) {
    _back = nullptr;
  }
}

// Retorna elemento do topo da fila.
// Pré-condição: !is_empty()
template <typename type>
type Queue<type>::front() const {
  if(is_empty()){
    //Exceção
    throw queue_empty{};
  }
  return _front->value;
}

// Verifica se a fila está vazia.
template <typename type>
bool Queue<type>::is_empty() const { return _front.get() == nullptr; }

// Alguns testes simples.
int main(int, char const *[]) {
  Queue<int> my_queue;
  for (int i = 0; i < 4; ++i) {
    my_queue.push(i);
  }
  std::cout << "Primeiro na fila: " << my_queue.front() << std::endl;
  my_queue.pop();
  for (int i = 0; i < 3; ++i) {
    my_queue.push(3 * i);
  }

  std::cout << "Fila atual: ";
  while(true){
    //Tenta retirar da fila
    try {
      auto x = my_queue.front();
      my_queue.pop();
      std::cout << x << " ";
    } catch(queue_empty &e) {
      std::cout << "\nOperação inválida, fila vazia";
      break;
    }
  }
  std::cout << std::endl;
}
