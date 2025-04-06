#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <iostream>
#include <map>
#include <string>

class Estudiante {
private: // Pongo private para proteger los datos
  std::string nombreCompleto;
  int legajo;
  std::map<std::string, float> cursosYNotas; // curso -> nota final

public: // Pongo public solo para lo indispensable
  Estudiante(const std::string &nombre, int legajo);

  std::string getNombre() const;
  int getLegajo() const;
  float getPromedioGeneral() const;

  void agregarNota(const std::string &curso, float nota);

  // Sobrecarga del operador < para ordenar por nombre
  bool operator<(const Estudiante &otro) const;

  // Sobrecarga del operador << para impresión
  friend std::ostream &operator<<(std::ostream &os, const Estudiante &e);
};

#endif

/*
 Relación entre Curso y Estudiante:
 La relación entre Curso y Estudiante es de **agregación**.

 Un objeto Curso mantiene una colección de punteros a objetos Estudiante,
 pero **no es responsable de su creación ni destrucción**.

 Esto significa que los objetos Estudiante pueden existir de forma
 independiente y pertenecer a varios cursos simultáneamente. Es decir, la vida
 de un Estudiante no depende de la vida del Curso.
*/