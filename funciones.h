#pragma once

bool Bisiesto(int mes, int anio)
{
    if (mes == 2)
    {
        if ((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0)) // si es divisibe entre 4 y no entre 100 es bisiesto, a menos que sea divisible entre 400
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return false;
}
