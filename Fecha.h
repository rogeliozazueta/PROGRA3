#pragma once
#include <iostream>
#include <string>
using namespace std;

class Fecha
{
    private:
        int dd;
        int mm;
        int aa;
        bool Bisiesto();
        string nombreMes();

    public:
        Fecha();
        Fecha(int, int, int);

        int getano();
        int getdia();
        int getmes();
        void setano(int);
        void setdia(int);
        void setmes(int);
        void setfecha(int, int, int);
        Fecha operator+(int);
        bool operator>=(Fecha);
        bool operator<=(Fecha);
        bool operator>(Fecha);
        bool operator<(Fecha);
        bool operator==(Fecha);
        friend istream  &operator>>(istream &os, Fecha &f);
        friend ostream  &operator<<(ostream &os, Fecha f);
};

Fecha::Fecha()
{
    dd = 0;
    mm = 0;
    aa = 0;
}

Fecha::Fecha(int d, int m, int a)
{
    dd = d;
    mm = m;
    aa = a;
}

int Fecha::getano()
{
    return aa;
}

int Fecha::getdia()
{
    return dd;
}

int Fecha::getmes()
{
    return mm;
}

void Fecha::setano(int a)
{
    aa = a;
}

void Fecha::setdia(int d)
{
    dd = d;
}

void Fecha::setmes(int m)
{
    mm = m;
}

void Fecha::setfecha(int d, int m, int a)
{
    dd = d;
    mm = m;
    aa = a;
}

Fecha Fecha::operator+(int d)   //nos decide los dias respectivos al mes y al ano si el ano es bisiesto para ver como se sumaran los objetos tipo fecha
                              // ejemplo ingreso la fecha  31 de enero de 2019    fecha en la que esta reservado un libro entonces en base al mes establecera que enero tiene 31 dias por lo que los 7 dias de reservacion  fecha = fecha + (d - ndm)   31 + 7-31 =7 por lo que la fecha de fin reserva quedaria  en  07 febrero 2019  .. se encarga de este tipo de verificaciones en meses febrero , anos l 
{
    int ddaux = dd;
    int mmaux = mm;
    int aaaux = aa;
    int ndm;
    bool check = false;
    Fecha fecha(ddaux, mmaux, aaaux);

    switch (mmaux)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        
        if (ddaux + d > 31)
        { check = true; ndm = 31; }
        break;

        case 2:
        if (this -> Bisiesto())  //compureba si el ano es bisisesto o no para determinar los dias del mes de febrero 
       
       { 
         
        if (ddaux + d > 29)

       { check = true; ndm = 29; }
       
       }
        
      else
      { if (ddaux + d > 28)
        { check = true; ndm = 28;}
      
      }
            break;

        case 4:
        case 6:
        case 9:
        case 11:
      
      if (ddaux + d > 30)
      { check = true; ndm = 30;}
        break;

      case 12:
      if (ddaux + d > 31)
            {                        // aumenta el ano en caso del ser 31 de dic
                check = true;
                ndm = 31;
                mmaux = 0;
                aaaux++;
                aaaux %= 100;
                fecha.setano(aaaux);
            }
            break;
    }
    if (check)
    {               
        mmaux++;   // le sube al mes 
        fecha.setmes(mmaux);     //setea el mes
        fecha = fecha + (d - ndm);     // a los dias ingresados  les resta los dias del mes para que no se pase
    }
    else
    {
        // si no se pasan solo los incremena
        ddaux += d;
        fecha.setdia(ddaux);
    }
    return fecha;
}

bool Fecha::operator>=(Fecha f)    //REALIZAR CONSULTAS MAYOR O IGUAL de fechas para saber sobre las reservaciones
{
    if (aa > f.getano())  //COMPARA ANO PARA VER SI ES MAYOR 
    {
        return true;    
    }
    else if (aa == f.getano())   //VERIFICA QUE SEAN IGUALES
    {
        if (mm > f.getmes())  // REVISA EL MES EN CASO DE SER IGUALES LOS ANOS
        {
            return true;
        }
        else if (mm == f.getmes())  // VERIFICA LOS MESES SEAN IGUALES SI NO FUERON MAYORES
        {
            if (dd >= f.getdia())  // VERIFICA SI LOS DIAS SON MAYORES O IGUALES
            {
                return true;
            }
        }
    }
    return false;  // SI NO FUE MAYOR NI IGUAL REGRESA FALSO
}

bool Fecha::operator<=(Fecha f)
{
    
    if (aa < f.getano())
    {
        return true;
    }
    else if (aa == f.getano())
    {
        if (mm < f.getmes())
        {
            return true;
        }
        else if (mm == f.getmes())
        {
            if (dd <= f.getdia())
            {
                return true;
            }
        }
    }
    return false;
  
}

bool Fecha::operator>(Fecha f)  //constulata de fecha para saber si es mayor de fechas para saber sobre las reservaciones
{
    if(aa >= f.getano() && mm >= f.getmes() && dd > f.getdia()) //VA VERIFICANDO ANO , MES Y AL FINAL DIAS PARA VER SI ES MAYOR
    {
      return true;
    }
    else
    {
      return false;
    }
}

bool Fecha::operator<(Fecha f) //VA VERIFICANDO ANO , MES Y AL FINAL DIAS PARA VER SI ES MENOR
{
  if(aa <= f.getano() && mm <= f.getmes() && dd < f.getdia())
  {
      return true;  
  }
  else
  {
    return false;
  }
}  

bool Fecha::operator==(Fecha f)
{
    if(aa == f.getano() && mm == f.getmes() && dd == f.getdia()) //verifica que todos sean iguales
    {
      return true;
    }
    else
    {
      return false;
    }
}

istream &operator>>(istream &os, Fecha &f)  //declaracion de sobre carga operador  de cin 
{
    cout << "Dia (DD): ";
    os >> f.dd;  //dia de mi fecha
    cout << "Mes (MM): ";
    os >> f.mm;  // mes de mi fecha
    cout << "Ano (AA): ";
    os >> f.aa; // ano de mi fecha
    return os;
}

ostream &operator<<(ostream &os, Fecha f)
{   //da formato 09/dic/09           sobre carga de operador de cout 
    if (f.dd < 10)
    {
        os << '0';
    }
    os << f.dd << '/' << f.nombreMes() << '/';
    if (f.aa < 10)
    {
        os << '0';
    } 
    os << f.aa;
    return os;  


}




bool Fecha::Bisiesto()  //ano bisiesto 
{
    return ((aa % 4 == 0 && aa % 100 != 0) || aa % 400 == 0);
    
  
}

string Fecha::nombreMes()
{
    switch (mm)
    {
    case 1: return "Ene";break;
    case 2: return "Feb";break;
    case 3: return "Mar";break;
    case 4: return "Abr";break;
    case 5: return "May";break;
    case 6: return "Jun";break;
    case 7: return "Jul";break;
    case 8: return "Ago";break;
    case 9: return "Sep";break;
    case 10: return "Oct";break;
    case 11: return "Nov";break;
    case 12: return "Dic";break;
    }
    return " No existe el mes";
}
