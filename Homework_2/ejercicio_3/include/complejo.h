#ifndef COMPLEJO_H
#define COMPLEJO_H

#include "numero.h"
#include <string>

class Complejo : public Numero {
private:
  double parteReal;
  double parteImaginaria;

public:
  Complejo(double real, double imag);

  Numero *suma(Numero *otro) const override;
  Numero *resta(Numero *otro) const override;
  Numero *multiplicacion(Numero *otro) const override;
  Numero *division(Numero *otro) const override;

  std::string toString() const override;

  double getReal() const;
  double getImag() const;
};

#endif
