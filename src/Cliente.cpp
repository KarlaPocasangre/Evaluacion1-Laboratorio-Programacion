#include <iostream>
using namespace std;
#include "Cliente.h"
// Karla Estefany Hernandez Pocasangre Evaluacion 1 Laboratorio Pg

Cliente::Cliente(int i, string n, string a)
{
    this->idCliente = i;
    this->nombre = n;
    this->apellido = a;
}
int Cliente::getIdCliente()
{
    return this->idCliente;
}
string Cliente::getNombre()
{
    return this->nombre;
}
string Cliente::getApellido()
{
    return this->apellido;
}
