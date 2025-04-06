#ifndef NUMERO_H
#define NUMERO_H

#include <string>

class Numero {
public:
  virtual ~Numero() = default;

  virtual Numero *suma(Numero *otro) const = 0;
  virtual Numero *resta(Numero *otro) const = 0;
  virtual Numero *multiplicacion(Numero *otro) const = 0;
  virtual Numero *division(Numero *otro) const = 0; // opcional pero incluimos

  virtual std::string toString() const = 0;
};

#endif
