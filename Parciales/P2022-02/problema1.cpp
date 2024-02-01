#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Funcion para encriptar un caracter
char encriptarCaracter(char c){
  if(c >= 'a' && c <= 'z'){
    return 'z' - (c - 'a');
  } else if (c >= 'A' && c <= 'Z'){
    return 'Z' - (c - 'A');
  } 
  return c;
}
// Funcion para desencriptar un caracter
char desencriptarCaracter(char c){
  if(c >= 'a' && c <= 'z'){
    return 'a' + ('z' - c);
  } else if (c >= 'A' && c <= 'Z'){
    return 'A' + ('Z' - c);
  } 
  return c;
}
// Funcion generica para transformar el mensaje
string transformarMensaje(const string& mensaje, char (*transformar)(char)){
  string resultado;
  for (char c: mensaje){
    resultado += transformar(c);
  }
  return resultado;
}

int main(){
  // Nombre del archivo a leer
  string nombreArchivo = "datos.txt";
  //Variable para almacenar el contenido del archivo
  string contenido;
  // Variable para almacenar cada linea leida
  string linea;

  // Abrir el archivo en modo lectura
  ifstream archivo(nombreArchivo);

  // Verificar si el archivo se abrio correctamente
  if(!archivo.is_open()){
    cerr << "Error al abrir el archivo" << nombreArchivo << endl;
    return 1;
  }

  // Leer el contenido del archivo
  while (getline(archivo, linea)){
    contenido += linea + "\n";
  }

  // Cerrar el archivo
  archivo.close();

  // Iprimir el contenido del archivo
  // cout << "Contenido del archivo: " << nombreArchivo << endl;
  // cout << contenido << endl;

  // Validar la funcion de encriptacion
  // cout << encriptarCaracter('b') << endl;
  // Validar la funcion de desencriptacion
  // cout << desencriptarCaracter('c') << endl;

  // Encriptar el mensaje
  string mensajeEncriptado = transformarMensaje(contenido, encriptarCaracter);
  // Desecriptar el mensaje
  string mensajeDesencriptado = transformarMensaje(mensajeEncriptado, desencriptarCaracter);
  cout << "Mensaje desencriptado: " << mensajeDesencriptado << endl;
  
  // Guardar el mensaje encriptado en un archivo encriptado.txt
  ofstream archivoEncriptado("encriptado.txt");
  if(!archivoEncriptado.is_open()){
    cerr << "Error al abrir el archivo encriptado.txt" << endl;
  } else {
    archivoEncriptado << mensajeEncriptado;
    archivoEncriptado.close();
  }
    
    
  return 0;
}