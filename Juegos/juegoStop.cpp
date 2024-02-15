#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <iomanip> // Para formatear la salida
#include <limits>
#include <set>

using namespace std;

struct ResultadoRonda {
    char letra;
    double tiempo;
    int puntos;
};

// Genera una letra aleatoria que no ha sido usada anteriormente
char generarLetraAleatoria(set<char>& letrasUsadas) {
    char letra;
    do {
        letra = 'A' + rand() % 26;
    } while (letrasUsadas.find(letra) != letrasUsadas.end());
    letrasUsadas.insert(letra); // Agrega la letra al conjunto de usadas
    return letra;
}

bool iniciaConLetra(const string& palabra, char letra) {
    return !palabra.empty() && toupper(palabra[0]) == toupper(letra);
}

int calcularPuntos(const vector<string>& respuestas, char letra) {
    int puntos = 0;
    for (const auto& respuesta : respuestas) {
        if (iniciaConLetra(respuesta, letra)) {
            puntos += 100;
        } else if (!respuesta.empty()) {
            puntos -= 50;
        }
    }
    return puntos;
}

void imprimirResultados(const vector<ResultadoRonda>& resultados, const string& nombreJugador) {
    cout << "\nResultados finales para " << nombreJugador << ":\n";
    cout << left << setw(10) << "Letra" << setw(20) << "Tiempo (s)" << setw(10) << "Puntos" << endl;
    double tiempoTotal = 0;
    int puntosTotales = 0;

    for (const auto& r : resultados) {
        cout << setw(10) << r.letra << setw(20) << r.tiempo << setw(10) << r.puntos << endl;
        tiempoTotal += r.tiempo;
        puntosTotales += r.puntos;
    }

    cout << setw(10) << "Total" << setw(20) << tiempoTotal << setw(10) << puntosTotales << endl;
}

vector<ResultadoRonda> jugarRonda(const string& nombreJugador, set<char>& letrasUsadas) {
    vector<ResultadoRonda> resultados;
    vector<string> categorias = {"Nombre", "Apellido", "Ciudad", "País", "Fruta", "Objeto", "Animal", "Color"};

    for (int i = 0; i < 5; ++i) {
        char letra = generarLetraAleatoria(letrasUsadas);
        vector<string> respuestas(categorias.size());
        cout << nombreJugador << ", es tu turno. La letra de esta ronda es: " << letra << endl;

        auto inicio = chrono::high_resolution_clock::now();

        for (int j = 0; j < categorias.size(); ++j) {
            cout << "Ingrese un(a) " << categorias[j] << " con la letra " << letra << ": ";
            getline(cin, respuestas[j]);
        }

        auto fin = chrono::high_resolution_clock::now();
        chrono::duration<double> duracion = fin - inicio;

        int puntos = calcularPuntos(respuestas, letra);
        resultados.push_back({letra, duracion.count(), puntos});
    }

    return resultados;
}

// Calcula los totales de puntos y tiempo de un jugador
pair<int, double> calcularTotales(const vector<ResultadoRonda>& resultados) {
    int puntosTotales = 0;
    double tiempoTotal = 0;
    for (const auto& resultado : resultados) {
        puntosTotales += resultado.puntos;
        tiempoTotal += resultado.tiempo;
    }
    return {puntosTotales, tiempoTotal};
}

// Compara los resultados y decide el ganador
void decidirGanador(const string& nombreJugador1, const vector<ResultadoRonda>& resultadosJugador1,
                    const string& nombreJugador2, const vector<ResultadoRonda>& resultadosJugador2) {
    auto [puntosJugador1, tiempoJugador1] = calcularTotales(resultadosJugador1);
    auto [puntosJugador2, tiempoJugador2] = calcularTotales(resultadosJugador2);

    cout << "\nDecidiendo el ganador...\n";
    cout << nombreJugador1 << " - Puntos Totales: " << puntosJugador1 << ", Tiempo Total: " << tiempoJugador1 << "s\n";
    cout << nombreJugador2 << " - Puntos Totales: " << puntosJugador2 << ", Tiempo Total: " << tiempoJugador2 << "s\n";

    if (puntosJugador1 > puntosJugador2 || (puntosJugador1 == puntosJugador2 && tiempoJugador1 < tiempoJugador2)) {
        cout << "El ganador es " << nombreJugador1 << "!" << endl;
    } else if (puntosJugador2 > puntosJugador1 || (puntosJugador1 == puntosJugador2 && tiempoJugador2 < tiempoJugador1)) {
        cout << "El ganador es " << nombreJugador2 << "!" << endl;
    } else {
        cout << "¡Es un empate!" << endl;
    }
}

bool deseaContinuar(const string& nombreJugador) {
    cout << nombreJugador << ", presiona 'Y' y Enter para continuar o cualquier otra tecla y Enter para terminar: ";
    string decision;
    getline(cin, decision);
    return decision == "Y" || decision == "y";
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr))); // Inicialización del generador de números aleatorios

    string nombreJugador1, nombreJugador2;
    cout << "Ingrese el nombre del Jugador 1: ";
    getline(cin, nombreJugador1);
    cout << "Ingrese el nombre del Jugador 2: ";
    getline(cin, nombreJugador2);

    set<char> letrasUsadas; // Conjunto para almacenar las letras ya usadas

    if (!deseaContinuar(nombreJugador1)) {
        cout << nombreJugador1 << " ha decidido no continuar. Fin del juego." << endl;
        return 0;
    }

    auto resultadosJugador1 = jugarRonda(nombreJugador1, letrasUsadas);
    imprimirResultados(resultadosJugador1, nombreJugador1);

    if (!deseaContinuar(nombreJugador2)) {
        cout << nombreJugador2 << " ha decidido no continuar. Fin del juego." << endl;
        return 0;
    }

    auto resultadosJugador2 = jugarRonda(nombreJugador2, letrasUsadas);
    imprimirResultados(resultadosJugador2, nombreJugador2);

    // Decidir el ganador
    decidirGanador(nombreJugador1, resultadosJugador1, nombreJugador2, resultadosJugador2);

    return 0;
}
