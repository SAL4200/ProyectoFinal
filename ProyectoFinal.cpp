#include <iostream>
#include <string>

using namespace std;

int main() {
    // Variables de datos basicos de los pacientes
    int codigo[100];       // Codigo del paciente
    string nombre_p[100];  // Nombre del paciente
    string apellido_p[100]; // Apellido del paciente
    int edad[100];          // Edad del paciente
    string genero[100];     // Genero del paciente
    string eps[100];        // EPS del paciente
    string historia[100];   // Historia clinica de los pacientes

    // Medicos y consultorios predefinidos
    string medicos[5] = { "Juan Lopez", "Maria Perez", "Carlos Ruiz", "Carlos Velasquez", "Sofia Gonzalez" }; // Medicos 
    string consultorio[5] = { "A1", "B2", "C3", "D4", "E5" }; // Consultorios

    // Medicamentos asignados a cada paciente
    string medicamentos[100][10]; // Medicamentos asignados a cada paciente
    float precios_med[100][10] = {}; // Precios de los medicamentos asignados

    // Datos de cita y costos
    int tipo_cita[3] = {}; // Contadores de tipos de cita: 0 = general, 1 = especialista, 2 = revision
    float total_cita[100] = {}; // Costo total de la cita para cada paciente
    float total_descuento[100] = {}; // Descuento aplicado a cada paciente
    float total_recaudado = 0; // Suma total recaudada por todas las citas
    float descuentos_aplicados = 0; // Suma total de descuentos aplicados

    // Contadores y totales por forma de pago
    int pagos_efectivo = 0, pagos_debito = 0, pagos_credito = 0; // Contadores de pagos por metodo
    float recaudado_efectivo = 0, recaudado_debito = 0, recaudado_credito = 0; // Totales recaudados por cada metodo

    // Estadisticas de edad
    int menores_edad = 0, mayores_edad = 0; // Contadores de pacientes menores y mayores de edad

    // Estadisticas de medicamentos
    int medicamentos_costosos = 0; // Pacientes con al menos un medicamento mayor a $10,000

    // Datos sobre pacientes que mas y menos pagaron
    int paciente_max = -1, paciente_min = -1; // Indices del paciente que mas y menos pagaron
    float max_pago = -1, min_pago = 1e9; // Montos que mas y menos se pagaron

    // Contadores para pacientes atendidos por cada medico
    int pacientes_por_medico[5] = {}; // Cantidad de pacientes atendidos por cada medico

    // Contador general de pacientes atendidos
    int total_pacientes = 0; // Total de pacientes atendidos durante el dia

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
            int i = total_pacientes;
            if (total_pacientes < 100) {
                // Ingreso de datos del paciente
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
                string medico_asignado = medicos[seleccion - 1];
                string consultorio_asignado = consultorio[seleccion - 1];
                pacientes_por_medico[seleccion - 1]++; // Incrementar contador de pacientes para el medico

                // Determinar tipo de cita
                int tipo;
                cout << "Seleccione el tipo de cita:\n1. Medico General ($25,000)\n2. Especialista ($80,000)\n3. Revision (Gratis)\n";
                cin >> tipo;
                float costo_cita = 0;
                if (tipo == 1) {
                    costo_cita = 25000;
                    tipo_cita[0]++; // Incrementar contador de citas generales
                }
                else if (tipo == 2) {
                    costo_cita = 80000;
                    tipo_cita[1]++;  // Incrementar contador de citas con especialista
                }
                else if (tipo == 3) {
                    tipo_cita[2]++; // Incrementar contador de revisiones
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
                        medicamentos_costosos++; // Incrementar contador de medicamentos costosos
                }
                total_cita[i] += total_meds;

                // Aplicar descuento por edad
                if (edad[i] < 5) {
                    total_descuento[i] = total_cita[i] * 0.10;
                }
                else if (edad[i] > 60) {
                    total_descuento[i] = total_cita[i] * 0.20;
                }
                // Aplicar descuento al costo total de la cita
                total_cita[i] -= total_descuento[i];
                descuentos_aplicados += total_descuento[i];

                // Determinar forma de pago
                int forma_pago;
                float recibido = 0;
                cout << "Seleccione el metodo de pago:\n1. Efectivo\n2. Tarjeta Debito\n3. Tarjeta Credito\n";
                cin >> forma_pago;

                if (forma_pago == 1) {
                    cout << "Ingrese el monto recibido en efectivo: ";
                    cin >> recibido;
                    pagos_efectivo++;
                    recaudado_efectivo += total_cita[i];
                    if (recibido > total_cita[i])
                        cout << "Devuelta: $" << recibido - total_cita[i] << "\n";
                }
                else if (forma_pago == 2) {
                    pagos_debito++;
                    recaudado_debito += total_cita[i];
                }
                else if (forma_pago == 3) {
                    pagos_credito++;
                    recaudado_credito += total_cita[i];
                }

                total_recaudado += total_cita[i]; // Actualizar total recaudado

                // Actualizar el paciente que más y menos pagó
                if (total_cita[i] > max_pago) {
                    max_pago = total_cita[i];
                    paciente_max = i;
                }
                if (total_cita[i] < min_pago) {
                    min_pago = total_cita[i];
                    paciente_min = i;
                }

                // Actualizar estadísticas de edad
                if (edad[i] < 18)
                    menores_edad++;
                else
                    mayores_edad++;

                total_pacientes++; // Incrementar el total de pacientes atendidos
            }
            else {
                cout << "Capacidad maxima de pacientes alcanzada.\n";
            }
        } break;

        case 2: {
            // Mostrar reporte del día
            cout << "\nREPORTE DEL DIA\n";
            cout << "Pacientes atendidos: " << total_pacientes << "\n";
            cout << "Total recaudado: $" << total_recaudado << "\n";
            cout << "Total descuentos aplicados: $" << descuentos_aplicados << "\n";

            // Porcentajes de tipos de cita
            cout << "Porcentaje de citas:\n";
            cout << "  Medico General: " << (tipo_cita[0] * 100.0 / total_pacientes) << "%\n";
            cout << "  Medico Especialista: " << (tipo_cita[1] * 100.0 / total_pacientes) << "%\n";
            cout << "  Revision: " << (tipo_cita[2] * 100.0 / total_pacientes) << "%\n";

            // Pacientes que más y menos pagaron
            cout << "Paciente que mas pago: " << nombre_p[paciente_max] << " " << apellido_p[paciente_max] << ", $" << max_pago << "\n";
            cout << "Paciente que menos pago: " << nombre_p[paciente_min] << " " << apellido_p[paciente_min] << ", $" << min_pago << "\n";

            // Recaudado por formas de pago
            cout << "Recaudado por forma de pago:\n";
            cout << "  Efectivo: $" << recaudado_efectivo << "\n";
            cout << "  Tarjeta Debito: $" << recaudado_debito << "\n";
            cout << "  Tarjeta Credito: $" << recaudado_credito << "\n";

            // Estadísticas de género y edad
            int hombres = 0, mujeres = 0;
            for (int i = 0; i < total_pacientes; i++) {
                if (genero[i] == "M")
                    hombres++;
                else if (genero[i] == "F")
                    mujeres++;
            }
            cout << "Porcentaje por genero:\n";
            cout << "  Masculino: " << (hombres * 100.0 / total_pacientes) << "%\n";
            cout << "  Femenino: " << (mujeres * 100.0 / total_pacientes) << "%\n";
            cout << "Porcentaje de menores de edad: " << (menores_edad * 100.0 / total_pacientes) << "%\n";
            cout << "Porcentaje de mayores de edad: " << (mayores_edad * 100.0 / total_pacientes) << "%\n";

            // Pacientes con medicamentos costosos
            cout << "Pacientes con medicamentos > $10,000: " << medicamentos_costosos << "\n";

            // Listado de médicos y pacientes atendidos
            cout << "Pacientes atendidos por medico:\n";
            for (int i = 0; i < 5; i++) {
                cout << medicos[i] << ": " << pacientes_por_medico[i] << " pacientes\n";
            }
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

