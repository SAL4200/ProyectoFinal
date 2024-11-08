#include <iostream>
#include <string>
using namespace::std;
int codigo[5]; //codigo
string nombre_p[5]; // nombre del cliente
string apellido_p[5]; // apellido
int edad[5]; // edad
string genero[5]; // genero 
string eps[5]; // eps
string medicamentos {5}


int main() {
    int opcion;

    do {
        cout << "MENU PRINCIPAL";
        cout << "\n1. Atender paciente\n";
        cout << "2. Mostrar total del dia\n";
        cout << "3. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;


        switch (opcion) {
        case 1:
            do {
                cout << "Menu de opciones";
                cout << " 1. Ingresar paciente";
                cout << " 2. Asignar médico";
                cout << " 3. Historia Clínica";
                cout << " 4. Asignar medicamentos";
                cout << " 5. Mostrar total a pagar";
                cout << " 6. Menú anterior";
                cin >> opcion;

                for (int i = 0; i < 5; ++i) {
                    cout << "Ingrese el codigo del paciente: ";
                    cin >> codigo[i];
                    cout << "Ingrese el nombre del paciente: ";
                    cin >> nombre_p[i];
                    cout << "Ingrese el apellido del paciente: ";
                    cin >> apellido_p[i];
                    cout << "Ingrese la edad del paciente: ";
                    cin >> edad[i];
                    cout << "Ingrese el genero del paciente: ";
                    cin >> genero[i];
                    cout << "Ingrese la EPS del paciente : ";
                    cin >> eps[i];
                }

        case 2:
            break;
        case 3:
            break;
        case 4:
           
            break;
        case 5:
            break;
        case 6:
            break;
        default:
            cout << "Opción no válida. Intente de nuevo.\n";
            }
        } while (opcion != 0);



        break;
        case 2:

            break;
        case 3:
            cout << "Saliendo del programa.\n";
            break;

        default:
            cout << "Opción no válida. Intente de nuevo.\n";
    }
} while (opcion != 0);

}

}

