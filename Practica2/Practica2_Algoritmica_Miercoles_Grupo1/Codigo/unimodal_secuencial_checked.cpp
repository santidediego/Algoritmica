#include<iostream>
#include<vector>
#include<cstdlib>
#include <ctime>
#include <climits>
#include <cassert>

using namespace std;

int unimodal_secuencial(vector<int> v){
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

int main(int argc, char* argv[]){
  vector<int> array;
  int valor = -1;
	double suma=0;

  int v_size = atoi(argv[1]);
  array.resize(v_size);

for(int i=0; i<20; ++i){
     int p;
     if(i<10)
        p=1;
     else
        p=v_size-2;
  array.at(p) = v_size-1;
  for (int i=0; i<p; i++)
    array.at(i)=i;
  for (int i=p; i<v_size-1; i++)
    array.at(i)=p-(i-p);


  clock_t tantes;
  clock_t tdespues;
  tantes=clock();
  valor = unimodal_secuencial(array);
  tdespues=clock();
	suma += (double)(tdespues - tantes) / CLOCKS_PER_SEC;
}
  cout << v_size <<" "<< suma/100 << endl;
}
