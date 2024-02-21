#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
#include <limits>

// Dibujos del ahorcado como arreglos de cadenas
const std::string fallos[] = {
    "  !===N\n      N\n      N\n      N\n======",
    "  !===N\n  0   N\n      N\n      N\n======",
    "  !===N\n _0   N\n      N\n      N\n======",
    "  !===N\n _0_  N\n      N\n      N\n======",
    "  !===N\n _0_  N\n  |   N\n      N\n======",
    "  !===N\n _0_  N\n  |   N\n /    N\n======",
    "  !===N\n _0_  N\n  |   N\n / \\  N\n======"
};

// Función para seleccionar una palabra al azar
std::string seleccionar_palabra(const std::vector<std::string>& palabras) {
    srand(time(nullptr)); // Semilla para la generación de números aleatorios
    int indice = rand() % palabras.size();
    return palabras[indice];
}

// Función para mostrar el estado actual del juego
void mostrar_tablero(int intentos, const std::string& letras_correctas, const std::string& palabra) {
    std::cout << fallos[intentos] << std::endl;
    for (char letra : palabra) {
        std::cout << (letras_correctas.find(letra) != std::string::npos ? letra : '_') << ' ';
    }
    std::cout << std::endl;
}

// Función para solicitar y validar una letra del usuario
char solicitar_letra(const std::string& letras_todas) {
    std::string entrada;
    while (true) {
        std::cout << "Dime una letra: ";
        std::getline(std::cin, entrada); // Lee una línea completa
        // Convierte la entrada a mayúsculas y verifica si es válida
        if (entrada.length() == 1) {
            char letra = toupper(entrada[0]);
            if (letras_todas.find(letra) != std::string::npos) {
                std::cout << "Esa letra ya la has dicho." << std::endl;
            } else if (!isalpha(letra)) {
                std::cout << "Introduce una letra válida." << std::endl;
            } else {
                return letra;
            }
        } else {
            std::cout << "Por favor, introduce una sola letra." << std::endl;
        }
    }
}

// Función principal para ejecutar el juego del ahorcado
void juego_del_ahorcado(const std::vector<std::string>& palabras) {
    std::string palabra = seleccionar_palabra(palabras);
    std::string letras_correctas = "";
    std::string letras_todas = "";
    int intentos = 0;

    while (intentos < sizeof(fallos)/sizeof(fallos[0]) - 1) {
        mostrar_tablero(intentos, letras_correctas, palabra);

        char letra = solicitar_letra(letras_todas);
        letras_todas += letra;

        if (palabra.find(letra) != std::string::npos) {
            letras_correctas += letra;
            bool ha_ganado = true;
            for (char letra_palabra : palabra) {
                if (letras_correctas.find(letra_palabra) == std::string::npos) {
                    ha_ganado = false;
                    break;
                }
            }
            if (ha_ganado) {
                mostrar_tablero(intentos, letras_correctas, palabra);
                std::cout << "¡Has ganado! La palabra era: " << palabra << std::endl;
                return;
            }
        } else {
            intentos++;
        }

        if (intentos == sizeof(fallos)/sizeof(fallos[0]) - 1) {
            mostrar_tablero(intentos, letras_correctas, palabra);
            std::cout << "Has perdido. La palabra era: " << palabra << std::endl;
            return;
        }
    }
}

int main() {
    std::vector<std::string> palabras = {"PYTHON", "JAVA", "RUBY", "JAVASCRIPT"};
    juego_del_ahorcado(palabras);
    return 0;
}
