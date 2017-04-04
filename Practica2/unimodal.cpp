#include<iostream>
#include<vector>

using namespace std;

int unimodal(vector<int> v){
  bool fin=false;
  int tamanio=v.size()-1;
  int indice=tamanio/2;
	int aux;
	int contador=0;
  while(!fin){
    if(v.at(indice-1)<v.at(indice))
       if(v.at(indice+1)<v.at(indice))
          fin=true;
       else
          indice+=(tamanio-indice)/2;
    else{
			aux=tamanio;
			tamanio=indice;
    	indice=(aux-indice)/2;
	 	}
		contador++;
  }
	cout << "El contador es: " << contador << endl;
  return indice;
 }

int main(){
  vector<int> array;

int tamanio=16;
int posicion=9;
for (int i=0, j=0; i<tamanio;i++,j--){
	if(i<=posicion)
	   array.push_back(i);
	else
	   array.push_back(j);
}


  cout << "El vector contiene: " << endl;
  for(int i=0; i < array.size(); i++)
     cout << array.at(i) << endl;


  int valor = unimodal(array);

  cout << "Maximo es: " << array.at(valor) << endl;
}
