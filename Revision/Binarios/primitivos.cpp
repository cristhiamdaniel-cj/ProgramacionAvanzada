#include <fstream>
#include <iostream>

int main() {
    // Abre un archivo binario para escritura
    std::ofstream outFile("primitivos.bin", std::ios::binary | std::ios::out);
    if (!outFile) {
        std::cerr << "No se pudo abrir el archivo para escritura." << std::endl;
        return 1; // Finaliza con error
    }

    // Datos primitivos para escribir
    int myInt = 123;
    float myFloat = 456.789f;
    char myChar = 'Z';

    // Imprimir los casting y el tamanio de cada variable
    std::cout << "Casting de variables" << std::endl;
    std::cout << "Entero: " << reinterpret_cast<const char*>(&myInt) << std::endl;
    std::cout << "Flotante: " << reinterpret_cast<const char*>(&myFloat) << std::endl;
    std::cout << "Carácter: " << reinterpret_cast<const char*>(&myChar) << std::endl;

    std::cout << "Tamaño de variables" << std::endl;
    std::cout << "Entero: " << sizeof(myInt) << std::endl;
    std::cout << "Flotante: " << sizeof(myFloat) << std::endl;
    std::cout << "Carácter: " << sizeof(myChar) << std::endl;


    // Escribe los datos primitivos en el archivo
    outFile.write(reinterpret_cast<const char*>(&myInt), sizeof(myInt));
    outFile.write(reinterpret_cast<const char*>(&myFloat), sizeof(myFloat));
    outFile.write(reinterpret_cast<const char*>(&myChar), sizeof(myChar));

    // Cierra el archivo después de escribir
    outFile.close();

    // Abre el archivo binario para lectura
    std::ifstream inFile("primitivos.bin", std::ios::binary | std::ios::in);
    if (!inFile) {
        std::cerr << "No se pudo abrir el archivo para lectura." << std::endl;
        return 1; // Finaliza con error
    }

    // Variables para leer los datos primitivos
    int readInt;
    float readFloat;
    char readChar;

    // Lee los datos primitivos del archivo
    inFile.read(reinterpret_cast<char*>(&readInt), sizeof(readInt));
    inFile.read(reinterpret_cast<char*>(&readFloat), sizeof(readFloat));
    inFile.read(reinterpret_cast<char*>(&readChar), sizeof(readChar));

    // Muestra los datos leídos en consola
    std::cout << "Entero: " << readInt << std::endl;
    std::cout << "Flotante: " << readFloat << std::endl;
    std::cout << "Carácter: " << readChar << std::endl;

    // Cierra el archivo después de leer
    inFile.close();

    return 0;
}
