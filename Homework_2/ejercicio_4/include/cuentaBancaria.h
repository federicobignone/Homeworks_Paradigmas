#ifndef CUENTA_BANCARIA_H
#define CUENTA_BANCARIA_H

#include <iostream>
#include <string>

/*
 Justificación de especificadores de acceso:

 - balance y titularCuenta (protected):
   Permiten que las subclases accedan directamente a estos datos sin usar
 getters, manteniendo flexibilidad para que métodos como retirar() o
 mostrarInfo() puedan usarlos directamente. Se evita el uso de private para
 favorecer extensibilidad sin romper encapsulamiento interno.

 - depositar(double): public
   Método común a todas las cuentas, puede usarse desde código externo (como el
 main).

 - retirar(double) y mostrarInfo(): public y virtual puro
   Fuerzan a las subclases a implementar su propia lógica de retiro y
 visualización, cumpliendo con polimorfismo. Son públicos para ser utilizados
 desde cualquier parte del programa.

 - getBalance(): public
   Permite acceder al balance de forma segura (por ejemplo desde
 CuentaCorriente) sin romper encapsulamiento.
*/

class CuentaBancaria {
protected:
  double balance;            // protected: accesible por subclases
  std::string titularCuenta; // protected: accesible por subclases

public:
  CuentaBancaria(const std::string &titular, double saldoInicial);
  virtual ~CuentaBancaria() = default;

  void depositar(double monto); // público: debe ser usable desde el main
  virtual bool retirar(
      double monto) = 0; // virtual puro: implementación específica de cada tipo
  virtual void
  mostrarInfo() const = 0; // virtual puro: comportamiento específico por tipo

  double getBalance() const { return balance; } // getter público seguro
};

// Implementación inline simple para no generar CuentaBancaria.cpp
inline CuentaBancaria::CuentaBancaria(const std::string &titular,
                                      double saldoInicial)
    : balance(saldoInicial), titularCuenta(titular) {} // orden corregido

inline void CuentaBancaria::depositar(double monto) { balance += monto; }

#endif