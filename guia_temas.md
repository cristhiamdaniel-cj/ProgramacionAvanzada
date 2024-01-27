# Vectores y Matrices

## 1. Vectores

### 1.1 Declaración

**Definición y Tipos:**
En este caso, utilizaremos arreglos estáticos para representar vectores:

```cpp
#include <iostream>

int main() {
    // Declaración de un vector de enteros estático
    int vectorEnteros[5];

    // Declaración e inicialización de un vector de doubles estático
    double vectorDoubles[] = {1.5, 2.5, 3.5};

    return 0;
}
```

### 1.2 Vector de Constantes

**Creación de Vectores con Valores Constantes:**
Para tener un vector con valores constantes, puedes declarar un arreglo constante:

```cpp
#include <iostream>

int main() {
    // Vector de coeficientes constantes en regresión lineal
    const double coeficientes[] = {0.5, 1.2, -0.3};

    // Intentar modificar el vector generará un error de compilación
    // coeficientes[0] = 2.0;  // Error!

    return 0;
}
```

### 1.3 Límites de un Vector

**Longitud y Capacidad de un Vector:**
En este caso, la longitud del vector está determinada por el tamaño del arreglo, y no es posible cambiarla. La capacidad está asociada al tamaño máximo que puedes asignar al arreglo.

```cpp
#include <iostream>

int main() {
    int vectorEnteros[] = {1, 2, 3, 4, 5};

    // Obtener longitud del vector
    std::cout << "Longitud del vector: " << sizeof(vectorEnteros) / sizeof(vectorEnteros[0]) << std::endl;

    // No hay una función directa para obtener la capacidad en arreglos estáticos

    return 0;
}
```

**Gestión de Memoria y Redimensionamiento:**
Para redimensionar un arreglo dinámicamente, tendrías que utilizar la gestión de memoria manual con `new` y `delete`. Aquí tienes un ejemplo básico:

```cpp
#include <iostream>

int main() {
    int* vectorEnteros = new int[5];

    // ... Trabajar con el vector ...

    // Redimensionar el vector (crear uno nuevo)
    int* nuevoVectorEnteros = new int[10];

    // Copiar los elementos del vector original al nuevo vector

    // Liberar memoria del vector original
    delete[] vectorEnteros;

    // Actualizar el puntero al nuevo vector
    vectorEnteros = nuevoVectorEnteros;

    return 0;
}
```

Es importante mencionar que esta gestión de memoria manual puede ser propensa a errores y es más compleja que el uso de las librerías estándar de C++. Si prefieres, podemos avanzar al siguiente tema o abordar alguna otra pregunta que tengas.

### Aplicacion

```cpp
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

```
Este código se centra específicamente en los puntos mencionados sobre vectores (arreglos). La regresión lineal se realiza utilizando vectores `X` e `y`, y el vector de constantes `coeficientes` se utiliza en cálculos y operaciones. Además, se muestra la gestión de la longitud del vector y se imprime el loss durante el entrenamiento.