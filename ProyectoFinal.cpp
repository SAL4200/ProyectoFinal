#include <iostream>
#include <string>

using namespace std;

int main() {
    int codigo[100];       // Codigo del paciente
    string nombre_p[100];  // Nombre del paciente
    string apellido_p[100]; // Apellido del paciente
    int edad[100];          // Edad del paciente
    string genero[100];     // Genero del paciente
    string eps[100];        // EPS del paciente
    string medicos[5] = { "Juan Lopez", "Maria Perez", "Carlos Ruiz", "Carlos Velasquez", "Sofia Gonzalez" }; // Medicos
    string historia[100];   // Historia clinica de los pacientes
    string medicamentos[100][10]; // Medicamentos asignados a cada paciente
    float precios_med[100][10] = {}; // Precios de los medicamentos asignados
    string consultorio[5] = { "A1", "B2", "C3", "D4", "E5" }; // Consultorios
    string medico_asignado[100]; // Medico asignado al paciente
    string consultorio_asignado[100]; // Consultorio asignado
    int tipo_cita[3] = {}; // Contadores: 0 = general, 1 = especialista, 2 = revision
    float total_cita[100] = {}; // Costo total de la cita por paciente
    float total_descuento[100] = {}; // Descuento aplicado por paciente
    float total_recaudado = 0; // Total recaudado
    float descuentos_aplicados = 0; // Total descuentos aplicados
    int pagos_efectivo = 0, pagos_debito = 0, pagos_credito = 0; // Contadores de formas de pago
    float recaudado_efectivo = 0, recaudado_debito = 0, recaudado_credito = 0; // Totales por forma de pago
    int menores_edad = 0, mayores_edad = 0; // Contadores de menores y mayores de edad
    int pacientes_con_descuento = 0; // Pacientes con descuento aplicado
    int medicamentos_costosos = 0; // Pacientes con medicamentos mayores a $10,000
    int total_pacientes = 0; // Total pacientes atendidos

    int opcion;

    do {
        cout << "\nMENU PRINCIPAL\n"; 
        cout << "1. Atender paciente\n";
        cout << "2. Mostrar total del dia\n";
        cout << "3. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1: {
            if (total_pacientes < 100) {
                int i = total_pacientes;
                cout << "Ingrese el codigo del paciente: ";
                cin >> codigo[i];
                cout << "Ingrese el nombre del paciente: ";
                cin >> nombre_p[i];
                cout << "Ingrese el apellido del paciente: ";
                cin >> apellido_p[i];
                cout << "Ingrese la edad del paciente: ";
                cin >> edad[i];
                cout << "Ingrese el genero del paciente (M/F): ";
                cin >> genero[i];
                cout << "Ingrese la EPS del paciente: ";
                cin >> eps[i];
                historia[i] = "Sin registro";

                // Asignar medico y consultorio
                cout << "Medicos disponibles:\n";
                for (int j = 0; j < 5; j++) 
                    cout << j + 1 << ". " << medicos[j] << " (Consultorio: " << consultorio[j] << ")\n";
                int seleccion;
                cout << "Seleccione el medico: ";
                cin >> seleccion;
                medico_asignado[i] = medicos[seleccion - 1];
                consultorio_asignado[i] = consultorio[seleccion - 1];

                // Determinar tipo de cita
                int tipo;
                cout << "Seleccione el tipo de cita:\n1. Medico General ($25,000)\n2. Especialista ($80,000)\n3. Revision (Gratis)\n";
                cin >> tipo;
                float costo_cita = 0;
                if (tipo == 1) {
                    costo_cita = 25000;
                    tipo_cita[0]++;
                } else if (tipo == 2) {
                    costo_cita = 80000;
                    tipo_cita[1]++;
                } else if (tipo == 3) {
                    tipo_cita[2]++;
                }
                total_cita[i] = costo_cita;

                // Asignar medicamentos
                int num_meds;
                cout << "Cuantos medicamentos desea asignar al paciente? ";
                cin >> num_meds;
                float total_meds = 0;
                for (int j = 0; j < num_meds; j++) {
                    cout << "Ingrese el nombre del medicamento " << j + 1 << ": ";
                    cin >> medicamentos[i][j];
                    cout << "Ingrese el precio del medicamento " << j + 1 << ": ";
                    cin >> precios_med[i][j];
                    total_meds += precios_med[i][j];
                    if (precios_med[i][j] > 10000)
                        medicamentos_costosos++;
                }
                total_cita[i] += total_meds;

                // Aplicar descuento por edad
                if (edad[i] < 5) {
                    total_descuento[i] = total_cita[i] * 0.10;
                    pacientes_con_descuento++;
                } else if (edad[i] > 60) {
                    total_descuento[i] = total_cita[i] * 0.20;
                    pacientes_con_descuento++;
                }
                total_cita[i] -= total_descuento[i];
                descuentos_aplicados += total_descuento[i];

                // Determinar forma de pago
                int forma_pago;
                cout << "Seleccione el metodo de pago:\n1. Efectivo\n2. Tarjeta Debito\n3. Tarjeta Credito\n";
                cin >> forma_pago;
                if (forma_pago == 1) {
                    pagos_efectivo++;
                    recaudado_efectivo += total_cita[i];
                } else if (forma_pago == 2) {
                    pagos_debito++;
                    recaudado_debito += total_cita[i];
                } else if (forma_pago == 3) {
                    pagos_credito++;
                    recaudado_credito += total_cita[i];
                }
                total_recaudado += total_cita[i];

                // Contar menores y mayores de edad
                if (edad[i] < 18) 
                    menores_edad++;
                else 
                    mayores_edad++;

                total_pacientes++;
            } else {
                cout << "Capacidad maxima de pacientes alcanzada.\n";
            }
        } break;

        case 2: {
            cout << "\nREPORTE DEL DIA\n";
            cout << "Pacientes atendidos: " << total_pacientes << "\n";
            cout << "Total recaudado: $" << total_recaudado << "\n";
            cout << "Total descuentos aplicados: $" << descuentos_aplicados << "\n";
            cout << "Porcentaje de citas:\n";
            cout << "  Medico General: " << (tipo_cita[0] * 100.0 / total_pacientes) << "%\n";
            cout << "  Medico Especialista: " << (tipo_cita[1] * 100.0 / total_pacientes) << "%\n";
            cout << "  Revision: " << (tipo_cita[2] * 100.0 / total_pacientes) << "%\n";
            cout << "Recaudado por forma de pago:\n";
            cout << "  Efectivo: $" << recaudado_efectivo << "\n";
            cout << "  Tarjeta Debito: $" << recaudado_debito << "\n";
            cout << "  Tarjeta Credito: $" << recaudado_credito << "\n";
            cout << "Pacientes menores de edad: " << menores_edad << "\n";
            cout << "Pacientes mayores de edad: " << mayores_edad << "\n";
            cout << "Pacientes con descuento: " << pacientes_con_descuento << "\n";
            cout << "Pacientes con medicamentos > $10,000: " << medicamentos_costosos << "\n";
        } break;

        case 3:
            cout << "Saliendo del programa.\n";
            break;

        default:
            cout << "Opcion no valida.\n";
        }
    } while (opcion != 3);

    return 0;
}
