#pragma once
#include <iostream>
#include <string>
#include "funciones.h"
#include <iomanip>
using namespace std;

class Fecha
{
private:
    int dd, mm, aa;
public:
    Fecha(); //const. default
    Fecha(int d, int m, int a); //const. parámetros
    int getDia() {return dd;};
    int getMes() {return mm;};
    int getAnio() {return aa;};
    void setFecha(int d, int m, int a);
    friend Fecha operator+(Fecha f1, int d);
    friend bool operator>=(Fecha f1, Fecha f2);
    friend bool operator<=(Fecha f1, Fecha f2);
    friend bool operator>(Fecha f1, Fecha f2);
    friend bool operator<(Fecha f1, Fecha f2);
    friend bool operator==(Fecha f1, Fecha f2);
    friend ostream & operator<<(ostream &out, const Fecha &f);
    friend istream & operator>>(istream &in, Fecha &f);
    string nombreMes();
};

Fecha::Fecha() //const. default
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
void Fecha::setFecha(int d, int m, int a)
{
    dd = d;
    mm = m;
    aa = a;
}
Fecha operator+(Fecha f1, int d)
{
    int arr[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    int Ndia, Nmes, Nanio, Maxdias;
    Ndia = f1.dd + d;
    Nmes = f1.mm;
    Nanio = f1.aa;
    Maxdias = arr[Nmes] + (Bisiesto(Nmes, Nanio) ? 1 : 0);
    while (Ndia > Maxdias)
    {
        Ndia -= Maxdias;
        Nmes++;
        if (Nmes > 12)
        {
            Nmes = 1;
            Nanio++;
        }
        Maxdias = arr[Nmes] + (Bisiesto(Nmes, Nanio) ? 1 : 0);
    }
    Fecha temp(Ndia, Nmes, Nanio);
    return temp;
}
bool operator>=(Fecha f1, Fecha f2)
{
    if (f1.aa > f2.aa)
    {
        return true;
    }
    else if (f1.aa == f2.aa)
    {
        if (f1.mm > f2.mm)
        {
            return true;
        }
        else if (f1.mm == f2.mm)
        {
            if (f1.dd >= f2.dd)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}
bool operator<=(Fecha f1, Fecha f2)
{
    if (f1.aa < f2.aa)
    {
        return true;
    }
    else if (f1.aa == f2.aa)
    {
        if (f1.mm < f2.mm)
        {
            return true;
        }
        else if (f1.mm == f2.mm)
        {
            if (f1.dd <= f2.dd)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}
bool operator>(Fecha f1, Fecha f2)
{
    if (f1.aa > f2.aa)
    {
        return true;
    }
    else if (f1.aa == f2.aa)
    {
        if (f1.mm > f2.mm)
        {
            return true;
        }
        else if (f1.mm == f2.mm)
        {
            if (f1.dd > f2.dd)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}
bool operator<(Fecha f1, Fecha f2)
{
    if (f1.aa < f2.aa)
    {
        return true;
    }
    else if (f1.aa == f2.aa)
    {
        if (f1.mm < f2.mm)
        {
            return true;
        }
        else if (f1.mm == f2.mm)
        {
            if (f1.dd < f2.dd)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}
bool operator==(Fecha f1, Fecha f2)
{
    if ((f1.aa == f2.aa) && (f1.mm == f2.mm) && (f1.aa == f2.aa))
    {
        return true;
    }
    else
    {
        return false;
    }
}
ostream & operator<<(ostream &out, const Fecha &f)
{
    Fecha f1(f);
    out<<setw(2)<<setfill('0')<<f.dd<<"/"<<f1.nombreMes()<<"/"<<f.aa;
    return out;
}
istream & operator>>(istream &in, Fecha &f)
{
    cout<<"Introduce el día: ";
    in>>f.dd;
    cout<<"Introduce el mes: ";
    in>>f.mm;
    cout<<"Introduce el año: ";
    in>>f.aa;
    return in;
}
string Fecha::nombreMes()
{
    string arr[13] = {" ", "Ene", "Feb", "Mar", "Abr", "May", "Jun", "Jul", "Ago", "Sep", "Oct", "Nov", "Dic"};
    string mes;
    for (int i=0; i<=13; i++)
    {
        if (mm == i)
        {
            mes = arr[i];
        }
    }
    return mes;
}
