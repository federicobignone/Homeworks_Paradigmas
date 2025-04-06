#include "../include/tiempo.h"
#include <iomanip>
#include <limits>
#include <sstream>

// Métodos auxiliares para validar valores
bool Tiempo::esHoraValida(int h) { return h >= 1 && h <= 12; }

bool Tiempo::esMinutoValido(int m) { return m >= 0 && m < 60; }

bool Tiempo::esSegundoValido(int s) { return s >= 0 && s < 60; }

bool Tiempo::esPeriodoValido(const std::string &p) {
  return p == "a.m." || p == "p.m.";
}

// Constructores
Tiempo::Tiempo() : hora(0), minutos(0), segundos(0), periodo("a.m.") {}

Tiempo::Tiempo(int h) : Tiempo() {
  if (esHoraValida(h))
    hora = h;
}

Tiempo::Tiempo(int h, int m) : Tiempo(h) {
  if (esMinutoValido(m))
    minutos = m;
}

Tiempo::Tiempo(int h, int m, int s) : Tiempo(h, m) {
  if (esSegundoValido(s))
    segundos = s;
}

Tiempo::Tiempo(int h, int m, int s, const std::string &p) : Tiempo(h, m, s) {
  if (esPeriodoValido(p))
    periodo = p;
}

// Setters
void Tiempo::setHora(int h) {
  if (esHoraValida(h))
    hora = h;
}

void Tiempo::setMinutos(int m) {
  if (esMinutoValido(m))
    minutos = m;
}

void Tiempo::setSegundos(int s) {
  if (esSegundoValido(s))
    segundos = s;
}

void Tiempo::setPeriodo(const std::string &p) {
  if (esPeriodoValido(p))
    periodo = p;
}

// Getters
int Tiempo::getHora() const { return hora; }
int Tiempo::getMinutos() const { return minutos; }
int Tiempo::getSegundos() const { return segundos; }
std::string Tiempo::getPeriodo() const { return periodo; }

// Muestra la hora en formato "HHh, MMm, SSs a.m./p.m."
std::string Tiempo::toString() const {
  std::ostringstream oss;
  oss << std::setw(2) << std::setfill('0') << hora << "h, " << std::setw(2)
      << std::setfill('0') << minutos << "m, " << std::setw(2)
      << std::setfill('0') << segundos << "s " << periodo;
  return oss.str();
}

// Muestra la hora en formato 24hs (HH:MM:SS)
std::string Tiempo::toHora24() const {
  int h24 = hora;
  if (periodo == "p.m." && hora != 12)
    h24 += 12;
  if (periodo == "a.m." && hora == 12)
    h24 = 0;

  std::ostringstream oss;
  oss << std::setw(2) << std::setfill('0') << h24 << ":" << std::setw(2)
      << std::setfill('0') << minutos << ":" << std::setw(2)
      << std::setfill('0') << segundos;
  return oss.str();
}

// Función principal con validación interactiva
int main() {
  Tiempo t;

  std::cout << "Probando constructores:\n";
  Tiempo t1;
  std::cout << "Constructor por defecto: " << t1.toString() << std::endl;

  Tiempo t2(9);
  std::cout << "Constructor con hora: " << t2.toString() << std::endl;

  Tiempo t3(10, 25);
  std::cout << "Constructor con hora y minutos: " << t3.toString() << std::endl;

  Tiempo t4(11, 45, 30);
  std::cout << "Constructor con hora, minutos y segundos: " << t4.toString()
            << std::endl;

  Tiempo t5(3, 14, 42, "p.m.");
  std::cout << "Constructor completo: " << t5.toString() << std::endl;
  std::cout << "Formato 24h: " << t5.toHora24() << std::endl;

  std::cout << "\n--- Menú de prueba interactiva ---\n";
  bool continuar = true;
  while (continuar) {
    std::cout << "\nSeleccione una opción:\n";
    std::cout << "1. Modificar hora\n";
    std::cout << "2. Modificar minutos\n";
    std::cout << "3. Modificar segundos\n";
    std::cout << "4. Modificar período (a.m./p.m.)\n";
    std::cout << "5. Ver tiempo en formato 12h\n";
    std::cout << "6. Ver tiempo en formato 24h\n";
    std::cout << "0. Salir\n";
    std::cout << "Opción: ";

    int opcion;
    std::cin >> opcion;

    switch (opcion) {
    case 1: {
      int h;
      while (true) {
        std::cout << "Ingrese la hora (1-12, -1 para cancelar): ";
        std::cin >> h;
        if (h == -1)
          break;
        if (h >= 1 && h <= 12) {
          t.setHora(h);
          break;
        } else {
          std::cout << "Valor inválido.\n";
        }
      }
      break;
    }
    case 2: {
      int m;
      while (true) {
        std::cout << "Ingrese los minutos (0-59, -1 para cancelar): ";
        std::cin >> m;
        if (m == -1)
          break;
        if (m >= 0 && m < 60) {
          t.setMinutos(m);
          break;
        } else {
          std::cout << "Valor inválido.\n";
        }
      }
      break;
    }
    case 3: {
      int s;
      while (true) {
        std::cout << "Ingrese los segundos (0-59, -1 para cancelar): ";
        std::cin >> s;
        if (s == -1)
          break;
        if (s >= 0 && s < 60) {
          t.setSegundos(s);
          break;
        } else {
          std::cout << "Valor inválido.\n";
        }
      }
      break;
    }
    case 4: {
      std::string p;
      while (true) {
        std::cout << "Ingrese el período (a.m. o p.m., salir para cancelar): ";
        std::cin >> p;
        if (p == "salir")
          break;
        if (p == "a.m." || p == "p.m.") {
          t.setPeriodo(p);
          break;
        } else {
          std::cout << "Valor inválido.\n";
        }
      }
      break;
    }
    case 5:
      std::cout << "Tiempo actual (12h): " << t.toString() << std::endl;
      break;
    case 6:
      std::cout << "Tiempo actual (24h): " << t.toHora24() << std::endl;
      break;
    case 0:
      continuar = false;
      break;
    default:
      std::cout << "Opción inválida. Intente de nuevo.\n";
    }
  }

  std::cout << "Programa finalizado.\n";
  return 0;
}
// Aclaración:
// En el sistema de 24 horas:
// - 12:00 a.m. representa medianoche (00:00)
// - 12:00 p.m. representa mediodía (12:00)
// Esto puede resultar confuso si uno espera que 12 p.m. sea 00:00, pero ese
// valor en 24h es reservado para el inicio del día (medianoche).
