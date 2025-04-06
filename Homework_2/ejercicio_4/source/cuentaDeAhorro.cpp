#include "../include/cajaDeAhorro.h"
#include <iostream>

CajaDeAhorro::CajaDeAhorro(const std::string &titular, double saldoInicial)
    : CuentaBancaria(titular, saldoInicial) {}

bool CajaDeAhorro::retirar(double monto) {
  if (monto <= balance) {
    balance -= monto;
    return true;
  } else {
    std::cout << "Fondos insuficientes en Caja de Ahorro.\n";
    return false;
  }
}

void CajaDeAhorro::mostrarInfo() const {
  contadorConsultas++;
  std::cout << "Titular: " << titularCuenta << "\n";
  std::cout << "Tipo: Caja de Ahorro\n";
  std::cout << "Balance: $" << balance << "\n";

  if (contadorConsultas > 2) {
    std::cout << "(Se descontaron $20 por exceso de consultas)\n";
    const_cast<CajaDeAhorro *>(this)->balance -= 20;
  }
}
