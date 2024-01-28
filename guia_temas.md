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

Entendido, estamos evitando el uso de las librerías `<vector>` y `<array>`. Vamos a continuar generando contenido para los subtemas utilizando únicamente arreglos en C++.

## 2. Paso de Vectores a Funciones

### 2.1 Vectores de Constantes

**Pasando vectores como argumentos:**
En C++, los arreglos pueden ser pasados a funciones como argumentos de manera similar a otros tipos de datos. Al utilizar referencias, se evita copiar el contenido completo del vector, lo que mejora la eficiencia.

```cpp
#include <iostream>

void funcionConArreglo(const int miArreglo[], int tamaño) {
    // Acceder a elementos del arreglo
    for (int i = 0; i < tamaño; ++i) {
        std::cout << miArreglo[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int arregloPrincipal[] = {1, 2, 3, 4, 5};
    int tamañoArreglo = sizeof(arregloPrincipal) / sizeof(arregloPrincipal[0]);
    
    funcionConArreglo(arregloPrincipal, tamañoArreglo);

    return 0;
}
```

**Modificación y retorno de arreglos:**
Una función puede modificar los elementos de un arreglo y, opcionalmente, devolver un nuevo arreglo modificado. Aquí se muestra un ejemplo donde se duplican los elementos del arreglo.

```cpp
#include <iostream>

void duplicarArreglo(const int arregloOriginal[], int tamaño, int arregloDuplicado[]) {
    for (int i = 0; i < tamaño; ++i) {
        arregloDuplicado[i] = arregloOriginal[i] * 2;
    }
}

int main() {
    int arregloPrincipal[] = {1, 2, 3, 4, 5};
    int tamañoArreglo = sizeof(arregloPrincipal) / sizeof(arregloPrincipal[0]);
    int arregloDuplicado[tamañoArreglo];

    duplicarArreglo(arregloPrincipal, tamañoArreglo, arregloDuplicado);

    // Mostrar el arreglo duplicado
    for (int i = 0; i < tamañoArreglo; ++i) {
        std::cout << arregloDuplicado[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

### 2.2 Tamaño Delimitado por Centinela

**Uso de centinela para gestionar el tamaño:**
Al igual que con vectores, un centinela puede utilizarse para gestionar dinámicamente el tamaño de un arreglo.

```cpp
#include <iostream>

void imprimirArregloConCentinela(const int miArreglo[]) {
    for (int i = 0; miArreglo[i] != -1; ++i) {
        std::cout << miArreglo[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int arregloConCentinela[] = {1, 2, 3, 4, 5, -1};  // -1 indica el final
    imprimirArregloConCentinela(arregloConCentinela);

    return 0;
}
```

**Evitando desbordamientos y errores:**
Para evitar desbordamientos y errores al gestionar dinámicamente el tamaño de un arreglo, es crucial garantizar que el centinela no sea confundido con un valor de datos real.

```cpp
#include <iostream>

void agregarConCentinela(int miArreglo[], int nuevoElemento) {
    const int centinela = -1;

    for (int i = 0; miArreglo[i] != centinela; ++i) {
        // Buscar el centinela para gestionar el tamaño
    }

    // Agregar nuevo elemento y volver a colocar el centinela
    miArreglo[0] = nuevoElemento;
    miArreglo[1] = centinela;
}

int main() {
    int arregloConCentinela[] = {1, 2, 3, 4, 5, -1};
    agregarConCentinela(arregloConCentinela, 6);

    // Mostrar el arreglo actualizado
    for (int i = 0; arregloConCentinela[i] != -1; ++i) {
        std::cout << arregloConCentinela[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

## 3. Ejemplos: Búsqueda y Ordenación

### 3.1 Algoritmos de Búsqueda

#### 3.1.1 Búsqueda Lineal y Binaria

**Búsqueda Lineal:**
- Definición: La búsqueda lineal recorre secuencialmente los elementos de una colección hasta encontrar el elemento deseado.
- Aplicación práctica: Buscar un elemento específico en un arreglo no ordenado.

```cpp
#include <iostream>

bool busquedaLineal(const int arreglo[], int n, int objetivo) {
    for (int i = 0; i < n; ++i) {
        if (arreglo[i] == objetivo) {
            return true;  // Elemento encontrado
        }
    }
    return false;  // Elemento no encontrado
}

int main() {
    const int n = 5;
    int arreglo[] = {2, 4, 7, 1, 9};
    int objetivo = 7;

    if (busquedaLineal(arreglo, n, objetivo)) {
        std::cout << "Elemento encontrado." << std::endl;
    } else {
        std::cout << "Elemento no encontrado." << std::endl;
    }

    return 0;
}
```

**Búsqueda Binaria:**
- Definición: La búsqueda binaria funciona en arreglos ordenados, dividiendo el espacio de búsqueda por la mitad en cada iteración.
- Aplicación práctica: Buscar un elemento específico en un arreglo ordenado.

```cpp
#include <iostream>

bool busquedaBinaria(const int arreglo[], int inicio, int fin, int objetivo) {
    while (inicio <= fin) {
        int medio = inicio + (fin - inicio) / 2;

        if (arreglo[medio] == objetivo) {
            return true;  // Elemento encontrado
        }

        if (arreglo[medio] < objetivo) {
            inicio = medio + 1;
        } else {
            fin = medio - 1;
        }
    }
    return false;  // Elemento no encontrado
}

int main() {
    const int n = 5;
    int arreglo[] = {1, 2, 4, 7, 9};
    int objetivo = 7;

    if (busquedaBinaria(arreglo, 0, n - 1, objetivo)) {
        std::cout << "Elemento encontrado." << std::endl;
    } else {
        std::cout << "Elemento no encontrado." << std::endl;
    }

    return 0;
}
```

### 3.2 Algoritmos de Ordenación

#### 3.2.1 Bubble Sort

**Bubble Sort:**
- Definición: Bubble Sort compara y swapea elementos adyacentes hasta que la colección esté ordenada.
- Comparación de rendimiento: No es eficiente para grandes conjuntos de datos.
- Eficiencia: O(n^2) en el peor caso.

```cpp
#include <iostream>

void bubbleSort(int arreglo[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arreglo[j] > arreglo[j + 1]) {
                // Swap de elementos
                int temp = arreglo[j];
                arreglo[j] = arreglo[j + 1];
                arreglo[j + 1] = temp;
            }
        }
    }
}

int main() {
    const int n = 5;
    int arreglo[] = {4, 2, 7, 1, 9};

    // Aplicar Bubble Sort al arreglo
    bubbleSort(arreglo, n);

    // Imprimir arreglo ordenado
    std::cout << "Arreglo ordenado: ";
    for (int i = 0; i < n; ++i) {
        std::cout << arreglo[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

#### 3.2.2 QuickSort

**QuickSort:**
- Definición: QuickSort utiliza un elemento pivote para dividir la colección en subconjuntos y luego aplica recursivamente el algoritmo.
- Comparación de rendimiento: Eficiente para grandes conjuntos de datos.
- Eficiencia: O(n log n) en el caso promedio.

```cpp
#include <iostream>

void intercambiar(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int particionar(int arreglo[], int bajo, int alto) {
    int pivote = arreglo[alto];
    int i = bajo - 1;

    for (int j = bajo; j < alto; ++j) {
        if (arreglo[j] <= pivote) {
            ++i;
            intercambiar(arreglo[i], arreglo[j]);
        }
    }

    intercambiar(arreglo[i + 1], arreglo[alto]);
    return i + 1;
}

void quickSort(int arreglo[], int bajo, int alto) {
    if (bajo < alto) {
        int indicePivote = particionar(arreglo, bajo, alto);

        quickSort(arreglo, bajo, indicePivote - 1);
        quickSort(arreglo, indicePivote + 1, alto);
    }
}

int main() {
    const int n = 5;
    int arreglo[] = {4, 2, 7, 1, 9};

    // Aplicar QuickSort al arreglo
    quickSort(arreglo, 0, n - 1);

    // Imprimir arreglo ordenado
    std::cout << "Arreglo ordenado: ";
    for (int i = 0; i < n; ++i) {
        std::cout << arreglo[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
```
## Cadena de Caracteres

### 4.1 Paso de Cadenas a Funciones

#### Tratamiento de strings como vectores

En el contexto de programación, las cadenas de caracteres son tratadas como vectores, permitiendo realizar operaciones similares a las de los vectores tradicionales. Este enfoque posibilita el acceso y manipulación de caracteres individuales en la cadena, abriendo la puerta a diversas operaciones como búsqueda, sustitución y procesamiento específico de datos en la cadena.

##### Ejemplo en C++:

```cpp
#include <iostream>

// Función que recibe una cadena como argumento e imprime cada carácter
void printString(const char* str) {
    for (int i = 0; str[i] != '\0'; ++i) {
        std::cout << str[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    const char* message = "Hola, mundo!";
    
    // Llamada a la función con una cadena como argumento
    printString(message);

    return 0;
}
```

#### Manipulación y procesamiento de cadenas

Al tratar las cadenas como vectores, se pueden realizar operaciones de manipulación como la inversión de la cadena, la búsqueda y reemplazo de subcadenas, así como la extracción de información específica. Esta capacidad de procesamiento facilita el desarrollo de algoritmos eficientes para tareas relacionadas con el manejo de texto.

### 4.2 E/S de Cadenas

#### Entrada y salida de cadenas

La entrada y salida (E/S) de cadenas es esencial en programas que involucran procesamiento de texto. La capacidad de recibir y mostrar información mediante cadenas de caracteres permite la interacción con el usuario y la lectura de datos desde diversas fuentes, ampliando las posibilidades de aplicación de programas que manipulan texto.

##### Ejemplo en C++:

```cpp
#include <iostream>

int main() {
    // Entrada de una cadena desde el usuario
    char inputString[50];
    std::cout << "Ingrese una cadena: ";
    std::cin >> inputString;

    // ... (resto del código)

    return 0;
}
```

#### Formateo y presentación de datos

El formateo de cadenas es crucial para presentar datos de manera legible y estéticamente agradable. Esta práctica implica controlar la apariencia visual de la salida, utilizando técnicas como el ajuste de anchos y la alineación. El formateo cuidadoso mejora la presentación de la información, haciéndola más comprensible para el usuario.

##### Ejemplo en C++:

```cpp
#include <iostream>
#include <iomanip>

int main() {
    // ... (resto del código)

    // Salida formateada de una cadena
    std::cout << "Cadena ingresada: " << std::setw(20) << std::setfill('-') << inputString << std::endl;

    return 0;
}
```
