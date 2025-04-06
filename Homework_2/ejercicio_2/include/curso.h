#ifndef CURSO_H
#define CURSO_H

#include "estudiante.h"
#include <string>
#include <vector>

class Curso {
private:
  std::string nombre;
  std::vector<Estudiante *> estudiantes;
  static const int CAPACIDAD_MAXIMA = 20;

public:
  Curso(const std::string &nombre);

  bool inscribirEstudiante(Estudiante *e);
  bool desinscribirEstudiante(int legajo);
  bool estaInscripto(int legajo) const;
  bool estaCompleto() const;

  void imprimirOrdenAlfabetico() const;

  // Copia superficial: copia los punteros (no los estudiantes en sí)
  // Esto es razonable porque varios cursos comparten estudiantes,
  // y no queremos duplicar objetos. La responsabilidad de manejar
  // la memoria de los estudiantes no es del curso.
  Curso(const Curso &otro);
};

#endif
