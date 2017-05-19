#include "sudoku.h"
#include <fstream>
using namespace std;

//Eficiencia

int main(int argc, char *argv[])
{
	if(argc<2){
		cout << "Error en el número de parámetros" << endl;
                return -1;
        }

	ifstream MiArchivo;
	MiArchivo.open (argv[1]);
	Problema sudoku;
	MiArchivo >> sudoku; //Cargamos el problema desde archivo
	MiArchivo.close();

	sudoku.funcion_solucion(0,0); //Solucionamos el problema
	cout << sudoku; //Mostramos la solución por pantalla

    return 0;
}
