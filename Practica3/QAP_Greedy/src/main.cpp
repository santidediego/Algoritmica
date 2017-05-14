#include "greedy.h"
#include <fstream>
using namespace std;

int main()
{
    ifstream MiArchivo;
    MiArchivo.open ("dat/matrices.dat");
    Problema problemaQAP;
    MiArchivo >> problemaQAP; //Cargamos el problema desde archivo
    MiArchivo.close();

    problemaQAP.solucionProblema(); //Solucionamos el problema
    cout << problemaQAP; //Mostramos la solución por pantalla

    return 0;
}
