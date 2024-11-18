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
string historia[5];   // Historia clínica de los pacientes
string medicamentos[5][10]; // Medicamentos asignados a cada paciente
float precios_med[5][10] = {}; // Precios de los medicamentos asignados

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
        case 1: {
            int subOpcion;
            do {
                cout << "\nMenu de opciones para paciente\n"; // Submenu para el paciente
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
                        historia[p_conta] = "Sin registro"; // Inicializa la historia clínica

                        p_conta++;  // Incrementar el contador de pacientes registrados
                        cout << "Paciente ingresado correctamente.\n";
                    } else {
                        cout << "No hay espacio para mas pacientes.\n";
                    }
                    break;

                case 3: {
                    int paciente, encontrado = -1;
                    cout << "Ingrese el codigo del paciente: ";
                    cin >> paciente;

                    // Verifica el código del paciente en sistema
                    for (int i = 0; i < p_conta; i++) {
                        if (codigo[i] == paciente) {
                            encontrado = i;
                            break;
                        }
                    }

                    if (encontrado != -1) {
                        cout << "Historia actual del paciente: " << historia[encontrado] << "\n";
                        cout << "Ingrese nueva entrada para la historia clinica (sin espacios): ";
                        cin >> historia[encontrado]; // Solo permite palabras sin espacios
                        cout << "Historia clinica actualizada.\n";
                    } else {
                        cout << "Paciente no encontrado.\n";
                    }
                } break;

                case 4: {
                    int paciente, encontrado = -1;
                    cout << "Ingrese el codigo del paciente: ";
                    cin >> paciente;

                    // Verifica el código del paciente en sistema
                    for (int i = 0; i < p_conta; i++) {
                        if (codigo[i] == paciente) {
                            encontrado = i;
                            break;
                        }
                    }

                    if (encontrado != -1) {
                        int num_meds;
                        cout << "Cuantos medicamentos desea asignar al paciente? ";
                        cin >> num_meds;

                        if (num_meds > 0 && num_meds <= 10) {
                            for (int j = 0; j < num_meds; j++) {
                                cout << "Ingrese el nombre del medicamento " << j + 1 << " (sin espacios): ";
                                cin >> medicamentos[encontrado][j];
                                cout << "Ingrese el precio del medicamento " << j + 1 << ": ";
                                cin >> precios_med[encontrado][j];
                            }
                            cout << "Medicamentos asignados correctamente.\n";
                        } else {
                            cout << "Cantidad de medicamentos no valida.\n";
                        }
                    } else {
                        cout << "Paciente no encontrado.\n";
                    }
                } break;

                case 6:
                    break; // Regresar al menú principal

                default:
                    cout << "Opcion no valida. Intente de nuevo.\n";
                    break;
                }
            } while (subOpcion != 6); // Continuar hasta que el usuario regrese al menú principal
        } break;

        case 3:
            cout << "Saliendo del programa.\n";
            break;

        default:
            cout << "Opcion no valida. Intente de nuevo.\n";
            break;
        }
    } while (opcion != 3);

    return 0;
}
