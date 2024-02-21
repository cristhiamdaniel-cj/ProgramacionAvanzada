#include <fstream>
#include <iostream> // Incluido para permitir la impresión en consola

int main() {
    // Creación de un objeto ofstream para escritura en archivo binario
    std::ofstream outFile("ejemplo.bin", std::ios::binary | std::ios::out);
    // Verificar si el archivo se abrió correctamente
    if (!outFile) {
        std::cerr << "Error al abrir el archivo para escritura" << std::endl;
        return 1; // Retorna un código de error
    }

    // Escritura de datos en el archivo
    int myData = 123;
    outFile.write(reinterpret_cast<const char*>(&myData), sizeof(myData));

    // Cierre del archivo
    outFile.close();

    // Creación de un objeto ifstream para lectura de archivo binario
    std::ifstream inFile("ejemplo.bin", std::ios::binary | std::ios::in);
    // Verificar si el archivo se abrió correctamente
    if (!inFile) {
        std::cerr << "Error al abrir el archivo para lectura" << std::endl;
        return 1; // Retorna un código de error
    }

    // Lectura de datos del archivo
    int readData;
    inFile.read(reinterpret_cast<char*>(&readData), sizeof(readData));

    // Imprime el dato leído
    std::cout << "Dato leído del archivo: " << readData << std::endl;

    // Cierre del archivo
    inFile.close();

    return 0;
}
