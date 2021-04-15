#include <iostream>

using namespace std;

int main(){
  int i, veces=0;
  string palabra, caracter, compar;
  cout << "Ingrese la cadena de caracteres: " << endl;
  getline(cin, palabra);
  cout << "Ingrese caracter a buscar: " << endl;
  getline(cin, caracter);
  for(i=0;i<palabra.size();i++){
    compar=palabra[i];
    if(caracter==compar) veces++;
  }
  cout << "La letra se encuentra " << veces << " veces en la cadena de caracteres" << endl;
  return 0;
}
