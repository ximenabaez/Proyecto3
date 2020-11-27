#pragma once
#include <iostream>
#include "Material.h"

using namespace std;

class Disco : public Material
{
private:
    int  duracion;
    string Genero;
public:
    Disco(); //const. default
    Disco(int idM, string t, int d, string g);
    int getDuracion() {return duracion;};
    string getGenero() {return Genero;};
    void setDuracion(int d);
    void setGenero(string g);
    void muestraDatos();
    int cantidadDiasPrestamo();
};

Disco::Disco() : Material()
{
    duracion = 0;
    Genero = " ";
}
Disco::Disco(int idM, string t, int d, string g) : Material(idM, t)
{
    duracion = d;
    Genero = g;
}
void Disco::setDuracion(int d)
{
    duracion = d;
}
void Disco::setGenero(string g)
{
    Genero = g;
}
void Disco::muestraDatos()
{
    cout<<"•DISCO•"<<endl;
    cout<<"Id de material: "<<idMaterial<<endl;
    cout<<"Título: "<<titulo<<endl;
    cout<<"Duración: "<<duracion<<endl;
    cout<<"Género: "<<Genero<<endl;
}
int Disco::cantidadDiasPrestamo()
{
    return 3;
}
