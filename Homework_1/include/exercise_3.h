#ifndef EXERCISE_3_H
#define EXERCISE_3_H

#include <memory>

// Nodo de la lista (solo int y puntero al siguiente nodo)
struct Node {
  int value;
  std::unique_ptr<Node> next;

  Node(int val) : value(val), next(nullptr) {}
};

// Crea un nuevo nodo
std::unique_ptr<Node> create_node(int value);

// Inserta al frente de la lista
void push_front(std::unique_ptr<Node> &head, int value);

// Inserta al final de la lista
void push_back(std::unique_ptr<Node> &head, int value);

// Inserta en posición 'pos' (0-indexed)
void insert(std::unique_ptr<Node> &head, int pos, int value);

// Borra el nodo en posición 'pos' (0-indexed)
void erase(std::unique_ptr<Node> &head, int pos);

// Imprime la lista
void print_list(const std::unique_ptr<Node> &head);

#endif // EXERCISE_3_H