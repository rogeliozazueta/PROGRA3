#include <string>
#include <iostream>
#pragma once
#include "Material.h"
using namespace std;

class Disco: public Material
{
    private:
        int duracion;
		    string genero;
    public:
        Disco();
        Disco(int, string, int,string);

        int getduracion();
        void setduracion(int);
        string getgenero();
        void setgenero(string g);
        void muestra();
        int cantidaddiasprestamo();
};

Disco::Disco(): Material()
{
    duracion = 1;
    genero="NONE";
}

Disco::Disco(int idm, string t, int du,string g): Material(idm, t)
{
    duracion = du;
    genero=g;
}

int Disco::getduracion()
{
    return duracion;
}

void Disco::setduracion(int du)
{
    duracion = du;
}

string Disco::getgenero()
{
	
	return genero;
	
}
void Disco::setgenero(string g)
{
	genero=g;
}

void Disco::muestra()
{
    cout << "Disco:" << endl;
    cout << "IdMaterial: " << idmaterial << endl;
    cout << "Titulo: " << titulo << endl;
    cout<< "Genero:"<<genero<<endl;
    cout << "Duracion: " << duracion << endl;
}

int Disco::cantidaddiasprestamo()
{
    return 2;
}
