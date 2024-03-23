#ifndef ABONO_H_INCLUDED
#define ABONO_H_INCLUDED
#include "Fecha.h"
// Karla Estefany Hernandez Pocasangre Evaluacion 1 Laboratorio Pg

class Abono
{
private:
    Fecha *fecha;
    float montoAbono;

public:
    Abono(Fecha *, float);
    Fecha *getFechaAbono();
    float getMontoAbono();
};

#endif // ABONO_H_INCLUDED
