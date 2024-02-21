#include <iostream>

// Función para realizar regresión lineal utilizando vectores como argumentos
void regresionLineal(const double X[], const double y[], int n, double& b, double& w) {
    double dw = 0.0;
    double db = 0.0;

    for (int i = 0; i < n; ++i) {
        double error = y[i] - (w * X[i] + b);
        db += -2.0 * error;
        dw += -2.0 * error * X[i];
    }

    double alpha = 0.01;
    double aux = 1.0 / static_cast<double>(n);
    b = b - aux * alpha * db;
    w = w - aux * alpha * dw;
}

int main() {
    const int n = 5;
    double X[n] = {1, 2, 3, 4, 5};
    double y[n] = {5.3, 7.9, 9.5, 11.1, 13.8};

    double b = 0.0;
    double w = 0.0;

    // Llamada a la función de regresión lineal
    regresionLineal(X, y, n, b, w);

    // Imprimir resultados
    std::cout << "b: " << b << " w: " << w << std::endl;

    return 0;
}
