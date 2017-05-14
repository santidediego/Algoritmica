#include "greedy.h"



	Problema::Problema(int num, vector<vector<double> > m1, vector<vector<double> > m2){
		n=num;
		matriz1=m1;
		matriz2=m2;

	}




	vector<double> Problema::candidatos(const vector<vector<double> >& m){
		vector<double> c;
		int suma=0;



		for(int i=0; i<n; ++i){
			for(int j=0; j<n; ++j){
				suma+=m[i][j];
			}
			c.push_back(suma);
			suma=0;
		}

		return c;
	}

	vector<double> Problema::solucion(){
		vector<double> v1 = candidatos(matriz1);
		vector<double> v2 = candidatos(matriz2);
		vector<double> sol(n);
		int i1, i2;

		for(int i=0; i<n; ++i){
			i1 = funcion_seleccion1(v1);
			i2 = funcion_seleccion2(v2);

			sol[i1]=v2[i2];
			v1[i1]=-1;
			v2[i2]=-1;

		}

		return sol;
	}

	int Problema::funcion_seleccion2(vector<double>& v){
		int min_i=0;

		for(int i=1; i<v.size(); ++i)
			if((v[i] < v[min_i]) || (v[min_i] == -1))
				min_i=i;

		return min_i;
	}

	int Problema::funcion_seleccion1(vector<double>& v){
		int max_i=0;

		for(int i=1; i<v.size(); ++i)
			if(v[i] > v[max_i])
				max_i=i;

		return max_i;
	}



	Problema::Problema()
	{
			n=0;
	}

	Problema::Problema(int num)
	{
			n=num;
			matriz1.resize(n);
			matriz2.resize(n);
			for(int i=0; i<n; i++){
					matriz1[i].resize(n);
					matriz2[i].resize(n);
				}
	}

	Problema& Problema::operator=(const Problema& m)
	{
			n=m.n;
			matriz1 = m.matriz1;
			matriz2 = m.matriz2;

			return *this;
	}

	Problema::Problema(const Problema & m) {
			n = m.n;
			matriz1 = m.matriz1;
			matriz2 = m.matriz2;
	}


	int Problema::getNum()
	{
			return n;
	}

	double Problema::getDato1(int i,int j)
	{
			return matriz1[i][j];
	}

	double Problema::getDato2(int i,int j)
	{
			return matriz2[i][j];
	}

	void Problema::setNum(int i){
			n = i;
	}

	void Problema::setDato1(int i, int j, double d){
			matriz1[i][j] = d;
	}

	void Problema::setDato2(int i, int j, double d){
			matriz2[i][j] = d;
	}

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
									aux.matriz1[i][j]=dato;
							}
					}
					for(int i=0;i<num;i++)
					{
							for(int j=0;j<num;j++)
							{
									is>>dato;
									aux.matriz2[i][j]=dato;
							}
					}
					if (is)
					{
							m=aux;
					}
			}
			return is;
	}

	ostream& operator<<(ostream& os,  Problema& m)
	{
			os << m.getNum() << endl;
			for (int i=0;i<m.n;i++)
			{
					for(int j=0;j<m.n;j++)
					{
							os << m.getDato1(i,j) <<" ";
					}
					os << endl;
			}
			for (int i=0;i<m.n;i++)
			{
					for(int j=0;j<m.n;j++)
					{
							os << m.getDato2(i,j) <<" ";
					}
					os << endl;
			}
			return os;
	}
