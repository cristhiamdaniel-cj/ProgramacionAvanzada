// Ejemplo de archivo binario con registros de tamaño variable
#include <iostream>
#include <fstream>
#include <string>

struct Registro {
    int codigo;
    std::string nombre;
    float salario;
};

int main() {
    std::ofstream archivo("archivo_binario_tamano_variable.bin", std::ios::binary);

    if (archivo.is_open()) {
        Registro registros[] = {
            {1, "Alice", 2500.0f},
            {2, "Bob el Constructor", 3200.0f},
            {3, "Charlie Brown", 2900.0f}
        };

        for (const Registro& reg : registros) { // reg es una referencia const a un elemento del arreglo
            int tamanoNombre = reg.nombre.size(); // Antes de guardar el nombre se debe conocer el tamanio del string
            archivo.write(reinterpret_cast<char*>(&tamanoNombre), sizeof(int)); // convertir la direccion de memoria del tamanio del nombre en un puntero a char
            archivo.write(reg.nombre.c_str(), tamanoNombre); // Escribir el nombre en el archivo
            archivo.write(const_cast<char*>(reinterpret_cast<const char*>(&reg.salario)), sizeof(float)); // conts_cast elimina el calificador "const"
        }

        archivo.close();
    } else {
        std::cerr << "Error al abrir el archivo." << std::endl;
    }

    

    return 0;
}