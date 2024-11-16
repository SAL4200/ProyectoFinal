#include <iostream>
#include <string>

using namespace std;

int codigo[5];        // código del paciente
string nombre_p[5];   // nombre del paciente
string apellido_p[5]; // apellido del paciente
int edad[5];          // edad del paciente
string genero[5];     // género del paciente
string eps[5];        // EPS del paciente
string medicos[5] = { "Juan Lopez", "Maria Perez", "Carlos Ruiz", "Carlos Velasquez", "Sofia Gonzalez" }; // médicos

int main() {
    int opcion;
    int p_conta = 0; // Contador de pacientes registrados

    do {
        cout << "\nMENU PRINCIPAL\n"; 
        cout << "1. Atender paciente\n";
        cout << "2. Mostrar total del dia\n";
        cout << "3. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            int subOpcion;
            do {
                cout << "\nMenu de opciones para paciente\n"; //Submenu para el paciente
                cout << "1. Ingresar paciente\n";
                cout << "2. Asignar medico\n";
                cout << "3. Historia Clinica\n";
                cout << "4. Asignar medicamentos\n";
                cout << "5. Mostrar total a pagar\n";
                cout << "6. Menu anterior\n";
                cout << "Seleccione una opcion: ";
                cin >> subOpcion;

                switch (subOpcion) {
                case 1:
                    if (p_conta < 5) {
                        // Ingresar un paciente, uno a la vez
                        cout << "Ingrese el codigo del paciente: ";
                        cin >> codigo[p_conta];
                        cout << "Ingrese el nombre del paciente: ";
                        cin >> nombre_p[p_conta];
                        cout << "Ingrese el apellido del paciente: ";
                        cin >> apellido_p[p_conta];
                        cout << "Ingrese la edad del paciente: ";
                        cin >> edad[p_conta];
                        cout << "Ingrese el genero del paciente: ";
                        cin >> genero[p_conta];
                        cout << "Ingrese la EPS del paciente: ";
                        cin >> eps[p_conta];

                        p_conta++;  // Incrementar el contador de pacientes registrados
                        cout << "Paciente ingresado correctamente.\n";
                    }
                    else {
                        cout << "No hay espacio para mas pacientes.\n";
                    }
                    break;
                case 2:
                    if (p_conta > 0) {
                    int paciente, encontrado = -1, seleccion;
                    cout << "Ingrese el codigo del paciente: ";
                    cin >> paciente;   

                    for (int i = 0; i < p_conta; i++) {
                    if (codigo[i] == paciente) {
                    encontrado = i;
                    break;
                      }
                     } //verifica el codigo del paciente en sistema

                    if (encontrado != -1) {
                        cout << "Medicos disponibles:\n";
                        for (int j = 0; j < 5; j++) cout << j + 1 << ". " << medicos[j] << "\n";
                        cout << "Seleccione el medico: ";
                        cin >> seleccion;
            
                        if (seleccion >= 1 && seleccion <= 5)
                            cout << "Medico asignado: " << medicos[seleccion - 1] << "\n";
                        else
                            cout << "Selección inválida.\n";
                    } else {
                        cout << "Paciente no encontrado.\n";
                    }
                } else {
                    cout << "No hay pacientes registrados.\n";
                }
                     break;

                    
                    break;
                case 3:
                    
                    break;
                case 4:
                    
                    break;
                case 5:
                    
                    break;
                case 6:
                    break; // Regresar al menú principal
                default:
                    cout << "Opcion no valida. Intente de nuevo.\n";
                    break;
                }
            } while (subOpcion != 6); // Continuar hasta que el usuario regrese al menú principal

            break;

        case 2:
            
            break;

        case 3:
            cout << "Saliendo del programa.\n";
            break;

        default:
            cout << "Opcion no valida. Intente de nuevo.\n";
            break;
        }

    } while (opcion != 3); // Continuar hasta que el usuario seleccione salir

    return 0;
}
