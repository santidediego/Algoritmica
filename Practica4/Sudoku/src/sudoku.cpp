#include "sudoku.h"


	// Constructor de copia

	Problema::Problema(vector<vector<int> > sudo){
		sudoku = sudo;
	}

	//Constructor por defecto, el sudoku tiene todas las casillas vacías(0 indica que la casilla está vacía).

	Problema::Problema(){
		sudoku.resize(TAMANIO);
			for(int i=0; i<TAMANIO; i++){
				sudoku[i].resize(TAMANIO);
			}
	}

        /*Encuentra la siguiente casilla vacía
	*/
	bool Problema::siguiente(int &fila, int &columna){
		bool sig=true;
		while(sig && sudoku[fila][columna]!=0){
			if(columna==(TAMANIO-1)){
				fila=fila+1;
				columna=0;
				if(fila==TAMANIO)
					sig=false;
			}
			else columna=columna+1;
		}
		return sig;
	}

	/*Determina si poner un número en una casilla es válido.
	No debe haber un número igual en la misma fila, columna y cuadrante.
	*/


	bool Problema::podar(int fila, int columna, int num){
		bool poda=false;
		for(int i=0; i<TAMANIO & !poda; i++)
			if(sudoku[i][columna]==num)
				poda = true;
			
		for(int j=0; j<TAMANIO & !poda; j++)
			if(sudoku[fila][j]==num)
				poda = true;
		int cuadrante = TAMANIO/3;
		int fila_cuadrante = (fila/cuadrante)*cuadrante;
		int columna_cuadrante = (columna/cuadrante)*cuadrante;
		for(int i=fila_cuadrante; i<fila_cuadrante+cuadrante & !poda; i++)
			for(int j=columna_cuadrante; j<columna_cuadrante+cuadrante & !poda; j++)
				if(sudoku[i][j]==num)
					poda=true;
		return poda;
	}

	/*Función que soluciona el problema del sudoku.
	*/

	bool Problema::funcion_solucion(int fila, int columna){
		bool terminar = false;
		if(!siguiente(fila,columna))
			terminar = true;
		for(int k=1; k<(TAMANIO+1) & !terminar; k++){
			if(!podar(fila,columna,k)){
				sudoku[fila][columna]=k;
				if(funcion_solucion(fila,columna))
					terminar = true;
				//else{
				//	sudoku[fila][columna]=0;
				//}
			}
		}
		if(!terminar)
			sudoku[fila][columna]=0;
		
		return terminar;
		
	}

	// Sobrecarga del operador =

	Problema& Problema::operator=(const Problema& m)
	{
			sudoku = m.sudoku;

			return *this;
	}

	// Constructor de copia

	Problema::Problema(const Problema & m) {
			sudoku = m.sudoku;
	}

	// Devuelve la solución del problema

	vector<vector<int> > Problema::getSolucion(){
			return sudoku;
	}

	// Lee desde un flujo istream con el formato aconsejado en las prácticas

	istream& operator>>(istream& is, Problema& m)
	{
		int dato;
		for(int i=0;i<m.TAMANIO;i++)
			for(int j=0;j<m.TAMANIO;j++){
				is>>dato;
				m.sudoku[i][j]=dato;
			}
			return is;
	}

	// Escribe en un flujo ostream la solución del problema

	ostream& operator<<(ostream& os,  Problema& m)
	{
		for(int i=0;i<m.TAMANIO;i++){
			for(int j=0;j<m.TAMANIO;j++){
					os << m.sudoku[i][j] << " ";
			}
			os << endl;
		}
    			os << endl;
			return os;
	}
