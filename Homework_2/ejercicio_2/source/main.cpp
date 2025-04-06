// main.cpp
#include "../include/curso.h"
#include "../include/estudiante.h"
#include <iostream>
#include <limits>
#include <map>
#include <memory>

int main() {
  std::map<int, std::unique_ptr<Estudiante>> estudiantesCreados;
  Curso curso("Paradigmas de Programación");

  bool salir = false;
  while (!salir) {
    std::cout << "\n----- MENÚ -----\n";
    std::cout << "1. Crear nuevo estudiante\n";
    std::cout << "2. Inscribir estudiante al curso\n";
    std::cout << "3. Desinscribir estudiante del curso\n";
    std::cout << "4. Verificar si estudiante está inscripto\n";
    std::cout << "5. Verificar si el curso está completo\n";
    std::cout
        << "6. Mostrar estudiantes inscriptos ordenados alfabéticamente\n";
    std::cout << "7. Mostrar todos los estudiantes creados\n";
    std::cout << "0. Salir\n";
    std::cout << "Seleccione una opción: ";

    int opcion;
    std::cin >> opcion;
    std::cin.ignore(); // limpiar buffer

    switch (opcion) {
    case 1: {
      std::string nombre;
      int legajo;

      // Validar nombre no vacío
      do {
        std::cout << "Ingrese nombre completo del estudiante: ";
        std::getline(std::cin, nombre);
        if (nombre.empty()) {
          std::cout << "El nombre no puede estar vacío. Intente de nuevo.\n";
        }
      } while (nombre.empty());

      // Validar legajo
      while (true) {
        std::cout << "Ingrese legajo único (número entero positivo): ";
        std::cin >> legajo;
        if (std::cin.fail() || legajo <= 0) {
          std::cin.clear();
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
          std::cout << "Legajo inválido. Intente de nuevo.\n";
        } else {
          break;
        }
      }

      if (estudiantesCreados.count(legajo)) {
        std::cout << "Ya existe un estudiante con ese legajo.\n";
      } else {
        estudiantesCreados[legajo] =
            std::make_unique<Estudiante>(nombre, legajo);
        std::cout << "Estudiante creado correctamente.\n";
      }
      break;
    }
    case 2: {
      int legajo;
      std::cout << "Ingrese legajo del estudiante a inscribir: ";
      std::cin >> legajo;

      if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Entrada inválida. Debe ingresar un número entero.\n";
        break;
      }

      if (!estudiantesCreados.count(legajo)) {
        std::cout << "No existe estudiante con ese legajo.\n";
      } else if (curso.inscribirEstudiante(estudiantesCreados[legajo].get())) {
        std::cout << "Estudiante inscrito correctamente.\n";
      } else {
        std::cout << "No se pudo inscribir (puede estar inscrito o el curso "
                     "estar completo).\n";
      }
      break;
    }
    case 3: {
      int legajo;
      std::cout << "Ingrese legajo del estudiante a desinscribir: ";
      std::cin >> legajo;

      if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Entrada inválida. Debe ingresar un número entero.\n";
        break;
      }

      if (curso.desinscribirEstudiante(legajo)) {
        std::cout << "Estudiante desinscripto correctamente.\n";
      } else {
        std::cout << "No se encontró al estudiante en el curso.\n";
      }
      break;
    }
    case 4: {
      int legajo;
      std::cout << "Ingrese legajo del estudiante: ";
      std::cin >> legajo;

      if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Entrada inválida. Debe ingresar un número entero.\n";
        break;
      }

      if (curso.estaInscripto(legajo)) {
        std::cout << "El estudiante está inscripto en el curso.\n";
      } else {
        std::cout << "El estudiante NO está inscripto en el curso.\n";
      }
      break;
    }
    case 5: {
      if (curso.estaCompleto()) {
        std::cout << "El curso está completo.\n";
      } else {
        std::cout << "El curso aún tiene cupo.\n";
      }
      break;
    }
    case 6: {
      std::cout << "\nEstudiantes inscriptos ordenados alfabéticamente:\n";
      curso.imprimirOrdenAlfabetico();
      break;
    }
    case 7: {
      std::cout << "\nTodos los estudiantes creados:\n";
      for (const auto &par : estudiantesCreados) {
        std::cout << *par.second << std::endl;
      }
      break;
    }
    case 0:
      salir = true;
      break;
    default:
      std::cout << "Opción inválida. Intente nuevamente.\n";
    }
  }

  std::cout << "Programa finalizado.\n";
  return 0;
}
