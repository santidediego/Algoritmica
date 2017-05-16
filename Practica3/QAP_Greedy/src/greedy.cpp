#include "greedy.h"


	// Constructor de copia

	Problema::Problema(int num, vector<vector<double> > m1, vector<vector<double> > m2){
		n=num;
		MatrizHabitaciones=m1;
		MatrizOficinistas=m2;
	}



	/*
	Se pasa una matriz de distacias a habitaciones u de flujo de trabajo de oficinistas y genera el vector 
	de distancias potencial dp entre habitaciones y el de flujos potenciales fp respectivamente.
	Eficiencia: O(n²)
	*/
	vector<double> Problema::candidatos(const vector<vector<double> >& m){
		vector<double> candidatos;
		int suma=0;
		
		for(int i=0; i<n; ++i){			
			for(int j=0; j<n; ++j){		
				suma+=m[i][j];
			}
			candidatos.push_back(suma);
			suma=0;
		}

		return candidatos;
	}

	/*
	Genera los vectores asociados a las matrices que se pasan como parámetros en el Problema.
	Una vez obtenidos los candidatos del Problema, se llama a las funciones de selección y se obtiene
	la solución del mismo asignándolo al atributo solucion.
	Asignamos un centinela (-1) a la lista de candidatos para "eliminarlo" de la misma.
	Eficiencia: O(n²)
	*/

	void Problema::solucionProblema(){
		vector<double> habitaciones = candidatos(MatrizHabitaciones);
		vector<double> oficinistas = candidatos(MatrizOficinistas);
		int i1, i2;

		for(int i=0; i<n; ++i){
			i1 = funcion_seleccion1(habitaciones);
			i2 = funcion_seleccion2(oficinistas);

			solucion[i1]=i2;
			habitaciones[i1]=-1;
			oficinistas[i2]=-1;

		}
	}

	/*
	Se le pasa el vector con el flujo de trabajo entre los oficinistas y 
	devuelve el índice del oficinista con menor flujo.
	Eficiencia: O(n)
	*/

	int Problema::funcion_seleccion2(vector<double>& v){
		int min_i=0;

		for(int i=1; i<v.size(); ++i)
			if((v[i] < v[min_i]) || (v[min_i] == -1))
				min_i=i;

		return min_i;
	}

	/*
	Se le pasa el vector con la distancia entre las habitaciones y 
	devuelve el índice de la habitación con mayor distancia.
	Eficiencia: O(n)
	*/

	int Problema::funcion_seleccion1(vector<double>& v){
		int max_i=0;

		for(int i=1; i<v.size(); ++i)
			if(v[i] > v[max_i])
				max_i=i;

		return max_i;
	}

	// Constructor sin parámetros

	Problema::Problema()
	{
			n=0;
	}

	// Constructor con parámetro tamaño de la matriz NxN

	Problema::Problema(int num)
	{
			n=num;
			MatrizHabitaciones.resize(n);
			MatrizOficinistas.resize(n);
			for(int i=0; i<n; i++){
					MatrizHabitaciones[i].resize(n);
					MatrizOficinistas[i].resize(n);
				}
			solucion.resize(n);
	}

	// Sobrecarga del operador =

	Problema& Problema::operator=(const Problema& m)
	{
			n=m.n;
			MatrizHabitaciones = m.MatrizHabitaciones;
			MatrizOficinistas = m.MatrizOficinistas;
			solucion = m.solucion;

			return *this;
	}

	// Constructor de copia

	Problema::Problema(const Problema & m) {
			n = m.n;
			MatrizHabitaciones = m.MatrizHabitaciones;
			MatrizOficinistas = m.MatrizOficinistas;
			solucion = m.solucion;
	}

	// Getters varios de los atributos de la clase


	int Problema::getNum()
	{
			return n;
	}

	double Problema::getDato1(int i,int j)
	{
			return MatrizHabitaciones[i][j];
	}

	double Problema::getDato2(int i,int j)
	{
			return MatrizOficinistas[i][j];
	}

	// Setters varios de los atributos de la clase

	void Problema::setNum(int i){
			n = i;
	}

	void Problema::setDato1(int i, int j, double d){
			MatrizHabitaciones[i][j] = d;
	}

	void Problema::setDato2(int i, int j, double d){
			MatrizOficinistas[i][j] = d;
	}

	// Devuelve la solución del problema

	vector<double> Problema::getSolucion(){
			return solucion;
	}

	// Lee desde un flujo istream con el formato aconsejado en las prácticas

	istream& operator>>(istream& is, Problema& m)
	{
			while(isspace(is.peek()))
			{
					is.ignore();
			}
			int dato;
			int num;
			is >> num;
			if(is && num>=0)
			{
					Problema aux(num);

					for(int i=0;i<num;i++)
					{
							for(int j=0;j<num;j++)
							{
									is>>dato;
									aux.MatrizHabitaciones[i][j]=dato;
							}
					}
					for(int i=0;i<num;i++)
					{
							for(int j=0;j<num;j++)
							{
									is>>dato;
									aux.MatrizOficinistas[i][j]=dato;
							}
					}
					if (is)
					{
							m=aux;
					}
			}
			return is;
	}

	// Escribe en un flujo ostream la solución del problema

	ostream& operator<<(ostream& os,  Problema& m)
	{
			os << "Habitaciones: ";
    			for (int i=1; i<=m.getNum(); i++)
    				os << i << "  ";
    			os << endl;
			os << "Oficinistas:  ";
    			for (int i=0; i<m.getNum(); i++)
    				os << m.solucion[i]+1 << "  "; //Para que concuerden los índices
    			os << endl;
			return os;
	}
