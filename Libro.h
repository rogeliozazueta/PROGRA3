#include <string>
#include <iostream>
#pragma once
#include "Material.h"
using namespace std;

class Libro: public Material
{
    private:
        int numpag;
        string autor;

    public:
        Libro();
        Libro(int idm, string t, int n, string a);

        int getnumpag();
        string getautor();
        void setnumpag(int);
        void setautor(string);
        void muestra();
        int cantidaddiasprestamo();
};

Libro::Libro(): Material()
{
    numpag = 0;
    autor = "NA";
}

Libro::Libro(int idm, string t, int n, string a): Material(idm, t)
{
    numpag = n;
    autor = a;
}

int Libro::getnumpag()
{
    return numpag;
}

string Libro::getautor()
{
    return autor;
}

void Libro::setnumpag(int n)
{
    numpag = n;
}

void Libro::setautor(string a)
{
    autor = a;
}

void Libro::muestra()
{
    cout << "Libro:" << endl;
    cout << "IdMaterial: " << idmaterial << endl;
    cout << "Titulo: " << titulo << endl;
    cout << "NumPag: " << numpag << endl;
    cout << "Autor: " << autor << endl;
}

int Libro::cantidaddiasprestamo()
{
    return 7;
}
