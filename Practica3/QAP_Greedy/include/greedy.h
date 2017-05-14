#include<iostream>
#include<vector>

using namespace std;


class Problema{

private:
	vector<vector<double> > matriz1;
	vector<vector<double> > matriz2;
	int n;
        vector<double> solucion;

public:

	Problema(int n, vector<vector<double> > m1, vector<vector<double> > m2);

	Problema();

	Problema(int num);

	Problema(const Problema & m);

	int getNum();

	Problema& operator=(const Problema& m);

	vector<double> candidatos(const vector<vector<double> >& m);

	void solucionProblema();

	int funcion_seleccion2(vector<double>& v);

	int funcion_seleccion1(vector<double>& v);

	double getDato1(int i,int j);

	double getDato2(int i,int j);

	void setNum(int i);

	void setDato1(int i, int j, double d);

	void setDato2(int i, int j, double d);

	vector<double> getSolucion();

	friend istream& operator>>(istream& is, Problema& m);

	friend ostream& operator<<(ostream& os,  Problema& m);



};
