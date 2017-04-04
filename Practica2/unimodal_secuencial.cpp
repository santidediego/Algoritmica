#include<iostream>
#include<vector>
#include<cstdlib>


using namespace std;

int unimodal(vector<int> v){
  bool fin=false;
  int indice=1;

  while(!fin){
     if(v.at(indice+1)<v.at(indice))
        fin=true;
     else
        indice++;
  }
  
  return indice;
}

int main(){
  vector<int> array;

  array.push_back(1);
  array.push_back(5);
  array.push_back(6);
  array.push_back(8);
  array.push_back(1);


  cout << "El vector contiene: " << endl;
  for(int i=0; i < array.size(); i++)
     cout << array.at(i) << endl;


  int valor = unimodal(array);

  cout << "Maximo es: " << array.at(valor) << endl;
}
