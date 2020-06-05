#include <string>
#pragma once
#include "Material.h"
using namespace std;

class Material
{
    protected:
        int idmaterial;
        string titulo;

    public:
        Material();
        Material(int idm , string t);

        int getidmaterial();
        string gettitulo();
        void setidmaterial(int idm);
        void settitulo(string t);
        virtual void muestra() = 0;  //funcion virtual (METODO ABSTACTO)
        virtual int cantidaddiasprestamo() = 0;//funcion virtual (METODO ABSTACTO)
};

Material::Material()
{
    idmaterial = 0;
    titulo = "NONE";
}

Material::Material(int idm, string t)
{
    idmaterial = idm;
    titulo = t;
}

int Material::getidmaterial()
{
    return idmaterial;
}

string Material::gettitulo()
{
    return titulo;
}

void Material::setidmaterial(int idm)
{
    idmaterial = idm;
}

void Material::settitulo(string t)
{
    titulo = t;
}
