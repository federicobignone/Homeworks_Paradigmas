#include "../include/cajaDeAhorro.h"
#include "../include/cuentaCorriente.h"
#include <iostream>

int main() {
  std::cout << "--- Creación de cuentas ---\n";
  CajaDeAhorro caja("Federico", 500);
  CuentaCorriente cc("Federico", 200, &caja);

  std::cout << "\n--- Depósitos ---\n";
  caja.depositar(100);
  cc.depositar(50);

  std::cout << "\n--- Retiros ---\n";
  std::cout << "Retirar $150 de cuenta corriente: ";
  if (cc.retirar(150))
    std::cout << "Éxito\n";
  else
    std::cout << "Fallo\n";

  std::cout << "Retirar $200 de cuenta corriente (requiere usar caja): ";
  if (cc.retirar(200))
    std::cout << "Éxito\n";
  else
    std::cout << "Fallo\n";

  std::cout << "Retirar $9999 de cuenta corriente (excede ambas): ";
  if (cc.retirar(9999))
    std::cout << "Éxito\n";
  else
    std::cout << "Fallo\n";

  std::cout << "\n--- Mostrar info (Caja de Ahorro) ---\n";
  caja.mostrarInfo();
  caja.mostrarInfo();
  caja.mostrarInfo(); // se aplicará penalidad aca

  std::cout << "\n--- Mostrar info (Cuenta Corriente) ---\n";
  cc.mostrarInfo();

  return 0;
}
