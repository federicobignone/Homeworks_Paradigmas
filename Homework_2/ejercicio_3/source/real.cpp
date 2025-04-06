#include "../include/real.h"
#include "../include/complejo.h"
#include "../include/entero.h"
#include <iomanip>
#include <sstream>
#include <stdexcept>
#include <typeinfo>

Real::Real(double v) : valor(v) {}

double Real::getValor() const { return valor; }

Numero *Real::suma(Numero *otro) const {
  if (auto r = dynamic_cast<Real *>(otro)) {
    return new Real(this->valor + r->getValor());
  } else if (auto e = dynamic_cast<Entero *>(otro)) {
    return new Real(this->valor + e->getValor());
  } else if (auto c = dynamic_cast<Complejo *>(otro)) {
    return new Complejo(this->valor + c->getReal(), c->getImag());
  }
  throw std::invalid_argument("Tipo incompatible para suma con Real.");
}

Numero *Real::resta(Numero *otro) const {
  if (auto r = dynamic_cast<Real *>(otro)) {
    return new Real(this->valor - r->getValor());
  } else if (auto e = dynamic_cast<Entero *>(otro)) {
    return new Real(this->valor - e->getValor());
  } else if (auto c = dynamic_cast<Complejo *>(otro)) {
    return new Complejo(this->valor - c->getReal(), -c->getImag());
  }
  throw std::invalid_argument("Tipo incompatible para resta con Real.");
}

Numero *Real::multiplicacion(Numero *otro) const {
  if (auto r = dynamic_cast<Real *>(otro)) {
    return new Real(this->valor * r->getValor());
  } else if (auto e = dynamic_cast<Entero *>(otro)) {
    return new Real(this->valor * e->getValor());
  } else if (auto c = dynamic_cast<Complejo *>(otro)) {
    double real = this->valor * c->getReal();
    double imag = this->valor * c->getImag();
    return new Complejo(real, imag);
  }
  throw std::invalid_argument(
      "Tipo incompatible para multiplicación con Real.");
}

Numero *Real::division(Numero *otro) const {
  if (auto r = dynamic_cast<Real *>(otro)) {
    if (r->getValor() == 0.0)
      throw std::domain_error("División por cero.");
    return new Real(this->valor / r->getValor());
  } else if (auto e = dynamic_cast<Entero *>(otro)) {
    if (e->getValor() == 0)
      throw std::domain_error("División por cero.");
    return new Real(this->valor / e->getValor());
  } else if (auto c = dynamic_cast<Complejo *>(otro)) {
    double a = this->valor;
    double d = c->getReal() * c->getReal() + c->getImag() * c->getImag();
    if (d == 0.0)
      throw std::domain_error("División por cero complejo.");
    double real = (a * c->getReal()) / d;
    double imag = (-a * c->getImag()) / d;
    return new Complejo(real, imag);
  }
  throw std::invalid_argument("Tipo incompatible para división con Real.");
}

std::string Real::toString() const {
  std::ostringstream oss;
  oss << std::fixed << std::setprecision(2) << valor;
  return oss.str();
}
