#pragma once
#include <iostream>
#include "Material.h"

using namespace std;

class Software : public Material
{
private:
    int Version;
    string SO;
public:
    Software(); //const. default
    Software(int idM, string t, int v, string s);
    int getVersion() {return Version;};
    string getSO() {return SO;};
    void setVersion(int v);
    void setSO(string s);
    void muestraDatos();
    int cantidadDiasPrestamo();
};

Software::Software() : Material()
{
    Version = 0;
    SO = " ";
}
Software::Software(int idM, string t, int v, string s) : Material(idM, t)
{
    Version = v;
    SO = s;
}
void Software::setVersion(int v)
{
    Version = v;
}
void Software::setSO(string s)
{
    SO = s;
}
void Software::muestraDatos()
{
    cout<<"•SOFTWARE•"<<endl;
    cout<<"Id del material: "<<idMaterial<<endl;
    cout<<"Título: "<<titulo<<endl;
    cout<<"Versión: "<<Version<<endl;
    cout<<"Sistema operativo: "<<SO<<endl;
}
int Software::cantidadDiasPrestamo()
{
    return 1;
}
