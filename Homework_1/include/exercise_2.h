#ifndef EXERCISE_2_H
#define EXERCISE_2_H

#include <string>

// Niveles de severidad del log con eventos personalizados
enum class LogLevel {
  DEBUG,
  INFO,
  WARNING,
  ERROR,
  CRITICAL,
  SECURITY,
  HOLA,       // Evento personalizado
  MAINTENANCE // Evento de mantenimiento
};

// Funciones de logging
void logMessage(const std::string &mensaje, LogLevel nivel);
void logMessage(const std::string &mensaje, LogLevel nivel,
                const std::string &archivo, int linea);
void logSecurityEvent(const std::string &usuario, const std::string &mensaje);
void logCustomEvent(
    const std::string &mensaje); // Nueva función para el evento "HOLA"

#endif // EXERCISE_2_H