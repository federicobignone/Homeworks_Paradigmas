#ifndef ENTERO_H
#define ENTERO_H

#include "numero.h"
#include <string>

class Entero : public Numero {
private:
  int valor;

public:
  Entero(int v);

  Numero *suma(Numero *otro) const override;
  Numero *resta(Numero *otro) const override;
  Numero *multiplicacion(Numero *otro) const override;
  Numero *division(Numero *otro) const override;

  std::string toString() const override;

  int getValor() const;
};

#endif
