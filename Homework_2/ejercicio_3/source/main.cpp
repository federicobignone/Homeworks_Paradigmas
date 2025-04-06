#include "../include/complejo.h"
#include "../include/entero.h"
#include "../include/real.h"
#include <iostream>
#include <memory>

void probarOperaciones(const std::string &nombreTipo, Numero *a, Numero *b) {
  std::cout << "\n--- Operaciones con tipo: " << nombreTipo << " ---\n";
  std::cout << "A: " << a->toString() << ", B: " << b->toString() << "\n";

  try {
    std::unique_ptr<Numero> suma(a->suma(b));
    std::cout << "Suma: " << suma->toString() << "\n";
  } catch (const std::exception &e) {
    std::cout << "Suma: ERROR - " << e.what() << "\n";
  }

  try {
    std::unique_ptr<Numero> resta(a->resta(b));
    std::cout << "Resta: " << resta->toString() << "\n";
  } catch (const std::exception &e) {
    std::cout << "Resta: ERROR - " << e.what() << "\n";
  }

  try {
    std::unique_ptr<Numero> multi(a->multiplicacion(b));
    std::cout << "Multiplicación: " << multi->toString() << "\n";
  } catch (const std::exception &e) {
    std::cout << "Multiplicación: ERROR - " << e.what() << "\n";
  }

  try {
    std::unique_ptr<Numero> div(a->division(b));
    std::cout << "División: " << div->toString() << "\n";
  } catch (const std::exception &e) {
    std::cout << "División: ERROR - " << e.what() << "\n";
  }
}

int main() {
  Entero e1(10), e2(2);
  Real r1(5.5), r2(1.1);
  Complejo c1(3.0, 4.0), c2(1.0, -2.0);

  probarOperaciones("Entero", &e1, &e2);
  probarOperaciones("Real", &r1, &r2);
  probarOperaciones("Complejo", &c1, &c2);

  std::cout << "\n--- Pruebas mezclando tipos ---\n";

  try {
    Numero *mezcla1 = r1.suma(&c1);
    std::cout << "Real + Complejo: " << mezcla1->toString() << "\n";
    delete mezcla1;
  } catch (const std::exception &e) {
    std::cout << "Real + Complejo: ERROR - " << e.what() << "\n";
  }

  try {
    Numero *mezcla2 = e1.multiplicacion(&r2);
    std::cout << "Entero * Real: " << mezcla2->toString() << "\n";
    delete mezcla2;
  } catch (const std::exception &e) {
    std::cout << "Entero * Real: ERROR - " << e.what() << "\n";
  }

  try {
    Numero *mezcla3 = c1.division(&e2);
    std::cout << "Complejo / Entero: " << mezcla3->toString() << "\n";
    delete mezcla3;
  } catch (const std::exception &e) {
    std::cout << "Complejo / Entero: ERROR - " << e.what() << "\n";
  }

  std::cout << "\nFin de pruebas.\n";
  return 0;
}
