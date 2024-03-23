#ifndef CUENTA_H_INCLUDED
#define CUENTA_H_INCLUDED
#include "Abono.h"
#include "Cliente.h"
#define DIM 5
// Karla Estefany Hernandez Pocasangre Evaluacion 1 Laboratorio Pg

class Cuenta
{
private:
    int numeroCuenta;
    Cliente *cliente;
    Abono *lstAbono[DIM];
    float saldo;
    int contadorAbonos;

public:
    Cuenta();
    Cuenta(int, Cliente *);
    int getNumeroCuenta();
    void setNumeroCuenta(int);
    Cliente *getCliente();
    void setCliente(Cliente *);
    bool agregarAbono(Abono *);
    Abono **getLstAbonos();
    float getSaldo();
    int getContadorAbonos();
};

#endif // CUENTA_H_INCLUDED
