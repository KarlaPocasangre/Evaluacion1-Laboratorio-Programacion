#include <iostream>
using namespace std;
#include "Fecha.h"
// Karla Estefany Hernandez Pocasangre Evaluacion 1 Laboratorio Pg

Fecha::Fecha(int d, int m, int a)
{
    this->dia = d;
    this->mes = m;
    this->anio = a;
}
void Fecha::mostrarFecha()
{
    cout << this->dia << "/";
    cout << this->mes << "/";
    cout << this->anio;
}
