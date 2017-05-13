#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
using namespace std;

class Prueba
{
    vector<vector<double> > matriz1;
    vector<vector<double> > matriz2;
    int n;

    public:
    Prueba()
    {
        n=0;
    }

    Prueba(int num)
    {
        n=num;
        matriz1.resize(n);
        matriz2.resize(n);
        for(int i=0; i<n; i++){
            matriz1[i].resize(n);
            matriz2[i].resize(n);
          }
    }

    Prueba& operator=(const Prueba& m)
    {
        n=m.n;
        matriz1 = m.matriz1;
        matriz2 = m.matriz2;

        return *this;
    }

    Prueba(const Prueba & m) {
        n = m.n;
        matriz1 = m.matriz1;
        matriz2 = m.matriz2;
    }


    int getNum()
    {
        return n;
    }

    double getDato1(int i,int j)
    {
        return matriz1[i][j];
    }

    double getDato2(int i,int j)
    {
        return matriz2[i][j];
    }

    void setNum(int i){
        n = i;
    }

    void setDato1(int i, int j, double d){
        matriz1[i][j] = d;
    }

    void setDato2(int i, int j, double d){
        matriz2[i][j] = d;
    }

    friend istream& operator>>(istream& is, Prueba& m)
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
            Prueba aux(num);

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

    friend ostream& operator<<(ostream& os,  Prueba& m)
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
};


int main()
{
    ifstream MiArchivo;
    MiArchivo.open ("archivo.txt");
    Prueba ejemplo;
    MiArchivo >> ejemplo;
    MiArchivo.close();

    cout << ejemplo.getNum() << endl;
    for (int i=0; i<ejemplo.getNum(); i++)
    {
        for(int j=0; j<ejemplo.getNum(); j++)
            cout<<ejemplo.getDato1(i,j)<<" ";
        cout<<endl;
    }
    for (int i=0; i<ejemplo.getNum(); i++)
    {
        for(int j=0; j<ejemplo.getNum(); j++)
            cout<<ejemplo.getDato2(i,j)<<" ";
        cout<<endl;
    }


    return 0;
}
