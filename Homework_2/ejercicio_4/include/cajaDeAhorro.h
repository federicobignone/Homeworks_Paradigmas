#ifndef CAJA_DE_AHORRO_H
#define CAJA_DE_AHORRO_H

#include "cuentaBancaria.h"

class CajaDeAhorro : public CuentaBancaria {
private:
  mutable int contadorConsultas = 0; // mutable para modificarlo en método const

public:
  CajaDeAhorro(const std::string &titular, double saldoInicial);

  bool retirar(double monto) override;
  void mostrarInfo() const override;
};

#endif
