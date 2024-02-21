#include <iostream>

// Función para realizar regresión lineal múltiple
bool regresionLinealMultiple(const double** X, const double* y, size_t filas, size_t columnas, double* coeficientes) {
    // Implementación simple de la ecuación normal sin descomposición LU

    // Calcular la transpuesta de la matriz X
    double X_transpuesta[columnas][filas];
    for (size_t i = 0; i < columnas; ++i) {
        for (size_t j = 0; j < filas; ++j) {
            X_transpuesta[i][j] = X[j][i];
        }
    }

    // Calcular X_transpuesta * X
    double XTX[columnas][columnas] = {0.0};
    for (size_t i = 0; i < columnas; ++i) {
        for (size_t j = 0; j < columnas; ++j) {
            for (size_t k = 0; k < filas; ++k) {
                XTX[i][j] += X_transpuesta[i][k] * X[k][j];
            }
        }
    }

    // Calcular X_transpuesta * y
    double XTy[columnas] = {0.0};
    for (size_t i = 0; i < columnas; ++i) {
        for (size_t j = 0; j < filas; ++j) {
            XTy[i] += X_transpuesta[i][j] * y[j];
        }
    }

    // Resolver el sistema de ecuaciones XTX * coeficientes = XTy
    for (size_t i = 0; i < columnas; ++i) {
        for (size_t j = i + 1; j < columnas; ++j) {
            double factor = XTX[j][i] / XTX[i][i];
            for (size_t k = i; k < columnas; ++k) {
                XTX[j][k] -= factor * XTX[i][k];
            }
            XTy[j] -= factor * XTy[i];
        }
    }

    // Sustitución hacia atrás para encontrar los coeficientes
    for (int i = columnas - 1; i >= 0; --i) {
        coeficientes[i] = XTy[i];
        for (size_t j = i + 1; j < columnas; ++j) {
            coeficientes[i] -= XTX[i][j] * coeficientes[j];
        }
        coeficientes[i] /= XTX[i][i];
    }

    return true;
}

int main() {
    const size_t filas = 5;  // Número de observaciones
    const size_t columnas = 3;  // Número de características (incluyendo el término independiente)

    // Datos de entrada (una fila por observación)
    const double* X[filas] = {
        new double[columnas] {1, 1, 2},
        new double[columnas] {1, 2, 3},
        new double[columnas] {1, 3, 4},
        new double[columnas] {1, 4, 5},
        new double[columnas] {1, 5, 6}
    };

    // Etiquetas (valores objetivo)
    const double y[filas] = {2.3, 4.5, 5.2, 7.1, 8.0};

    // Coeficientes de la regresión
    double coeficientes[columnas] = {0.0};

    // Realizar regresión lineal múltiple
    if (regresionLinealMultiple(X, y, filas, columnas, coeficientes)) {
        // Imprimir coeficientes
        std::cout << "Coeficientes de la regresión:" << std::endl;
        for (size_t i = 0; i < columnas; ++i) {
            std::cout << coeficientes[i] << " ";
        }
        std::cout << std::endl;
    } else {
        std::cerr << "Error en la regresión lineal múltiple." << std::endl;
    }

    // Liberar memoria
    for (size_t i = 0; i < filas; ++i) {
        delete[] X[i];
    }

    return 0;
}
