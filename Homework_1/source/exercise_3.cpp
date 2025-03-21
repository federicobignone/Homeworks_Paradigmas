#include "../include/exercise_3.h"
#include <iostream>
// Se usan unique_ptr para evitar problemas de dependencia cíclica
// Crea un nodo nuevo
std::unique_ptr<Node> create_node(int value) {
  return std::make_unique<Node>(value);
}

// Inserta al frente
void push_front(std::unique_ptr<Node> &head, int value) {
  auto new_node = create_node(value);
  new_node->next = std::move(head);
  head = std::move(new_node);
}

// Inserta al final
void push_back(std::unique_ptr<Node> &head, int value) {
  auto new_node = create_node(value);
  if (!head) {
    head = std::move(new_node);
    return;
  }

  Node *current = head.get();
  while (current->next) {
    current = current->next.get();
  }

  current->next = std::move(new_node);
}

// Inserta en una posición específica (0-indexed)
void insert(std::unique_ptr<Node> &head, int pos, int value) {
  if (pos <= 0 || !head) {
    push_front(head, value);
    return;
  }

  Node *current = head.get();
  int index = 0;
  while (current->next && index < pos - 1) {
    current = current->next.get();
    index++;
  }

  auto new_node = create_node(value);
  new_node->next = std::move(current->next);
  current->next = std::move(new_node);
}

// Elimina el nodo en una posición específica
void erase(std::unique_ptr<Node> &head, int pos) {
  if (!head)
    return;

  if (pos == 0) {
    head = std::move(head->next);
    return;
  }

  Node *current = head.get();
  int index = 0;
  while (current->next && index < pos - 1) {
    current = current->next.get();
    index++;
  }

  if (current->next) {
    current->next = std::move(current->next->next);
  }
}

// Imprime la lista
void print_list(const std::unique_ptr<Node> &head) {
  const Node *current = head.get(); // Puntero constante para no modificar head
  std::cout << "[ ";
  while (current) {
    std::cout << current->value << " ";
    current = current->next.get();
  }
  std::cout << "]\n";
}

// Función main para testear todo
int main() {
  std::unique_ptr<Node> head = nullptr;

  std::cout << "Inicializando lista...\n";
  print_list(head);

  std::cout << "Agregando 3 al frente\n";
  push_front(head, 3);
  print_list(head);

  std::cout << "Agregando 2 al frente\n";
  push_front(head, 2);
  print_list(head);

  std::cout << "Agregando 4 al final\n";
  push_back(head, 4);
  print_list(head);

  std::cout << "Insertando 10 en posición 1\n";
  insert(head, 1, 10);
  print_list(head);

  std::cout << "Insertando 0 en posición 0 (al frente)\n";
  insert(head, 0, 0);
  print_list(head);

  std::cout << "Eliminando nodo en posición 2\n";
  erase(head, 2);
  print_list(head);

  std::cout << "Eliminando nodo en posición 0 (frente)\n";
  erase(head, 0);
  print_list(head);

  std::cout << "Eliminando nodo en posición 10 (fuera de rango)\n";
  erase(head, 10); // No hace nada
  print_list(head);

  std::cout << "Pruebas completadas.\n";
  return 0;
}
