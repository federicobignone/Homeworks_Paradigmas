#include "../include/curso.h"
#include <algorithm>
#include <iostream>

Curso::Curso(const std::string &nombre) : nombre(nombre) {}

bool Curso::inscribirEstudiante(Estudiante *e) {
  if (estaCompleto())
    return false;
  if (estaInscripto(e->getLegajo()))
    return false;
  estudiantes.push_back(e);
  return true;
}

bool Curso::desinscribirEstudiante(int legajo) {
  auto it = std::remove_if(
      estudiantes.begin(), estudiantes.end(),
      [legajo](Estudiante *e) { return e->getLegajo() == legajo; });
  if (it != estudiantes.end()) {
    estudiantes.erase(it, estudiantes.end());
    return true;
  }
  return false;
}

bool Curso::estaInscripto(int legajo) const {
  for (Estudiante *e : estudiantes) {
    if (e->getLegajo() == legajo)
      return true;
  }
  return false;
}

bool Curso::estaCompleto() const {
  return estudiantes.size() >= CAPACIDAD_MAXIMA;
}

void Curso::imprimirOrdenAlfabetico() const {
  std::vector<Estudiante *> copia = estudiantes;
  std::sort(copia.begin(), copia.end(), [](Estudiante *a, Estudiante *b) {
    return *a < *b; // Usa operator< de Estudiante
  });
  for (const auto &est : copia) {
    std::cout << *est << std::endl; // Usa operator<< de Estudiante
  }
}

// Copia superficial del vector de punteros
Curso::Curso(const Curso &otro)
    : nombre(otro.nombre), estudiantes(otro.estudiantes) {
  // Justificación:
  // Al copiar el vector de punteros estamos compartiendo los objetos Estudiante
  // entre varios cursos. Esto es deseado ya que un estudiante puede estar en
  // varios cursos. No hacemos una copia profunda porque eso duplicaría la
  // información innecesariamente y violaría la lógica del sistema donde el
  // estudiante es único por legajo.
}
