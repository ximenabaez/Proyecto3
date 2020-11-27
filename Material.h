#pragma once
#include <iostream>

using namespace std;

class Material
{
protected:
    int idMaterial;
    string titulo;
public:
    Material(); //const. default
    Material(int idM, string t);
    int getIdMaterial() {return idMaterial;};
    string getTitulo() {return titulo;};
    void setIdMaterial(int idM);
    void setTitulo(string t);
    virtual void muestraDatos() = 0;
    virtual int cantidadDiasPrestamo() = 0;
};

Material::Material()
{
    idMaterial = 0;
    titulo = " ";
}
Material::Material(int idM, string t)
{
    idMaterial = idM;
    titulo = t;
}
void Material::setIdMaterial(int idM)
{
    idMaterial = idM;
}
void Material::setTitulo(string t)
{
    titulo = t;
}
