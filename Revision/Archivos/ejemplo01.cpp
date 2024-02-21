#include <iostream>
#include <fstream>

int main() {
    // Abrir un archivo para escritura
    std::ofstream archivoSalida("salida.txt");

    if (archivoSalida.is_open()) {
        archivoSalida << "Este es un archivo de salida." << std::endl;
        archivoSalida << "Puedes escribir datos en él." << std::endl;
        archivoSalida.close(); // Cerrar el archivo
    } else {
        std::cerr << "Error al abrir el archivo de salida." << std::endl;
    }

    // Abrir un archivo para lectura
    std::ifstream archivoEntrada("entrada.txt");

    if (archivoEntrada.is_open()) {
        std::string linea;
        while (std::getline(archivoEntrada, linea)) {
            std::cout << linea << std::endl;
        }
        archivoEntrada.close(); // Cerrar el archivo
    } else {
        std::cerr << "Error al abrir el archivo de entrada." << std::endl;
    }

    return 0;
}