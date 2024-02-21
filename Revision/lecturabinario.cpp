#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct Registro {
    int codigo;
    std::string nombre;
    float salario;
};

int main() {
    std::ifstream archivo("archivo_binario_tamano_variable.bin", std::ios::binary);
    std::vector<Registro> registrosLeidos;

    if (archivo.is_open()) {
        while (archivo.peek() != EOF) { // Mientras no se llegue al final del archivo
            Registro reg;

            // Leer el tamaño del nombre
            int tamanoNombre;
            archivo.read(reinterpret_cast<char*>(&tamanoNombre), sizeof(int));

            // Leer el nombre
            reg.nombre.resize(tamanoNombre); // Asegurarse de que el string tiene el tamaño adecuado
            archivo.read(&reg.nombre[0], tamanoNombre);

            // Leer el salario
            archivo.read(reinterpret_cast<char*>(&reg.salario), sizeof(float));

            // Agregar el registro leído al vector de registros
            registrosLeidos.push_back(reg);
        }

        archivo.close();

        // Imprimir los registros leídos para verificar
        for (const auto& reg : registrosLeidos) {
            std::cout << "Codigo: " << reg.codigo << ", Nombre: " << reg.nombre << ", Salario: " << reg.salario << std::endl;
        }
    } else {
        std::cerr << "Error al abrir el archivo para lectura." << std::endl;
    }

    return 0;
}
