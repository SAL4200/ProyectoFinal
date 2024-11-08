#include <iostream>
#include <string>
using namespace::std;
int codigo[5]; //codigo
string nombre_c[5]; // nombre del cliente
int edad[5]; // edad
string nombre_c[5]; // genero 
string eps[5]; // eps


int main()
{
    do {
        cout << "MENU PRINCIPAL";
        cout << "\n1. Atender paciente\n";
        cout << "2. Mostrar total del dia\n";
        cout << "3. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        if (!productosIngresados && opcion != 1 && opcion != 0) {
            cout << "\nDebe ingresar los productos primero.\n";
            continue;
        }

        switch (opcion) {
        case 1:
            ingresarProductos();
            break;
        case 2:
            mostrarProductos();
            break;
        case 3:
            ingresarClientes();
            break;
        case 4:
            procesarVenta();
            break;
        case 5:
            mostrarReporteVentas();
            break;
        case 6:
            mostrarReporteDescuentos();
            break;
        case 7:
            mostrarPromedioVentas();
            break;
        case 8:
            mostrarMayorMenorVenta();
            break;
        case 9:
            mostrarDescuentosMayorMenor();
            break;
        case 10:
            mostrarDescuentosPromedio();
        case 0:
            cout << "Saliendo del programa.\n";
            break;
        default:
            cout << "Opción no válida. Intente de nuevo.\n";
        }
    } while (opcion != 0);

}

}

