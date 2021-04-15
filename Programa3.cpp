#include <iostream>
#include <cstring>
#include <string>
#include <fstream>

using namespace std;

int getData(string gate){
  int i;
  char gate_int[gate.length()];
  const char *key="B";
  for(i=0;i<(gate.length()+1);i++){
    gate_int[i]=gate[i];
  }
  char *result=strtok(gate_int,key);
  while(result){
    string comp_address;
    if ((unsigned)strlen(result)>2) for(i=0;i<(unsigned)strlen(result);i++){
      if(comp_address.length()>5) comp_address="";
      comp_address+=result[i];
      comp_address+=result[i+1];
      comp_address+=result[i+2];
      comp_address+=result[i+3];
      comp_address+=result[i+4];
      comp_address+=result[i+5];
      if(comp_address=="F39550") cout << "Procedencia: Medidor de temperatura  |  valor: " << result[i+6] << result[i+7] << endl;
      if(comp_address=="F39577") cout << "Procedencia: Medidor de humedad      |  valor: " << result[i+6] << result[i+7] << result[i+8] << endl;
    }
    result=strtok(NULL, key);
  }
  return 0;
}

int main(){
  start:
  ifstream fileRX;
  fileRX.open("gateRX.txt");
  if(fileRX.fail()){
    cerr << "Error de lectura de archivo, creando una entrada para mostrar el funcionamiento del programa, por favor espere..." << endl;
    ofstream fileRX;
    fileRX.open("gateRX.txt");
    fileRX << "7EB3A50110140F3955025607EB7A50110140F39577301887EB3A50110140F3955026607EB7A50110140F3957730088";
    fileRX << "7EB3A50110140F3955024607EB7A50110140F39577298887EB3A50110140F3955023607EB7A50110140F3957730088";
    fileRX << "7EB3A50110140F3955027607EB7A50110140F39577304887EB3A50110140F3955023607EB7A50110140F3957729788";
    fileRX.close();
    goto start;
  }
  string gateRX;
  fileRX >> gateRX;
  getData(gateRX);
  fileRX.close();
  return 0;
}
