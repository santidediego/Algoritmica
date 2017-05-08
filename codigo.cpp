#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
using namespace std;

class Prueba
{
    vector<vector<double>> matriz;
    int n;

    public: 
    Prueba()
    {
        this->n=0;
    }

    Prueba(int num)
    {
        this->n=num;
        matriz.resize(n);
        for(int i=0; i<n; i++)
            matriz[i].resize(n);
    }

    Prueba& operator=(const Prueba& m)
    {
        n=m.n;
        m.matriz.resize(n);
        for(int i=0;i<n;i++)
        {
            m.matriz[i].resize(n);
        }
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                    matriz[i][j]=m.matriz[i][j];

        return *this;
    }

    int getNum()
    {
        return n;
    }

    double getDato(int i,int j)
    {
        return matriz[i][j];
    }

    void setNum(int i){
        n = i;
    }

    void setDato(int i, int j, double d){
        matriz[i][j] = d;
    }

    friend istream& operator>>(istream& is,  Prueba& m)
    {
        while(isspace(is.peek())) //Ignoramos los blancos
        {
            is.ignore();
        }
        int dato;
        int num;
        is>>num;
        if(is && num>=0)
        {
            Prueba aux(num);

            for(int i=0;i<num;i++)
            {
                for(int j=0;j<num;j++)
                {
                    is>>dato;
                    aux.matriz[i][j]=dato;
                }
            }
            if (is)
            {
                m=aux;
            }
        }
        return is;
    }

    friend ostream& operator<<(ostream& os,  const Prueba& m)
    {
        os<<m.getNum()<<endl;
        for (int i=0;i<m.n;i++)
        {
            for(int j=0;j<m.n;j++)
            {
                os<<m.getDato(i,j)<<" ";
            }
            os<<endl;
        }
        return os;
    }
};


int main()
{
    Prueba ejemplo(3);
    cout << ejemplo.getNum() << endl;
    for (int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            ejemplo.setDato(i,j,2);
    for (int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
            cout<<ejemplo.getDato(i,j)<<" ";
        cout<<endl;
    }

        
    return 0;
}