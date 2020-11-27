#pragma once
#include <iostream>
#include "Material.h"

using namespace std;

class Libro : public Material
{
private:
    int numPag;
    string Autor;
public:
    Libro(); //const. default
    Libro(int idM, string t, int nP, string a); //const. parámetros
    int getNumPag() {return numPag;};
    string getAutor() {return Autor;};
    void setNumPag(int nP);
    void setAutor(string a);
    void muestraDatos();
    int cantidadDiasPrestamo();
};

Libro::Libro() : Material()
{
    numPag = 0;
    Autor = " ";
}
Libro::Libro(int idM, string t, int nP, string a) : Material(idM, t)
{
    numPag = nP;
    Autor = a;
}
void Libro::setNumPag(int nP)
{
    numPag = nP;
}
void Libro::setAutor(string a)
{
    Autor = a;
}
void Libro::muestraDatos()
{
    cout<<"•LIBRO•"<<endl;
    cout<<"Id de material: "<<idMaterial<<endl;
    cout<<"Título: "<<titulo<<endl;
    cout<<"Número de páginas: "<<numPag<<endl;
    cout<<"Autor: "<<Autor<<endl;
}
int Libro::cantidadDiasPrestamo()
{
    return 5;
}

