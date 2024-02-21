// main.cpp
#include "JuegoStop.h"
#include <set>
#include <string>

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