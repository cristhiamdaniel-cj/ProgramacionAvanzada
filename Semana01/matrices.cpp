#include <iostream>
#include <vector>

// Función para imprimir una matriz
void imprimirMatriz(const std::vector<std::vector<double>>& matriz) {
    for (const auto& fila : matriz) {
        for (double elemento : fila) {
            std::cout << elemento << " ";
        }
        std::cout << std::endl;
    }
}

// Función para realizar regresión lineal múltiple
void regresionLinealMultiple(const std::vector<std::vector<double>>& X,
                              const std::vector<double>& y,
                              std::vector<double>& coeficientes) {
    // Implementación simple de la ecuación normal
    // En una aplicación real, se puede utilizar una biblioteca de álgebra lineal

    // Calcular la transpuesta de la matriz X
    std::vector<std::vector<double>> X_transpuesta(X[0].size(), std::vector<double>(X.size(), 0.0));
    for (size_t i = 0; i < X.size(); ++i) {
        for (size_t j = 0; j < X[0].size(); ++j) {
            X_transpuesta[j][i] = X[i][j];
        }
    }

    // Calcular X_transpuesta * X
    std::vector<std::vector<double>> XTX(X[0].size(), std::vector<double>(X[0].size(), 0.0));
    for (size_t i = 0; i < X[0].size(); ++i) {
        for (size_t j = 0; j < X[0].size(); ++j) {
            for (size_t k = 0; k < X.size(); ++k) {
                XTX[i][j] += X_transpuesta[i][k] * X[k][j];
            }
        }
    }

    // Calcular X_transpuesta * y
    std::vector<double> XTy(X[0].size(), 0.0);
    for (size_t i = 0; i < X[0].size(); ++i) {
        for (size_t j = 0; j < X.size(); ++j) {
            XTy[i] += X_transpuesta[i][j] * y[j];
        }
    }

    // Resolver el sistema de ecuaciones XTX * coeficientes = XTy
    for (size_t i = 0; i < X[0].size(); ++i) {
        for (size_t j = i + 1; j < X[0].size(); ++j) {
            double factor = XTX[j][i] / XTX[i][i];
            for (size_t k = i; k < X[0].size(); ++k) {
                XTX[j][k] -= factor * XTX[i][k];
            }
            XTy[j] -= factor * XTy[i];
        }
    }

    // Sustitución hacia atrás para encontrar los coeficientes
    for (int i = X[0].size() - 1; i >= 0; --i) {
        coeficientes[i] = XTy[i];
        for (size_t j = i + 1; j < X[0].size(); ++j) {
            coeficientes[i] -= XTX[i][j] * coeficientes[j];
        }
        coeficientes[i] /= XTX[i][i];
    }
}

int main() {
    const size_t filas = 5; // Número de observaciones
    const size_t columnas = 3; // Número de características (incluyendo el término independiente)

    // Datos de entrada (una fila por observación)
    std::vector<std::vector<double>> X = {
        {1, 2, 3},
        {1, 3, 4},
        {1, 4, 5},
        {1, 5, 7},
        {1, 2, 6}
    };

    // Etiquetas (valores objetivo)
    std::vector<double> y = {2.3, 4.5, 5.2, 7.1, 8.0};

    // Coeficientes de la regresión
    std::vector<double> coeficientes(columnas, 0.0);

    // Realizar regresión lineal múltiple
    regresionLinealMultiple(X, y, coeficientes);

    // Imprimir coeficientes
    std::cout << "Coeficientes de la regresión:" << std::endl;
    for (double coeficiente : coeficientes) {
        std::cout << coeficiente << " ";
    }
    std::cout << std::endl;

    return 0;
}

// y=−0.662791−0.667442x_1+1.64372x_2