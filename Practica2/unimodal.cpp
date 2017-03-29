#include<iostream>
#include<vector>

using namespace std;

int unimodal(vector<int> v){
  bool fin=false;
  int tamanio=v.size()-1;
  int indice=tamanio/2;
  while(!fin){
    if(v.at(indice-1)<v.at(indice))
       if(v.at(indice+1)<v.at(indice))
          fin=true;
       else
          indice+=(tamanio-indice)/2;
    else
       indice=(tamanio-indice)/2;
  }
  return indice;
 }

int main(){
  vector<int> array;

  array.push_back(1);
  array.push_back(10);
  array.push_back(3);


  cout << "El vector contiene: " << endl;
  for(int i=0; i < array.size(); i++)
     cout << array.at(i) << endl;


  int valor = unimodal(array);

  cout << "Maximo es: " << array.at(valor) << endl;
}
