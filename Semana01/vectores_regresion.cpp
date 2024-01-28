#include <iostream>

// Función para realizar regresión lineal utilizando vectores
void regresionLineal(double X[], double y[], int n, double& b, double& w) {
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

// Función para calcular la pérdida (error cuadrático medio)
double calcularPérdida(double X[], double y[], int n, double b, double w) {
    double sum = 0.0;

    for (int i = 0; i < n; ++i) {
        double error = y[i] - (w * X[i] + b);
        sum += error * error;
    }

    return sum / static_cast<double>(n);
}

int main() {
    const int n = 5;

    // 1. Vectores - Declaración e Inicialización
    double X[n] = {1, 2, 3, 4, 5};
    double y[n] = {5.3, 7.9, 9.5, 11.1, 13.8};

    // 1. Vectores - Vector de Constantes
    double coeficientes[] = {0.0, 0.0};  // b y w como constantes iniciales

    // Mostrar valores iniciales
    std::cout << "Antes de la regresión:" << std::endl;
    std::cout << "b: " << coeficientes[0] << " w: " << coeficientes[1] << std::endl;
    std::cout << "Loss: " << calcularPérdida(X, y, n, coeficientes[0], coeficientes[1]) << std::endl;

    int epochs = 9001;

    for (int e = 0; e < epochs; ++e) {
        // 2. Vectores - Paso de Vectores a Funciones (durante la regresión)
        regresionLineal(X, y, n, coeficientes[0], coeficientes[1]);

        // 3. Límites de un Vector - Mostrar Loss cada 100 epochs
        if (e % 100 == 0) {
            std::cout << "Epoch: " << e << " Loss: " << calcularPérdida(X, y, n, coeficientes[0], coeficientes[1]) << std::endl;
        }
    }

    // 2. Vectores - Paso de Vectores a Funciones (después de la regresión)
    std::cout << "Después de la regresión:" << std::endl;
    std::cout << "b: " << coeficientes[0] << " w: " << coeficientes[1] << std::endl;
    std::cout << "Loss: " << calcularPérdida(X, y, n, coeficientes[0], coeficientes[1]) << std::endl;

    // 4. Vectores - Utilización en Cálculos y Operaciones
    std::cout << "Predicción para x = 6: " << (coeficientes[1] * 6) + coeficientes[0] << std::endl;

    return 0;
}
