#include "Fecha.h"
#include "Reserva.h"
#include "Material.h"
#include "Libro.h"
#include "Disco.h"
#include "Software.h"
#include <iostream>
#include <fstream>

using namespace std;

bool VerifFecha(Reserva res[], Material *mat[], Fecha temp, int i, int j)
{
    if (res[i].getIdMaterial() == mat[j]->getIdMaterial())
    {
        if (temp <= res[i].calculaFechaFinReserva(mat[j]->cantidadDiasPrestamo()) && (temp >= res[i].getFechaReservacion()))
        {
            return true;
        }

    }
    return false;
}
bool VerifIdMat(Material *mat[], int idm, int cont)
{
    for (int j=0; j<cont; j++)
    {
        if (idm == mat[j]->getIdMaterial())
        {
            return false;
        }
    }
    return true;
}

int main ()
{   
    Material *materiales[30];
    Reserva reservaciones[60];
    
    ifstream archMaterial, archReserva;
    ofstream archSal;
    
    int idMat;
    string titu;
    int numP;
    string aut;
    int dur;
    string gen;
    int ver;
    string sistOp;
    string tipo;
    int dia;
    int mes;
    int anio;
    int idCli;
    char opcion = '\0';
    int cont = 0;
    int cont2 = 0;
    string archiM = "Material.txt";
    string archiR = "Reserva.txt";
    
    archMaterial.open(archiM);
    for (int i=0; !archMaterial.eof(); i++)
    {
        archMaterial>>idMat>>titu>>tipo;
        if (tipo == "L")
        {
            archMaterial>>numP>>aut;
            materiales[i] = new Libro(idMat,titu,numP,aut);
            cont++;
        }
        else if (tipo == "D")
        {
            archMaterial>>dur>>gen;
            materiales[i] = new Disco(idMat,titu,dur,gen);
            cont++;
        }
        else if (tipo == "S")
        {
            archMaterial>>ver>>sistOp;
            materiales[i] = new Software(idMat,titu,ver,sistOp);
            cont++;
        }
        else
        {
            cout<<"Error"<<endl;
        }
    }
    archMaterial.close();

    archReserva.open(archiR);
    for (int i=0; !archReserva.eof(); i++)
    {
        archReserva>>dia>>mes>>anio>>idMat>>idCli;
        Fecha temp(dia, mes, anio);
        reservaciones[i].setFechaReservacion(temp);
        reservaciones[i].setIdMaterial(idMat);
        reservaciones[i].setIdCliente(idCli);
        cont2++;
    }
    archReserva.close();

    while (opcion != 'F' || opcion != 'f')
    {
        cout<<"Seleccione la opción que desee realizar"<<endl;
        cout<<"A. Consultar la lista de Materiales"<<endl;
        cout<<"B. Consultar la lista de reservaciones"<<endl;
        cout<<"C. Consultar las reservaciones de un material dado"<<endl;
        cout<<"D. Consultar las reservaciones de una fecha dada"<<endl;
        cout<<"E. Hacer una reservacion"<<endl;
        cout<<"F. Terminar"<<endl;
        cout<<"Opción: "; cin>>opcion; cout<<endl;
        
//OPCIÓN A
        if (opcion == 'A' || opcion == 'a')
        {
            for (int i=0; i<20; i++)
            {
                materiales[i]->muestraDatos();
                cout<<endl;
            }
        }
//OPCIÓN B
        else if (opcion == 'B' || opcion == 'b')
        {
            for (int i=0; i<60; i++)
            {
                for (int j=0; j<cont; j++)
                {
                    if (reservaciones[i].getIdMaterial() == materiales[j]->getIdMaterial())
                    {
                        cout<<"Reservación: "<<reservaciones[i].getFechaReservacion()<<" | ";
                        cout<<"Entrega: "<<reservaciones[i].calculaFechaFinReserva(materiales[j]->cantidadDiasPrestamo())<<" | ";
                        if (materiales[j]->cantidadDiasPrestamo() == 5)
                        {
                            cout<<"Tipo: "<<"Libro"<<" | ";
                            cout<<"Nombre: "<<materiales[j]->getTitulo()<<" | ";
                            cout<<"Id cliente: "<<reservaciones[i].getIdCliente()<<endl;
                        }
                        else if (materiales[j]->cantidadDiasPrestamo() == 3)
                        {
                            cout<<"Tipo: "<<"Disco"<<" | ";
                            cout<<"Nombre: "<<materiales[j]->getTitulo()<<" | ";
                            cout<<"Id cliente: "<<reservaciones[i].getIdCliente()<<endl;
                        }
                        else if (materiales[j]->cantidadDiasPrestamo() == 1)
                        {
                            cout<<"Tipo: "<<"Software"<<" | ";
                            cout<<"Nombre: "<<materiales[j]->getTitulo()<<" | ";
                            cout<<"Id cliente: "<<reservaciones[i].getIdCliente()<<endl;
                        }
                    }
                }
            }
            cout<<endl;
        }
//OPCIÓN C
        else if (opcion == 'C' || opcion == 'c')
        {
            char op;
            cout<<"Seleccione un material"<<endl;
            cout<<"a) Libro"<<endl;
            cout<<"b) Disco"<<endl;
            cout<<"c) Software"<<endl;
            cout<<"Material: "; cin>>op; cout<<endl;
            if (op == 'a' || op == 'A')
            {
                cout<<"•LIBROS•"<<endl;
                for (int i=0; i<cont; i++)
                {
                    if (materiales[i]->cantidadDiasPrestamo() == 5)
                    {
                        for (int j=0; j<60; j++)
                        {
                            if (materiales[i]->getIdMaterial() == reservaciones[j].getIdMaterial())
                            {
                                cout<<"Nombre: "<<materiales[i]->getTitulo()<<" | ";
                                cout<<"Reservación: "<<reservaciones[j].getFechaReservacion()<<" | ";
                                cout<<"Entrega: "<<reservaciones[j].calculaFechaFinReserva(5)<<endl;
                            }
                        }
                    }
                }
            }
            else if (op == 'b' || op == 'B')
            {
                cout<<"•DISCOS•"<<endl;
                for (int i=0; i<cont; i++)
                {
                    if (materiales[i]->cantidadDiasPrestamo() == 3)
                    {
                        for (int j=0; j<60; j++)
                        {
                            if (materiales[i]->getIdMaterial() == reservaciones[j].getIdMaterial())
                            {
                                cout<<"Nombre: "<<materiales[i]->getTitulo()<<" | ";
                                cout<<"Reservación: "<<reservaciones[j].getFechaReservacion()<<" | ";
                                cout<<"Entrega: "<<reservaciones[j].calculaFechaFinReserva(3)<<endl;
                            }
                        }
                    }
                }
            }
            else if (op == 'c' || op == 'C')
            {
                cout<<"•SOFTWARE•"<<endl;
                for (int i=0; i<cont; i++)
                {
                    if (materiales[i]->cantidadDiasPrestamo() == 1)
                    {
                        for (int j=0; j<60; j++)
                        {
                            if (materiales[i]->getIdMaterial() == reservaciones[j].getIdMaterial())
                            {
                                cout<<"Nombre: "<<materiales[i]->getTitulo()<<" | ";
                                cout<<"Reservación: "<<reservaciones[j].getFechaReservacion()<<" | ";
                                cout<<"Entrega: "<<reservaciones[j].calculaFechaFinReserva(1)<<endl;
                            }
                        }
                    }
                }
            }
            cout<<endl;
        }
//OPCIÓN D
        else if (opcion == 'D' || opcion == 'd')
        {
            int d, m, a;
            do {
            cout<<"Digite una fecha a continuación"<<endl;
            cout<<"Día: "; cin>>d;
            cout<<"Mes: "; cin>>m;
            cout<<"Año: "; cin>>a;
            } while ((m == 2 && Bisiesto(m, a) &&  (d > 29 || d < 1)) || (m == 2 && !Bisiesto(m, a) && (d > 28 || d < 1)) || ((m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) && (d > 31 || d < 1)) || ((m == 4 || m == 6 || m == 9 || m == 11) && (d > 30 || d < 1)) || (m > 12) || (m < 1));
            Fecha temp(d, m, a);
            cout<<temp<<endl;
            for (int i=0; i<60; i++)
            {
                for (int j=0; j<cont; j++)
                {
                    if (VerifFecha(reservaciones, materiales, temp, i, j))
                    {
                        if (materiales[j]->cantidadDiasPrestamo() == 5)
                        {
                            cout<<"Tipo: "<<"Libro"<<" | ";
                            cout<<"Nombre: "<<materiales[j]->getTitulo()<<" | ";
                            cout<<"Id del cliente: "<<reservaciones[i].getIdCliente()<<endl;
                        }
                        else if (materiales[j]->cantidadDiasPrestamo() == 3)
                        {
                            cout<<"Tipo: "<<"Disco"<<" | ";
                            cout<<"Nombre: "<<materiales[j]->getTitulo()<<" | ";
                            cout<<"Id del cliente: "<<reservaciones[i].getIdCliente()<<endl;
                        }
                        else if (materiales[j]->cantidadDiasPrestamo() == 1)
                        {
                            cout<<"Tipo: "<<"Software"<<" | ";
                            cout<<"Nombre: "<<materiales[j]->getTitulo()<<" | ";
                            cout<<"Id del cliente: "<<reservaciones[i].getIdCliente()<<endl;
                        }
                    }
                    else if (!VerifFecha(reservaciones, materiales, temp, i, j) && (reservaciones[i].getIdMaterial() == 0))
                    {
                        cout<<"No hay reservaciones en la fecha dada"<<endl;
                        i = 60;
                        j = cont;
                    }
                }
            }
            cout<<endl;
        }
//OPCIÓN E
        else if (opcion == 'E' || opcion == 'e')
        {
            int idc, idm, d, m, a;
            bool encontro = false;
            bool lleno = false;
            do {
                cout<<"Digite el id del cliente: "; cin>>idc;
            } while (idc <= 0);
            do {
                cout<<"Digite el id del material: "; cin>>idm;
            } while (idm <= 0 || VerifIdMat(materiales, idm, cont));
            do {
            cout<<"Digite una fecha a continuación"<<endl;
            cout<<"Día: "; cin>>d;
            cout<<"Mes: "; cin>>m;
            cout<<"Año: "; cin>>a;
            } while ((m == 2 && Bisiesto(m, a) &&  (d > 29 || d < 1)) || (m == 2 && !Bisiesto(m, a) && (d > 28 || d < 1)) || ((m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) && (d > 31 || d < 1)) || ((m == 4 || m == 6 || m == 9 || m == 11) && (d > 30 || d < 1)) || (m > 12) || (m < 1));
            Fecha temp(d, m, a);
            for (int i=0; i<60; i++) //reservaciones
            {
                for (int j=0; j<cont; j++) //materiales
                {
                    if (idm == reservaciones[i].getIdMaterial())
                    {
                        if (reservaciones[i].getIdMaterial() == materiales[j]->getIdMaterial())
                        {
                            if (((temp >= (reservaciones[i].getFechaReservacion() + (-materiales[j]->cantidadDiasPrestamo()))) && temp <= reservaciones[i].calculaFechaFinReserva(materiales[j]->cantidadDiasPrestamo())) && (cont2 != 60))
                            {
                                //cout<<i<<endl;
                                encontro = true;
                                i = 60;
                            }
                            else if ((temp < reservaciones[i].getFechaReservacion() || temp > reservaciones[i].calculaFechaFinReserva(materiales[j]->cantidadDiasPrestamo())) && (cont2 != 60))
                            {
                                //cout<<"caso1.2 "<<i<<endl;
                                encontro = false;
                            }
                            else if (cont2 == 60)
                            {
                                //cout<<"caso1.3 "<<i<<endl;
                                lleno = true;
                                i = 60;
                            }
                        }
                    }
                    else if (((reservaciones[i].getIdMaterial() != idm) && (i == cont2)) && (cont2 != 60) && (reservaciones[i].getIdMaterial() == 0))
                    {
                        //cout<<"caso2.1 "<<i<<endl;
                        encontro = false;
                        i = 60;
                    }
                    else if (cont2 == 60)
                    {
                        //cout<<"caso2.2 "<<i<<endl;
                        lleno = true;
                        i = 60;
                    }
                }
            }
            if (encontro)
            {
                cout<<"Fecha no disponible"<<endl;
            }
            else if (!encontro && !lleno)
            {
                reservaciones[cont2].setIdMaterial(idm);
                reservaciones[cont2].setIdCliente(idc);
                reservaciones[cont2].setFechaReservacion(temp);
                cout<<"Reserva realizada exitosamente"<<endl;
                cont2++;
            }
            else if (lleno)
            {
                cout<<"No hay espacio para realizar la reservación"<<endl;
            }
            cout<<endl;
        }
//OPCIÓN F
        else if (opcion == 'F' || opcion == 'f')
        {
            archSal.open(archiR);
            for (int i=0; i<cont2; i++)
            {
                int d, m, a, idm, idc;
                d = reservaciones[i].getFechaReservacion().getDia();
                m = reservaciones[i].getFechaReservacion().getMes();
                a = reservaciones[i].getFechaReservacion().getAnio();
                idm = reservaciones[i].getIdMaterial();
                idc = reservaciones[i].getIdCliente();
                if (i == (cont2 - 1))
                {
                    archSal<<d<<" "<<m<<" "<<a<<" "<<idm<<" "<<idc;
                }
                else
                {
                    archSal<<d<<" "<<m<<" "<<a<<" "<<idm<<" "<<idc<<endl;
                }
            }
            archSal.close();
            break;
        }
    }
    
    return 0;
}
