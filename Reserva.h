#pragma once
#include <iostream>
#include "Fecha.h"
#include "Material.h"

using namespace std;

class Reserva
{
private:
    int idMaterial;
    int idCliente;
    Fecha fechaReservacion;
public:
    Reserva(); //const. default
    Reserva(int idM, int idC, Fecha fR); //const. parámetros
    int getIdMaterial() {return idMaterial;};
    int getIdCliente() {return idCliente;};
    Fecha getFechaReservacion() {return fechaReservacion;};
    void setIdMaterial(int idM);
    void setIdCliente(int idC);
    void setFechaReservacion(Fecha fR);
    Fecha calculaFechaFinReserva(int cantDias);
};

Reserva::Reserva()
{
    Fecha temp(0,0,0);
    idMaterial = 0;
    idCliente = 0;
    fechaReservacion = temp;
}
Reserva::Reserva(int idM, int idC, Fecha fR)
{
    idMaterial = idM;
    idCliente = idC;
    fechaReservacion = fR;
}
void Reserva::setIdMaterial(int idM)
{
    idMaterial = idM;
}
void Reserva::setIdCliente(int idC)
{
    idCliente = idC;
}
void Reserva::setFechaReservacion(Fecha fR)
{
    fechaReservacion = fR;
}
Fecha Reserva::calculaFechaFinReserva(int cantDias)
{
    int Fdia, Fmes, Fanio;
    Fdia = fechaReservacion.getDia();
    Fmes = fechaReservacion.getMes();
    Fanio = fechaReservacion.getAnio();
    Fecha temp(Fdia, Fmes, Fanio);
    return temp + cantDias;
}
