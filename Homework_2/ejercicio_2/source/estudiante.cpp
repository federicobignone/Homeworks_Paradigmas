#include "../include/estudiante.h"
#include <iomanip>
#include <numeric>

Estudiante::Estudiante(const std::string &nombre, int legajo)
    : nombreCompleto(nombre), legajo(legajo) {}

std::string Estudiante::getNombre() const { return nombreCompleto; }

int Estudiante::getLegajo() const { return legajo; }

void Estudiante::agregarNota(const std::string &curso, float nota) {
  cursosYNotas[curso] = nota;
}

float Estudiante::getPromedioGeneral() const {
  if (cursosYNotas.empty())
    return 0.0f;

  float suma = 0.0f;
  for (const auto &par : cursosYNotas) {
    suma += par.second;
  }
  return suma / cursosYNotas.size();
}

// Ordenar por nombre (alfabético)
bool Estudiante::operator<(const Estudiante &otro) const {
  // Sobrecarga del operador < para comparar por nombre
  return nombreCompleto < otro.nombreCompleto;
}

// Imprimir estudiante con nombre, legajo y promedio
std::ostream &operator<<(std::ostream &os, const Estudiante &e) {
  // Sobrecarga del operador << para imprimir
  os << std::fixed << std::setprecision(2);
  os << "Nombre: " << e.nombreCompleto << ", Legajo: " << e.legajo
     << ", Promedio: " << e.getPromedioGeneral();
  return os;
}
