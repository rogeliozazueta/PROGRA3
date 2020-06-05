#include <string>
#include <iostream>
#pragma once
#include "Material.h"
using namespace std;

class Software: public Material  //CLASE DERIVADA
{
    private:
        string SO;
        int version;

    public:
        Software();
        Software(int idm, string t,int v, string s);

        string getSO();
        void setSO(string s);
        int getversion();
        void setversion(int v);
        
        void muestra();
        int cantidaddiasprestamo();
};

Software::Software(): Material()
{
    SO = "NA";
    version=0;
}

Software::Software(int idm, string t,int v, string s): Material(idm, t)
{
    SO = s;
    version=v;
}

string Software::getSO()
{
    return SO;
}

void Software::setSO(string s)
{
    SO = s;
}
int Software::getversion()
{
	return version;
}

void Software::setversion(int v)
{
	version=v;
}

void Software::muestra()
{
    cout << "Software:" << endl;
    cout << "IdMaterial: " << idmaterial << endl;
    cout << "Titulo: " << titulo << endl;
    cout << "Version:"<<version<<endl;
    cout << "SistemaOper: " << SO << endl;
}

int Software::cantidaddiasprestamo()
{
    return 1;
}
