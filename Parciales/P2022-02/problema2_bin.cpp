#include <iostream>
#include <fstream>
#include <string>
#include <cstring> // strcmp


using namespace std;

struct Nota {
  int identificacion;
  char nombre[50];
  char tipoExamen[20];
  float nota;
};

int main(){
  string nombreArchivo = "notas.dat";

  // Abrir archivo para escritura
  ofstream archivo(nombreArchivo, ios::binary);

  Nota nota1 = {1111, "Juan Perez", "INICIAL", 4.5f};
  archivo.write(reinterpret_cast<char*>(&nota1), sizeof(Nota));
  Nota nota2 = {2222, "Maria Lopez", "SUPLETORIO", 3.5f};
  archivo.write(reinterpret_cast<char*>(&nota2), sizeof(Nota));
  Nota nota3 = {3333, "Pedro Gomez", "INICIAL", 2.5f};
  archivo.write(reinterpret_cast<char*>(&nota3), sizeof(Nota));

  // Cerrar archivo
  archivo.close();

  // Abrir el archivo en modo lectura
  ifstream archivoLectura(nombreArchivo, ios::binary);
  Nota leida;

  while(archivoLectura.read(reinterpret_cast<char*>(&leida), sizeof(Nota))){
    cout << "Identificacion: " << leida.identificacion << endl;
    cout << "Nombre: " << leida.nombre << endl;
    cout << "Tipo de examen: " << leida.tipoExamen << endl;
    cout << "Nota: " << leida.nota << endl;
    
  }

  archivoLectura.close();
}