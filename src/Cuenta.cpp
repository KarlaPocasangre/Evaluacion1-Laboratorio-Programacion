#include <iostream>
using namespace std;
#define DIM 5
#include "Cliente.h"
#include "Abono.h"
#include "Cuenta.h"
// Karla Estefany Hernandez Pocasangre Evaluacion 1 Laboratorio Pg

Cuenta::Cuenta(int n, Cliente *c)
{
    this->numeroCuenta = n;
    this->cliente = c;
    this->saldo = 0.0;
}
int Cuenta::getNumeroCuenta()
{
    return this->numeroCuenta;
}
void Cuenta::setNumeroCuenta(int n)
{
    this->numeroCuenta = n;
}
Cliente *Cuenta::getCliente()
{
    return this->cliente;
}
void Cuenta::setCliente(Cliente *c)
{
    this->cliente = c;
}
bool Cuenta::agregarAbono(Abono *ab)
{
    bool retorno = false;
    if (this->contadorAbonos < DIM)
    {
        this->lstAbono[this->contadorAbonos] = ab;
        this->contadorAbonos++;
        this->saldo += ab->getMontoAbono();
        retorno = true;
    }
    return retorno;
}
Abono **Cuenta::getLstAbonos()
{
    return this->lstAbono;
}
float Cuenta::getSaldo()
{
    return this->saldo;
}
int Cuenta::getContadorAbonos()
{
    return this->contadorAbonos;
}
