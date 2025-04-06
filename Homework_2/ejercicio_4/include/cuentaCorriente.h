#ifndef CUENTA_CORRIENTE_H
#define CUENTA_CORRIENTE_H

#include "cajaDeAhorro.h"
#include "cuentaBancaria.h"

class CuentaCorriente : public CuentaBancaria {
private:
  CajaDeAhorro *cajaVinculada; // puntero a caja de ahorro asociada

public:
  CuentaCorriente(const std::string &titular, double saldoInicial,
                  CajaDeAhorro *vinculada);

  bool retirar(double monto) override;
  void mostrarInfo() const override;

  friend class CajaDeAhorro; // permite a CajaDeAhorro acceder a sus miembros
                             // privados si es necesario
};

#endif
