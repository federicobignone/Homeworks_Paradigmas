#include <chrono>
#include <iostream>

// a) Comparación recursiva

bool compare_recursive(const char *a, const char *b) {
  if (*a == '\0' && *b == '\0')
    return true;
  if (*a != *b)
    return false;
  return compare_recursive(a + 1, b + 1);
}

// c) Comparación en tiempo de compilación

constexpr bool compare_constexpr(const char *a, const char *b) {
  return (*a == '\0' && *b == '\0') ? true
         : (*a != *b)               ? false
                                    : compare_constexpr(a + 1, b + 1);
}

int main() {
  // Texto de al menos 64 caracteres
  const char *text1 =
      "Este es un texto largo de prueba para verificar la recursion.";
  const char *text2 =
      "Este es un texto largo de prueba para verificar la recursion.";
  const char *text3 =
      "Este es un texto largo de prueba que es diferente en el final.";

  std::cout << "=== Comparación recursiva (parte a) ===\n";

  bool result1 = compare_recursive(text1, text2);
  bool result2 = compare_recursive(text1, text3);

  std::cout << "Resultado 1 (text1 vs text2): "
            << (result1 ? "iguales" : "distintos") << "\n";
  std::cout << "Resultado 2 (text1 vs text3): "
            << (result2 ? "iguales" : "distintos") << "\n";

  // b) Medición de tiempo
  std::cout << "\n=== Medición de tiempo (parte b) ===\n";

  auto start = std::chrono::high_resolution_clock::now();
  volatile bool dummy = compare_recursive(text1, text2);
  if (dummy) {
  } // para evitar el warning sin imprimir nada
  auto end = std::chrono::high_resolution_clock::now();

  std::chrono::duration<double, std::micro> duration = end - start;
  std::cout << "Tiempo de ejecución (us): " << duration.count() << " µs\n";

  // c)
  std::cout << "\n=== Comparación en tiempo de compilación (parte c) ===\n";

  constexpr bool result_constexpr_1 = compare_constexpr(
      "Este es un texto largo de prueba para verificar la recursion.",
      "Este es un texto largo de prueba para verificar la recursion.");

  constexpr bool result_constexpr_2 = compare_constexpr(
      "Este es un texto largo de prueba para verificar la recursion.",
      "Este es un texto largo de prueba que es diferente en el final.");

  std::cout << "Resultado constexpr 1: "
            << (result_constexpr_1 ? "iguales" : "distintos") << "\n";
  std::cout << "Resultado constexpr 2: "
            << (result_constexpr_2 ? "iguales" : "distintos") << "\n";

  return 0;
}

/*
Diferencia entre comparación runtime y constexpr:

La función compare_recursive evalúa los textos en tiempo de ejecución, lo que
permite comparar cualquier entrada dinámica. En cambio, compare_constexpr evalúa
en tiempo de compilación, lo que permite detectar diferencias en cadenas
literales estáticas antes de ejecutar el programa. Esto reduce el costo
en runtime a 0.

*/