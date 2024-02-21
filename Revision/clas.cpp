#include <iostream>
#include <math.h>

using namespace std;

int main() {
  /*Inicializa variables*/
  float punto1x;
  float punto1y;
  float punto2x;
  float punto2y;
  double distancia;
  float puntoMediox;
  float puntoMedioy;

  /*Pide coordenadas*/
  cout<<"Ingrese coordenadas x del primer punto:";
  cin>>punto1x;
  cout<<"Ingrese coordenadas y del primer punto:";
  cin>>punto1y;
  cout<<endl;

  cout<<"Ingrese coordenadas x del segundo punto:";
  cin>>punto2x;
  cout<<"Ingrese coordenadas y del segundo punto:";
  cin>>punto2y;
  cout<<endl;

  float punto1[2]={punto1x,punto1y};
  float punto2[2]={punto2x,punto2y};
  
  /*Formula para sacar la distancia entre los puntos*/
  distancia = sqrt(pow(punto2x - punto1x ,2) + pow(punto2y - punto1y ,2));

  /*Formula para sacar el punto medio de la linea que los une*/
  puntoMediox = (punto1x + punto2x)/2;
  puntoMedioy = (punto1y + punto2y)/2;

  /*Imprimir resultados*/
  cout<<"  ("<<punto1x<<","<<punto1y<<") "<<"("<<punto2x<<","<<punto2y<<")"<<endl;
  cout<<"La distancia entre los puntos es: "<<distancia<<endl;  
  cout<<"El punto medio de la linea que los une es: ("<<puntoMediox<<", "<<puntoMedioy<<")"<<endl;
}