#include<iostream>
#include<vector>
#include<cstdlib>
#include <ctime>
#include <climits>
#include <cassert>

using namespace std;

int unimodal(vector<int> v){
  bool fin=false;
  int maximo=v.size()-1;
  int indice=maximo/2;
	int minimo=0;
  while(!fin){
    if(v.at(indice-1)<v.at(indice))
       if(v.at(indice+1)<v.at(indice))
          fin=true;
       else{
				  minimo=indice;
          indice=indice+((maximo-indice)/2);
			 }
    else{
			maximo=indice;
    	indice=minimo+((indice-minimo)/2);
	 	}
  }
  return indice;
 }

int main(int argc, char *argv[]){
  vector<int> array;
  int valor = -1;
	double suma=0;

  int v_size = atoi(argv[1]);
  array.resize(v_size);
for(int i=0; i<20; ++i){
     int p;
     if(i<10)
        p=(v_size-1)/2;
     else
        p=v_size-2;
     array.at(p) = v_size-1;
     for (int i=0; i<p; i++)
        array.at(i)=i;
     for (int i=p+1; i<v_size; i++)
        array.at(i)=v_size-1-i+p;


  clock_t tantes;
  clock_t tdespues;
  tantes=clock();
  valor = unimodal(array);
  tdespues=clock();
	suma+=(double)(tdespues - tantes) / CLOCKS_PER_SEC;
}
  cout << v_size <<" "<< suma/100 << endl;
}
