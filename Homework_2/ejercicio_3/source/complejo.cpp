#include "../include/complejo.h"
#include "../include/entero.h"
#include "../include/real.h"
#include <iomanip>
#include <sstream>
#include <stdexcept>
#include <typeinfo>

Complejo::Complejo(double real, double imag)
    : parteReal(real), parteImaginaria(imag) {}

double Complejo::getReal() const { return parteReal; }

double Complejo::getImag() const { return parteImaginaria; }

Numero *Complejo::suma(Numero *otro) const {
  if (auto c = dynamic_cast<Complejo *>(otro)) {
    return new Complejo(parteReal + c->getReal(),
                        parteImaginaria + c->getImag());
  } else if (auto r = dynamic_cast<Real *>(otro)) {
    return new Complejo(parteReal + r->getValor(), parteImaginaria);
  } else if (auto e = dynamic_cast<Entero *>(otro)) {
    return new Complejo(parteReal + e->getValor(), parteImaginaria);
  }
  throw std::invalid_argument("Tipo incompatible para suma con Complejo.");
}

Numero *Complejo::resta(Numero *otro) const {
  if (auto c = dynamic_cast<Complejo *>(otro)) {
    return new Complejo(parteReal - c->getReal(),
                        parteImaginaria - c->getImag());
  } else if (auto r = dynamic_cast<Real *>(otro)) {
    return new Complejo(parteReal - r->getValor(), parteImaginaria);
  } else if (auto e = dynamic_cast<Entero *>(otro)) {
    return new Complejo(parteReal - e->getValor(), parteImaginaria);
  }
  throw std::invalid_argument("Tipo incompatible para resta con Complejo.");
}

Numero *Complejo::multiplicacion(Numero *otro) const {
  if (auto c = dynamic_cast<Complejo *>(otro)) {
    double a = parteReal, b = parteImaginaria;
    double x = c->getReal(), y = c->getImag();
    return new Complejo(a * x - b * y, a * y + b * x);
  } else if (auto r = dynamic_cast<Real *>(otro)) {
    return new Complejo(parteReal * r->getValor(),
                        parteImaginaria * r->getValor());
  } else if (auto e = dynamic_cast<Entero *>(otro)) {
    return new Complejo(parteReal * e->getValor(),
                        parteImaginaria * e->getValor());
  }
  throw std::invalid_argument(
      "Tipo incompatible para multiplicación con Complejo.");
}

Numero *Complejo::division(Numero *otro) const {
  if (auto c = dynamic_cast<Complejo *>(otro)) {
    double a = parteReal, b = parteImaginaria;
    double x = c->getReal(), y = c->getImag();
    double divisor = x * x + y * y;
    if (divisor == 0.0)
      throw std::domain_error("División por cero complejo.");
    double real = (a * x + b * y) / divisor;
    double imag = (b * x - a * y) / divisor;
    return new Complejo(real, imag);
  } else if (auto r = dynamic_cast<Real *>(otro)) {
    if (r->getValor() == 0.0)
      throw std::domain_error("División por cero real.");
    return new Complejo(parteReal / r->getValor(),
                        parteImaginaria / r->getValor());
  } else if (auto e = dynamic_cast<Entero *>(otro)) {
    if (e->getValor() == 0)
      throw std::domain_error("División por cero entero.");
    return new Complejo(parteReal / e->getValor(),
                        parteImaginaria / e->getValor());
  }
  throw std::invalid_argument("Tipo incompatible para división con Complejo.");
}

std::string Complejo::toString() const {
  std::ostringstream oss;
  oss << std::fixed << std::setprecision(2) << parteReal
      << (parteImaginaria >= 0 ? "+" : "") << parteImaginaria << "i";
  return oss.str();
}
