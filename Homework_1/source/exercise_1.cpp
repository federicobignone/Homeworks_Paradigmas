#include <iostream>
#include <sstream> // Necesario para stringstream
#include <vector>

// Se usa size_t para los índices (coincide con lo que espera vector).
std::vector<std::vector<int>> generateMatrix(int n) {
  const size_t N = static_cast<size_t>(
      n); // Se convierte a size_t porque es el tipo que espera vector
  std::vector<std::vector<int>> matrix(N, std::vector<int>(N));
  int value = 1;
  for (size_t i = 0; i < N; ++i) {
    for (size_t j = 0; j < N; ++j) {
      matrix[i][j] = value++;
    }
  } // Se usa value++ para llenar la matriz de izquierda a derecha y de arriba
    // hacia abajo con números consecutivos.
  return matrix;
}

// Imprime la matriz desde el valor mayor al menor.
void printMatrixDescendingOrder(const std::vector<std::vector<int>> &matrix) {
  // Se pasa por referencia para evitar copias innecesarias.
  const size_t N = matrix.size();
  const int total = static_cast<int>(N * N);
  // total es el mayor número en la matriz (n*n).

  for (int val = total; val >= 1; --val) {
    size_t i = static_cast<size_t>((val - 1) / static_cast<int>(N));
    size_t j = static_cast<size_t>((val - 1) % static_cast<int>(N));
    // Division entera para obtener el índice i y módulo para obtener el j.
    std::cout << "M" << N << "[" << i << "][" << j << "] = " << matrix[i][j]
              << std::endl;
  }
}

int main() {
  int n;
  std::string input; // Almacena la línea de entrada del usuario.

  // Validación del input del usuario.
  while (true) {
    std::cout << "Ingrese un valor entero positivo mayor que 1: ";
    std::getline(std::cin, input); // lee toda la línea como string
    std::stringstream ss(input);

    if ((ss >> n) && ss.eof() &&
        n > 1) { // intenta extraer un int y verifica que no haya más caracteres
                 // después del número.
      break;
    } else {
      std::cout << "Entrada inválida. Intente de nuevo.\n";
    }
    // uso sstream porque cin >> n hace casteos no seguros y puede fallar.
  }

  std::vector<std::vector<int>> matrix = generateMatrix(n);
  printMatrixDescendingOrder(matrix);

  return 0;
}
