#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
#include <string.h>
using namespace std;
// Karla Estefany Hernandez Pocasangre Evaluacion 1 Laboratorio Pg

class Cliente
{
private:
    int idCliente;
    string nombre;
    string apellido;

public:
    Cliente(int, string, string);
    int getIdCliente();
    string getNombre();
    string getApellido();
};

#endif // CLIENTE_H_INCLUDED
