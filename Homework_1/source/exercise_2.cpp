#include "../include/exercise_2.h"
#include <fstream>
#include <iostream>
#include <stdexcept>

// Convierte un LogLevel a string con formato [NIVEL]
std::string logLevelToString(LogLevel level) {
  switch (level) {
  case LogLevel::DEBUG:
    return "[DEBUG]";
  case LogLevel::INFO:
    return "[INFO]";
  case LogLevel::WARNING:
    return "[WARNING]";
  case LogLevel::ERROR:
    return "[ERROR]";
  case LogLevel::CRITICAL:
    return "[CRITICAL]";
  case LogLevel::SECURITY:
    return "[SECURITY]";
  case LogLevel::HOLA:
    return "[HOLA]"; // Evento personalizado
  case LogLevel::MAINTENANCE:
    return "[MAINTENANCE]"; // Evento de mantenimiento
  default:
    return "[UNKNOWN]";
  }
}

// Sanitiza strings para evitar saltos de línea, tabulaciones, etc.
std::string sanitizeInput(const std::string &input) {
  std::string sanitized;
  for (char c : input) {
    if (c == '\n' || c == '\t' || c == '\r') {
      sanitized += ' ';
    } else {
      sanitized += c;
    }
  }
  return sanitized;
}

// Implementación de logMessage básica
void logMessage(const std::string &mensaje, LogLevel nivel) {
  std::ofstream logFile("log.txt", std::ios::app);
  if (!logFile) {
    std::cerr << "Error al abrir el archivo de log.\n";
    return;
  }

  logFile << logLevelToString(nivel) << " " << mensaje << std::endl;
  logFile.flush(); // Asegura que se escriba inmediatamente
  logFile.close();
}

// Sobrecarga de logMessage para registrar errores con archivo y línea
void logMessage(const std::string &mensaje, LogLevel nivel,
                const std::string &archivo, int linea) {
  std::ofstream logFile("log.txt", std::ios::app);
  if (!logFile) {
    std::cerr << "Error al abrir el archivo de log.\n";
    return;
  }

  logFile << logLevelToString(nivel) << " " << mensaje
          << " (Archivo: " << archivo << ", Línea: " << linea << ")"
          << std::endl;
  logFile.flush();
  logFile.close();
}

// Evento de seguridad con sanitización
void logSecurityEvent(const std::string &usuario, const std::string &mensaje) {
  std::string cleanUser = sanitizeInput(usuario);
  std::string cleanMessage = sanitizeInput(mensaje);
  logMessage("Usuario: " + cleanUser + " - " + cleanMessage,
             LogLevel::SECURITY);
}

// Evento personalizado [HOLA]
void logCustomEvent(const std::string &mensaje) {
  logMessage(mensaje, LogLevel::HOLA);
}

// Evento de mantenimiento
void logMaintenance(const std::string &mensaje) {
  logMessage(mensaje, LogLevel::MAINTENANCE);
}

// Testeo de las funciones
int main() {
  try {
    // Logging básico como si fuera un sistema de un banco
    logMessage("Consulta de saldo realizada por usuario 123456",
               LogLevel::DEBUG);
    logMessage("Transferencia de $500 realizada a cuenta 789012",
               LogLevel::INFO);
    logMessage("Intento de acceso con credenciales incorrectas",
               LogLevel::WARNING);
    logMessage("Fallo en la verificación de identidad para usuario 456789",
               LogLevel::ERROR);
    logMessage("Transacción fraudulenta detectada en cuenta 987654",
               LogLevel::CRITICAL);

    // Eventos personalizados
    logCustomEvent("Mensaje de prueba para evento HOLA");
    logMaintenance("Servidor en mantenimiento programado");

    // Error con archivo y línea
    logMessage("Error en la base de datos", LogLevel::ERROR, __FILE__,
               __LINE__);

    // Evento de seguridad con caracteres especiales
    logSecurityEvent("usuario_admin",
                     "Access Denied\nIntento desde IP sospechosa");

    std::cout << "Mensajes de prueba escritos en log.txt" << std::endl;

    // Simulación de error en tiempo de ejecución
    throw std::runtime_error("Simulación de error crítico en ejecución");

  } catch (const std::runtime_error &e) {
    logMessage("Excepción en runtime: " + std::string(e.what()),
               LogLevel::CRITICAL, __FILE__, __LINE__);
    std::cerr << "Se produjo un error crítico, pero el programa continuará."
              << std::endl;
    // No termina con return 1 para que no se considere un error en la terminal.
  }

  return 0;
}