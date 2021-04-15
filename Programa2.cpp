#include <iostream>
#include <cstring>
using namespace std;

int main(){
  int i, aux;
  string palabra, resultado, pm;
  cout << "Ingrese la cadena de caracteres: " << endl;
  getline(cin, palabra);
  aux=palabra[0];
  for(i=0;i<palabra.size();i+=2){
    pm=palabra[i];
    aux=stoi(pm);
    string juntar(aux, palabra[i+1]);
    resultado+=juntar;
  }
  cout << "El resultado es: " << resultado << endl;
  return 0;
}
