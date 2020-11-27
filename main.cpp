#include "Fecha.h"
#include "Reserva.h"
#include "Material.h"
#include "Libro.h"
#include "Disco.h"
#include "Software.h"
#include <iostream>
#include <fstream>

using namespace std;

int main ()
{
   Fecha f1(10,9,2021), f2, f3(10,10,2021), f4;
   cout<<"•PRUEBAS•"<<endl;
   cout<<f1.getDia()<<"/"<<f1.getMes()<<"/"<<f1.getAnio()<<endl;
   f2 = f1 + (-2);
   cout<<f2.getDia()<<"/"<<f2.getMes()<<"/"<<f2.getAnio()<<endl;
   cout<<f2.nombreMes()<<endl;
   cout<<"-----------------"<<endl;
   cout<<"f1= "<<f1.getDia()<<"/"<<f1.getMes()<<"/"<<f1.getAnio()<<endl;
   cout<<"f3= "<<f3.getDia()<<"/"<<f3.getMes()<<"/"<<f3.getAnio()<<endl;
   if (f1 >= f3)
   {
       cout<<"f1 es mayor o igual"<<endl;
   }
   else
   {
       cout<<"f1 no es mayor o igual"<<endl;
   }
   cout<<"-----------------"<<endl;
   if (f1 <= f3)
   {
       cout<<"f1 es menor o igual"<<endl;
   }
   else
   {
       cout<<"f1 no es menor o igual"<<endl;
   }
   cout<<"-----------------"<<endl;
   if (f1 > f3)
   {
       cout<<"f1 es mayor"<<endl;
   }
   else if (f1 < f3)
   {
       cout<<"f1 es menor"<<endl;
   }
   else if (f1 == f3)
   {
       cout<<"f1 y f3 son iguales"<<endl;
   }
   cout<<"-----------------"<<endl;
   cout<<f3<<endl;
   cin>>f4;
   cout<<f4<<endl;
   cout<<"-----------------"<<endl;
   Material *arr[4];
   arr[0] = new Libro(2, "Libro divertido", 180, "Ximo Baez");
   arr[1] = new Disco(5, "Blanca Navidad", 4, "Pop");
   arr[2] = new Software(7, "Software hola", 9, "Sierra OS");
   arr[3] = new Disco(5, "Tiempo de bals", 3, "Bals");

   for (int i=0; i<4; i++)
   {
       arr[i]->muestraDatos();
       cout<<"Cantidad días prestamo: ";
       cout<<arr[i]->cantidadDiasPrestamo();
       cout<<endl<<endl;
   } 
    
    return 0;
}
