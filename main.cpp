#include "Material.h"
#include "Reserva.h"
#include "Fecha.h"
#include "Libro.h"
#include "Disco.h"
#include "Software.h"

#include <fstream>
#include <string>
#include <iostream>
using namespace std;

int main()
{
        
    
     Material* material[30]; // arreglo de apuntadores a objetos de tipo material

     ///Una variable apuntador de la clase base puede apuntar a un objeto de la clase derivada.

    int cont1 = 0; // contador de cantidad de material
    int idmaterial, numpag, duracion,version; //variables lectura archivo
    string title, autor, SO,genero;
    char LDS; // Nos detecta el tipo de material al leer
    
    ifstream ArchEnt;
    ArchEnt.open("Material.txt"); // apertura del archivo
    while (!ArchEnt.eof() && ArchEnt >> idmaterial >> title >> LDS) //mientras que el archivo no se cierre y encuentre tales datos (formato del txt material)
    {
          //va buscando y almacenando
        
            if(LDS == 'L')
               {  ArchEnt >> numpag >> autor;
                  material[cont1] = new Libro(idmaterial, title, numpag, autor); //variable dinamica 
                  //material (clase padre) , Libro , Disco , Software hijas  
                  // va guardando en el arreglo  los disintos tipos de material 
               } 
            else if(LDS =='D')
                { ArchEnt >>duracion>>genero;
                  material[cont1] = new Disco(idmaterial, title, duracion,genero);
                }
            else if(LDS == 'S')
                 { ArchEnt >>version>> SO;
                   material[cont1] = new Software(idmaterial, title,version,SO);
                 }                    
        ++cont1; // va contando los materiales ingresados
        
    }
    ArchEnt.close();

    ///////////////////////////////////////////////////////////////////////////////
    Reserva reservaciones[60];  //arreglo de tipo Reserva 
    int cont2 = 0;  // nos va contando las reservaciones
    int dia, mes, ano, idcliente; //variables que nos permiten ir leyendo el txt
    ifstream ArchEntr2;  //apertura del archivo
    ArchEntr2.open("Reserva.txt");
    while (!ArchEntr2.eof()&&ArchEntr2 >> dia >> mes >> ano >> idmaterial >> idcliente) //mientras que el archivo no se cierre y encuentre tales datos (formato del txt material)
    {
        reservaciones[cont2] = Reserva(idmaterial, idcliente, Fecha(dia, mes, ano%2000)); // va guardando objetos de tipo reserva en el arreglo  , Fecha se ingresa atraves de  la clase Fecha que esta en composicion con reserva
        ++cont2; // nos cuenta las reservaciones
      
    }
    ArchEntr2.close();

    //////////////////////////////////////////////////////////////////////////////
  
    int J, K; //variables para for 
    Material* aMaterial;  //apuntador a tipo material
    bool checkid, checkfecha,checkidc; // variables que nos ayudan a verificar y comprobar que existan ids etc
    char opcion;  // controlar el menu (opciones)
    Fecha fecha; //usado en opcion e
    do
    {
        system("cls"); 
        cout << "MENU" << endl;
        cout << "a) Consultar la lista de Materiales." << endl;
        cout << "b) Consultar la lista de reservaciones." << endl;
        cout << "c) Consultar las reservaciones de un material dado." << endl;
        cout << "d) Consultar las reservaciones de una fecha dada." << endl;
        cout << "e) Hacer una reservacion." << endl;
        cout << "f) Terminar." << endl;
        cout << "Porfavor ingrese una opcion:   ";
        cin >> opcion;
        switch (opcion)
        {
               //a. Consultar la lista de Materiales. Que muestre todos los datos de cada material.

            case 'a':
                for (J = 0; J < cont1; ++J)   //recorr el arreglo de apuntadores a objetos de tipo material
                {
                    material[J] -> muestra(); 
                    // el tipo objeto se va guarado en el apuntador de tipo material y usando la funcion virtual de material pero usamos una funcion virtual la cual al usar una función virtual, el tipo del objeto apuntado, y no el tipo del apuntador, es el que determina cual versión de la función utilizar (la de la clase base o la de la clase derivada).
                    cout<<"---------------------------"<<endl;
                    cout<<endl;
                }
                system("pause>nul");
                break;


          case 'b':
                for (J = 0; J < cont2; ++J)
                {
                        //verificacion                  
                    for (K = 0; K < cont1; ++K)
                    {
                        //verifica que el idmaterial de reservaciones txt este en el idmaterial de materiales txt
                        if (reservaciones[J].getidmaterial() == material[K] -> getidmaterial())  //Verificacion de que en ambos existan en ambos archivos
                           {
                            aMaterial = material[K]; //lo guarda en otro apuntador a material
                           }
                    }
                      //el entero de calcula fecha fin reserva se encuentra en la cantidaddiasdeprestamo de cada clase derivada  entonces dependiendo del material agrega a la fecha final
                    cout << "reservacion:" << endl;
                    cout << "fecha de inicio: ";
                    cout << reservaciones[J].getfechareservacion() << endl;  //carga de operador
                    cout << "fecha de terminacion: ";
                    //muestra la fecha terminacion mediante la funcion virtual llamada por el apuntador
                    cout << reservaciones[J].calculafechafinreserva(aMaterial -> cantidaddiasprestamo()) << endl;
                    cout << "material: ";
                    cout << aMaterial -> gettitulo() << endl;
                    cout << "cliente: ";
                    cout << reservaciones[J].getidcliente() << endl << endl;
                   
                   
                }
                system("pause>nul");
                break;



                case 'c':
                
                    do
                    {
                       //se ingreesa el id del material
                        cout << "Ingrese el Id del material : ";
                        cin >> idmaterial;


                        checkid = false; // variable para controlar si el id existe
                        for (J = 0; J < cont1; ++J)
                        {
                            if (idmaterial == material[J] -> getidmaterial()) //verifica que el id ingresado este en el idmaterial de material que ser cargo
                            {
                                checkid = true;
                                aMaterial = material[J];
                                
                            }
                        }
                        if (checkid==false)  // si no indica que no se encuentra
                        {
                            cout << "Error! ese material no esta registrado." << endl;
                            cout<<endl;
                        }
                    }while (checkid==false);
   


                    checkid= false;
                    for (J = 0; J < cont2; ++J)  // si se encontro despues revisa que este reservado en el txt
                    {
                        if (idmaterial == reservaciones[J].getidmaterial()) //verifica que el id ingresado este en reservaciones
                        {
                          //si si esta se muestan los datos
                            checkid = true;
                            cout << "Reservacion:" << endl;
                            cout << "Material: ";
                            cout << aMaterial -> gettitulo() << endl;
                            cout << "Fecha de inicio: ";
                            cout << reservaciones[J].getfechareservacion() << endl;
                            cout << "Fecha de terminacion: ";
                            //muestra la fecha terminacion mediante la funcion virtual llamada por el apuntador
                            cout << reservaciones[J].calculafechafinreserva(aMaterial -> cantidaddiasprestamo()) << endl << endl;
                        }
                    }
                    if (checkid==false)
                    {
                      /// si no esta reservado lo indica y muestra el material 
                        cout << "No reservado , disponible para reservacion" << endl;
                        for (J = 0; J < cont2; ++J)
                    {
                        if (idmaterial == material[J] -> getidmaterial())
                        {
                            checkid = true;
                            cout << "Material: ";
                            cout << aMaterial -> gettitulo() <<"  esta Disponible para reservar"<<endl;
            
                        }
                    }
                        cout<<endl;
                    }
              
                system("pause>nul");
                break;

                case 'd':
                   { 
                     
                    do
                    {
                        cout << "Ingrese la fecha:" << endl;
                        cin >> fecha;  // sobrecarga operadores
                        cout << endl;
                        dia = fecha.getdia();
                        mes = fecha.getmes();
                        ano = fecha.getano();

                        // se ingresa una fecha y se verifica que se valida de acuerdo a formato si los dias deben ser 31 30 28 29 dependiendo el mes o si el ano es bisiesto 
                        checkfecha =  ((1 <= dia && dia <= 31) &&(1 <= mes && mes <= 12) && (0 <= ano && ano <= 99)) ?(mes == 1 ||mes == 3 ||mes == 5 || mes == 7 ||mes == 8 || mes == 10 ||mes == 12) ?1 :mes == 2 ?ano % 4 == 0 ?dia <= 29 :dia <= 28 :(mes == 4 || mes == 6 ||mes == 9 || mes == 11) ?dia <= 30 :0 :0;

                                        
                        if (checkfecha==false)
                        {
                            cout << "La fecha ingresada no es valida." << endl;
                        }
                     } while (checkfecha==false);  // lo hace hasta que se ingresa una fecha valida

                   
                    checkfecha = false;
                    for (J = 0; J < cont2; ++J)
                    {
                        for (K = 0; K < cont1; ++K)
                        {
                            if (reservaciones[J].getidmaterial() == material[K] -> getidmaterial()) // verifica que el id de reserva este en el arreglo cargado por el material txt
                            {
                                aMaterial = material[K]; // si si lo agrega a una variabel aux para despues desplegarlo 
                                break;
                            }
                        }
                        
                         //revisa que la fecha de reservacion  del txt sea menor o igual a la fecha ingresada y que la fecha ingresada sea menor o igual a la fecha final que se le suman los dias de prestamo es de decir que entre en el rango de fecha inicio y terminacion  uso de sobrecarga operadores
                        if (reservaciones[J].getfechareservacion() <= fecha &&
                        fecha <= reservaciones[J].calculafechafinreserva(aMaterial -> cantidaddiasprestamo()))
                        {
                            checkfecha = true;
                            cout << "Material:" << endl;
                            cout << "Titulo: " << aMaterial -> gettitulo() << endl;
                            cout << "Cliente: " << reservaciones[J].getidcliente() << endl << endl;
                        }
                    }
                    if (checkfecha==false)
                    {
                        cout << "Nada reservado esa fecha " << endl;
                    }
                    
                    cout << endl;
                    break;
                   }
                    case 'e':
         
                   // pide el id cliente
                    cout << "Ingrese el Id del Cliente : ";
                    cin >> idcliente;


                    checkid = false;
                    do
                    {
                       //verificacion del id
                      cout << "Ingrese el Id del Material : ";
                        cin >> idmaterial;
                        
                        for (J = 0; J < cont1; ++J)
                        {
                            if (idmaterial == material[J] -> getidmaterial())
                            {
                                checkid = true;
                                aMaterial = material[J];
                                break;
                            }
                        }
                        if (!checkid)
                        {
                            cout << "No se encontro el Material." << endl;
                            
                        }
                    }while (!checkid);

                   

                    do
                    {
                        cout << "Ingrese la fecha en que desea reservar:" << endl;
                        cin >> fecha; //Sobre carga de operador 
                        cout << endl;
                        dia = fecha.getdia();
                        mes = fecha.getmes();
                        ano = fecha.getano();
                        //verificacion fecha
 checkfecha =  ((1 <= dia && dia <= 31) &&(1 <= mes && mes <= 12) && (0 <= ano && ano <= 99)) ?(mes == 1 ||mes == 3 ||mes == 5 || mes == 7 ||mes == 8 || mes == 10 ||mes == 12) ?1 :mes == 2 ?ano % 4 == 0 ?dia <= 29 :dia <= 28 :(mes == 4 || mes == 6 ||mes == 9 || mes == 11) ?dia <= 30 :0 :0;

                        checkidc = false;

                        if (!checkfecha)
                        {
                            cout << "La fecha ingresada no es valida." << endl;
                            
                        }
                            // si la fecha es valida
                        for (J = 0; J < cont2; ++J)
                        {
                           // verifica que el id de reservaciones txt corresponda con el idmaterial y 
                           //revisa que la fecha de reservacion  del txt sea menor o igual a la fecha ingresada y que la fecha ingresada sea menor o igual a la fecha final que se le suman los dias de prestamo rango
                            if (reservaciones[J].getidmaterial() == idmaterial && reservaciones[J].getfechareservacion() <= fecha && fecha <= reservaciones[J].calculafechafinreserva(aMaterial -> cantidaddiasprestamo()))
                            {
                                checkidc= true;
                                cout << "El Material esta ocupado de " << reservaciones[J].getfechareservacion() << " a " << reservaciones[J].calculafechafinreserva(aMaterial -> cantidaddiasprestamo()) << '.' << endl << endl;
                                break;
                            }
                        }
                        
                    }
                    while (!checkfecha || checkidc);

                    
                   //se carga al arreglo otra reservacion 
                    reservaciones[cont2] = Reserva(idmaterial, idcliente, fecha);
                    ++cont2;

                    cout << "El Material se reservo con exito." << endl;
                    
                   
                    cout << endl;
					break;
          case 'f':
           {

               Fecha Fr;
       
       remove("Reserva.txt");
      
       ofstream ArchSal;
       ArchSal.open("Reserva.txt", ofstream::app);
       for(J=0; J<cont2; J++)
       {
         Fr = reservaciones[J].getfechareservacion();
         ArchSal<<Fr.getdia()<<" "<<Fr.getmes()<<" "<<Fr.getano()<<" "<<reservaciones[J].getidmaterial()<<" "<<reservaciones[J].getidcliente()<<endl;
       }
       ArchSal.close();

       cout<<"Operación terminada"<<endl;
       cout<<"cambios guardados"<<endl;
       break;



















           }

              
              

              
              
             
                

    }
    
    }while (opcion != 'f' );
    return 0;
}
