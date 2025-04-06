#ifndef REAL_H
#define REAL_H

#include "numero.h"
#include <string>

class Real : public Numero {
private:
  double valor;

public:
  Real(double v);

  Numero *suma(Numero *otro) const override;
  Numero *resta(Numero *otro) const override;
  Numero *multiplicacion(Numero *otro) const override;
  Numero *division(Numero *otro) const override;

  std::string toString() const override;

  double getValor() const;
};

#endif
