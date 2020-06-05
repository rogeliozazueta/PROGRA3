#include "Fecha.h"
#pragma once
class Reserva
{
    private:
        int idmaterial;
        int idcliente;
        Fecha fechareservacion;

    public:
        Reserva();
        Reserva(int, int, Fecha);

        int getidmaterial();
        int getidcliente();
        Fecha getfechareservacion();
        void setidmaterial(int);
        void setidcliente(int);
        void setfechareservacion(Fecha);
        Fecha calculafechafinreserva(int);
};

Reserva::Reserva()
{
    idmaterial = 0;
    idcliente = 0;
    Fecha f(0,0,0);
    fechareservacion = f;
}

Reserva::Reserva(int idm, int idc, Fecha f)
{
    idmaterial = idm;
    idcliente = idc;
    fechareservacion = f;
}

int Reserva::getidmaterial()
{
    return idmaterial;
}

int Reserva::getidcliente()
{
    return idcliente;
}

Fecha Reserva::getfechareservacion()
{
    return fechareservacion;
}

void Reserva::setidmaterial(int idm)
{
    idmaterial = idm;
}

void Reserva::setidcliente(int idc)
{
    idcliente = idc;
}

void Reserva::setfechareservacion(Fecha f)
{
    fechareservacion = f;
}

Fecha Reserva::calculafechafinreserva(int d)
{
    return fechareservacion + d;
}
