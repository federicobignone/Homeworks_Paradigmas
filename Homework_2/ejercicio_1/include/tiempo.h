#ifndef TIEMPO_H
#define TIEMPO_H

#include <iostream>
#include <string>

class Tiempo {
private:
  int hora;            // Debe estar en [1, 12]
  int minutos;         // Debe estar en [0, 59]
  int segundos;        // Debe estar en [0, 59]
  std::string periodo; // "a.m." o "p.m."

  // Método auxiliar para validar datos al asignar
  bool esHoraValida(int h);
  bool esMinutoValido(int m);
  bool esSegundoValido(int s);
  bool esPeriodoValido(const std::string &p);

public:
  // Constructores
  Tiempo();
  Tiempo(int h);
  Tiempo(int h, int m);
  Tiempo(int h, int m, int s);
  Tiempo(int h, int m, int s, const std::string &p);

  // Setters con validación
  void setHora(int h);
  void setMinutos(int m);
  void setSegundos(int s);
  void setPeriodo(const std::string &p);

  // Getters
  int getHora() const;
  int getMinutos() const;
  int getSegundos() const;
  std::string getPeriodo() const;

  // Muestra la hora en formato "HHh, MMm, SSs a.m./p.m."
  std::string toString() const;

  // Muestra la hora en formato 24 horas (sin a.m./p.m.)
  std::string toHora24() const;
};

#endif