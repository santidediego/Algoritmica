#include "greedy.h"
#include <fstream>
using namespace std;

//Eficiencia: O(n²) donde n es el número de filas/columnas de las matrices utilizadas.

int main(int argc, char *argv[])
{
	if(argc<2){
		cout << "Error en el número de parámetros" << endl;
                return -1;
        }

	ifstream MiArchivo;
	MiArchivo.open (argv[1]);
	Problema problemaQAP;
	MiArchivo >> problemaQAP; //Cargamos el problema desde archivo
	MiArchivo.close();

	problemaQAP.solucionProblema(); //Solucionamos el problema
	cout << problemaQAP; //Mostramos la solución por pantalla

    return 0;
}
