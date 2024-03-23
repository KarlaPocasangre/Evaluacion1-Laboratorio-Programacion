#include <iostream>
#include <stdlib.h>
#include "Cuenta.h"
#include "Cliente.h"
#include "Fecha.h"
#include "Abono.h"
#include "stdlib.h"
#define TAM 5
// Karla Estefany Hernandez Pocasangre Evaluacion 1 Laboratorio Pg

using namespace std;

int menu()
{
    int op;
    cout << "-------------------------------" << endl;
    cout << "MENU\n";
    cout << "1. Agregar cliente a la lista\n";
    cout << "2. Agregar cuenta a la lista.\n";
    cout << "3. Hacer abonos\n";
    cout << "4. Mostrar lista de clientes\n";
    cout << "5. Mostrar lista de cuentas\n";
    cout << "6. Mostrar detalles de la cuenta\n";
    cout << "7. Salir\n";
    cout << "-------------------------------" << endl;
    cout << "Ingrese una opcion: ";
    cin >> op;
    system("cls");
    return op;
}
Cliente *agregarCliente()
{
    Cliente *cli;
    int id;
    string n, a;
    cout << "\nIngrese el id del cliente: ";
    cin >> id;
    cout << "\nIngrese el nombre del Cliente: ";
    cin >> n;
    cout << "\nIngrese el apellido del cliente: ";
    cin >> a;
    cli = new Cliente(id, n, a);
    return cli;
}
Cliente *buscarCliente(Cliente *lst[], int cont, int id)
{
    bool encontrado = false;
    int contador = 0;
    Cliente *cli = NULL;
    while (contador < cont && !encontrado)
    {
        if (lst[contador]->getIdCliente() == id)
        {
            encontrado = true;
            cli = lst[contador];
        }
        else
        {
            contador++;
        }
    }
    return cli;
}
Cuenta *buscarCuenta(Cuenta *lst[], int cont, int nc)
{
    bool encontrado = false;
    int contador = 0;
    Cuenta *cta = NULL;
    while (contador < cont && !encontrado)
    {
        if (lst[contador]->getNumeroCuenta() == nc)
        {
            encontrado = true;
            cta = lst[contador];
        }
        else
        {
            contador++;
        }
    }
    return cta;
}
Cuenta *agregarCuenta(Cliente *cli)
{
    int nc;
    Cuenta *cta;
    cout << "\nIngrese el numero de cuenta: ";
    cin >> nc;
    cta = new Cuenta(nc, cli);
    return cta;
}
void hacerAbono(Cuenta *cta)
{
    int d, m, a;
    Fecha *fa;
    float ma;
    Abono *ab;
    cout << "\nIngrese la fecha del abono: ";
    cin >> d >> m >> a;
    cout << "\nIngrese el monto del abono: ";
    cin >> ma;
    fa = new Fecha(d, m, a);
    ab = new Abono(fa, ma);
    cta->agregarAbono(ab);
}

void verDetalles(Cuenta *cta)
{
    cout << "\nNumero de cuenta : " << cta->getNumeroCuenta() << endl;
    cout << "\nCliente : " << cta->getCliente()->getNombre() << " " << cta->getCliente()->getApellido() << endl;
    cout << "\nSaldo : " << cta->getSaldo() << endl;
    if (cta->getContadorAbonos() == 0)
    {
        cout << "\nNo hay Abonos \n";
    }
    else
    {
        cout << "No\tFecha\tMonto\n";
        Abono **lst = cta->getLstAbonos();
        for (int i = 0; i < cta->getContadorAbonos(); i++)
        {
            cout << (i + 1) << "\t";
            lst[i]->getFechaAbono()->mostrarFecha();
            cout << "\t" << lst[i]->getMontoAbono() << endl;
        }
    }
}

int main()
{
    Cliente *lstCliente[TAM];
    Cuenta *lstCuenta[TAM];
    int contCli = 0, contCta = 0, idCli, idCta, opc;
    Cliente *cli = NULL;
    Cuenta *cta = NULL;
    do
    {
        system("cls");
        opc = menu();
        switch (opc)
        {
        case 1:
            // Agregar clientes
            if (contCli < TAM)
            {
                lstCliente[contCli] = agregarCliente();
                contCli++;
                cout << "\nEl Cliente fue agregado exitosamente\n";
            }
            else
            {
                cout << "\nLa lista esta llena\n";
            }
            break;
        case 2:
            // Agregar cuentas
            if (contCta < TAM)
            {
                cout << "\nIngrese el id del cliente: ";
                cin >> idCli;
                cli = buscarCliente(lstCliente, contCli, idCli);
                if (cli)
                {
                    // El cliente se encontro
                    lstCuenta[contCta] = agregarCuenta(cli);
                    contCta++;
                    cout << "\nLa cuenta se agrego con exito\n";
                }
                else
                {
                    cout << "\nEl cliente no se encontro\n";
                }
            }
            else
            {
                cout << "\nLa lista esta llena\n";
            }
            break;
        case 3:
            // Hacer abonos
            cout << "\nIngrese el numero de cuenta: ";
            cin >> idCta;
            cta = buscarCuenta(lstCuenta, contCta, idCta);
            if (cta)
            {
                // La cuenta se encontro
                hacerAbono(cta);
                cout << "\nEl abono se agrego con exito\n";
            }
            else
            {
                cout << "\nLa cuenta no se encontro\n";
            }
            break;
        case 4:
            // Ver lista de clientes
            if (contCli == 0)
                cout << "\nLa lista esta vacia\n";
            else
            {
                cout << "Id\tNombre\tApellido\n";
                for (int i = 0; i < contCli; i++)
                {
                    cout << lstCliente[i]->getIdCliente() << "\t";
                    cout << lstCliente[i]->getNombre() << "\t";
                    cout << lstCliente[i]->getApellido() << "\n";
                }
            }
            break;
        case 5:
            // Ver lista de cuentas
            if (contCta == 0)
            {
                cout << "\nLa lista esta vacia\n";
            }
            else
            {
                cout << "No\tCliente\tSaldo\n";
                for (int i = 0; i < contCta; i++)
                {
                    cout << lstCuenta[i]->getNumeroCuenta() << "\t";
                    cout << lstCuenta[i]->getCliente()->getNombre() << " " << lstCuenta[i]->getCliente()->getApellido() << "\t";
                    cout << lstCuenta[i]->getSaldo() << "\n";
                }
            }
            break;
        case 6:
            // Ver detalles de la cuenta
            cout << "\nIngrese el numero de cuenta: ";
            cin >> idCta;
            cta = buscarCuenta(lstCuenta, contCta, idCta);
            if (cta)
            {
                // La cuenta se encontro
                verDetalles(cta);
            }
            else
            {
                cout << "\nLa cuenta no se encontro \n";
            }
            break;
        case 7:
            // Salir
            cout << "\nSaliendo del programa...\n";
            return 0;
            break;
        default:
            cout << "\nError, opcion no esta definida\n";
            break;
        }
        cout << "\n";
        system("pause");
    } while (opc != 7);

    return 0;
}
