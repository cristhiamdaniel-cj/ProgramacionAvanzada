#include <iostream>
#include <vector>
#include <algorithm> // Para std::shuffle
#include <random>    // Para std::default_random_engine
#include <chrono>    // Para std::chrono::system_clock
#include <iomanip>   // Para std::setw
#include <fstream>

using namespace std;

void generarArchivoRespuestas(const vector<vector<int>>& tablero, const string& nombreArchivo) {
    ofstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo para escribir las respuestas." << endl;
        return;
    }

    for (const auto& fila : tablero) {
        for (const auto& valor : fila) {
            archivo << valor << " ";
        }
        archivo << "\n";
    }
    archivo.close();
    cout << "Archivo de respuestas generado: " << nombreArchivo << endl;
}

void inicializarTablero(vector<vector<int>>& tablero, int filas, int columnas) {
    int totalCartas = filas * columnas;
    int carta = 1;
    for (int i = 0; i < totalCartas; i += 2) {
        tablero[i / columnas][i % columnas] = carta;
        tablero[(i + 1) / columnas][(i + 1) % columnas] = carta;
        carta++;
    }

    // Mezclar el tablero
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle(begin(tablero[0]), end(tablero[0]), default_random_engine(seed));
}

void mostrarTablero(const vector<vector<int>>& tablero, const vector<vector<bool>>& reveladas) {
    for (int i = 0; i < tablero.size(); ++i) {
        for (int j = 0; j < tablero[i].size(); ++j) {
            if (reveladas[i][j]) {
                cout << setw(2) << tablero[i][j] << " ";
            } else {
                cout << setw(2) << "*" << " ";
            }
        }
        cout << "\n";
    }
}

bool comprobarFinJuego(const vector<vector<bool>>& reveladas) {
    for (const auto& fila : reveladas) {
        for (bool cartaRevelada : fila) {
            if (!cartaRevelada) {
                return false;
            }
        }
    }
    return true;
}

void elegirCarta(int& x, int& y, const vector<vector<bool>>& reveladas) {
    do {
        cout << "Elige una carta (fila y columna): ";
        cin >> x >> y;
        if (reveladas[x][y]) {
            cout << "Esta carta ya ha sido revelada. Elige otra carta.\n";
        }
    } while (reveladas[x][y]); // Repetir hasta que se elija una carta no revelada.
}

int main() {
    int filas = 4, columnas = 4; // Asumimos un tablero de 4x4 para simplificar
    vector<vector<int>> tablero(filas, vector<int>(columnas));
    vector<vector<bool>> reveladas(filas, vector<bool>(columnas, false));

    inicializarTablero(tablero, filas, columnas);
    generarArchivoRespuestas(tablero, "respuestasMemorama.txt");

    int x1, y1, x2, y2;
    while (!comprobarFinJuego(reveladas)) {
        mostrarTablero(tablero, reveladas);

        elegirCarta(x1, y1, reveladas); // Elegir la primera carta
        reveladas[x1][y1] = true; // Revelar temporalmente la primera carta
        mostrarTablero(tablero, reveladas);

        elegirCarta(x2, y2, reveladas); // Elegir la segunda carta

        if (tablero[x1][y1] == tablero[x2][y2]) {
            cout << "¡Encontraste una pareja!\n";
            reveladas[x2][y2] = true; // Revelar permanentemente la segunda carta
        } else {
            cout << "No son una pareja. Intenta de nuevo.\n";
            reveladas[x1][y1] = false; // Ocultar la primera carta nuevamente
            // La segunda carta no se revela permanentemente, así que no necesita ser ocultada nuevamente aquí.
        }
    }

    cout << "¡Felicidades! Has completado el juego.\n";
    return 0;
}
