#include "../include/cuentaCorriente.h"
#include <iostream>

CuentaCorriente::CuentaCorriente(const std::string &titular,
                                 double saldoInicial, CajaDeAhorro *vinculada)
    : CuentaBancaria(titular, saldoInicial), cajaVinculada(vinculada) {}

bool CuentaCorriente::retirar(double monto) {
  if (monto <= balance) {
    balance -= monto;
    return true;
  } else if (cajaVinculada &&
             (balance + cajaVinculada->getBalance() >= monto)) {
    double faltante = monto - balance;
    balance = 0;
    if (!cajaVinculada->retirar(faltante)) {
      std::cout << "Error al retirar de la caja vinculada.\n";
      return false;
    }
    return true;
  } else {
    std::cout << "La cuenta no posee dinero suficiente (ni en la cuenta "
                 "vinculada).\n";
    return false;
  }
}

void CuentaCorriente::mostrarInfo() const {
  std::cout << "Titular: " << titularCuenta << "\n";
  std::cout << "Tipo: Cuenta Corriente\n";
  std::cout << "Balance: $" << balance << "\n";
  if (cajaVinculada) {
    std::cout << "Balance Caja Vinculada: $" << cajaVinculada->getBalance()
              << "\n";
  }
}
