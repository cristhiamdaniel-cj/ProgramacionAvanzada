#include <iostream>
using namespace std;

int main() {
  int arr[3] = {10, 20, 30};
  int* ptr = arr;

  cout << sizeof(arr) << endl; // Muestra el tamaño total del array en bytes, por ejemplo, 12 en un sistema donde int es de 4 bytes
  cout << sizeof(ptr) << endl; // Muestra el tamaño del apuntador, por ejemplo, 8 en un sis

    return 0;
}