#include <iostream>
using namespace std;
#include "Fecha.h"
#include "Abono.h"
// Karla Estefany Hernandez Pocasangre Evaluacion 1 Laboratorio Pg

Abono::Abono(Fecha *fa, float m)
{
    this->fecha = fa;
    this->montoAbono = m;
}
Fecha *Abono::getFechaAbono()
{
    return this->fecha;
}
float Abono::getMontoAbono()
{
    return this->montoAbono;
}
