#include "greedy.h"
#include <fstream>
using namespace std;

int main()
{
    ifstream MiArchivo;
    MiArchivo.open ("archivo.txt");
    Problema ejemplo;
    MiArchivo >> ejemplo;
    MiArchivo.close();
		vector<double> solucion;
		solucion = ejemplo.solucion();

    cout << ejemplo.getNum() << endl;
    for (int i=0; i<ejemplo.getNum(); i++)
    	cout << solucion[i] << " ";


    return 0;
}
