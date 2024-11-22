#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Definición de constantes
const int MAX_PACIENTES = 100;
const float PRECIO_MEDICO_GENERAL = 25000;
const float PRECIO_ESPECIALISTA = 80000;
const float PRECIO_REVISION = 0;

// Arreglos para almacenar datos de pacientes
int codigo[MAX_PACIENTES];
string nombre[MAX_PACIENTES];
string apellido[MAX_PACIENTES];
int edad[MAX_PACIENTES];
string genero[MAX_PACIENTES];
string eps[MAX_PACIENTES];
string historia[MAX_PACIENTES];
string medico_asignado[MAX_PACIENTES];
string consultorio_asignado[MAX_PACIENTES];
string medicamentos[MAX_PACIENTES][10]; // Hasta 10 medicamentos por paciente
float precios_med[MAX_PACIENTES][10]; // Precios de los medicamentos asignados

// Arreglos para médicos y consultorios predefinidos
string medicos[5] = {"Juan Lopez", "Maria Perez", "Carlos Ruiz", "Carlos Velasquez", "Sofia Gonzalez"};
string consultorios[5] = {"A1", "B2", "C3", "D4", "E5"};

// Variables para estadísticas
int total_pacientes = 0;
float total_recaudado = 0;
float descuentos_aplicados = 0;
int tipo_cita[3] = {0}; // [0] General, [1] Especialista, [2] Revisión
int pacientes_por_medico[5] = {0}; // Contador por médico
float max_pago = -1, min_pago = 1e9; // Montos que más y menos se pagaron
int paciente_max = -1, paciente_min = -1; // Índices del paciente que más y menos pagaron

void ingresarDatosPaciente(int i) {
    cout << "Ingrese el código del paciente: ";
    cin >> codigo[i];
    cout << "Ingrese el nombre del paciente: ";
    cin >> nombre[i];
    cout << "Ingrese el apellido del paciente: ";
    cin >> apellido[i];
    cout << "Ingrese la edad del paciente: ";
    cin >> edad[i];
    cout << "Ingrese el género del paciente (M/F): ";
    cin >> genero[i];
    cout << "Ingrese la EPS del paciente: ";
    cin >> eps[i];
    historia[i] = "Sin registro"; // Historia clínica vacía inicialmente
}

void asignarMedico(int i) {
    cout << "Médicos disponibles:\n";
    for (int j = 0; j < 5; j++) {
        cout << j + 1 << ". " << medicos[j] << " (Consultorio: " << consultorios[j] << ")\n";
    }
    
    int seleccion;
    cout << "Seleccione el médico: ";
    cin >> seleccion;

    if (seleccion >= 1 && seleccion <= 5) {
        medico_asignado[i] = medicos[seleccion - 1];
        consultorio_asignado[i] = consultorios[seleccion - 1];
        pacientes_por_medico[seleccion - 1]++;
        cout << "Médico asignado: " << medico_asignado[i] 
             << " (Consultorio: " << consultorio_asignado[i] << ")\n";
    } else {
        cout << "Selección inválida.\n";
    }
}

void registrarHistoriaClinica(int i) {
    cout << "Ingrese la historia clínica del paciente: ";
    cin.ignore(); // Limpiar buffer
    getline(cin, historia[i]);
}

void asignarMedicamentos(int i) {
    int num_meds;
    cout << "Cuantos medicamentos desea asignar al paciente? ";
    cin >> num_meds;

    for (int j = 0; j < num_meds; j++) {
        cout << "Ingrese el nombre del medicamento " << j + 1 << ": ";
        cin >> medicamentos[i][j];

        cout << "Ingrese el precio del medicamento " << j + 1 << ": ";
        cin >> precios_med[i][j];
    }
}

float calcularCostoCita(int tipo) {
    switch (tipo) {
        case 1: return PRECIO_MEDICO_GENERAL; // Médico General
        case 2: return PRECIO_ESPECIALISTA;   // Especialista
        case 3: return PRECIO_REVISION;       // Revisión
        default: return 0;                    // Sin costo
    }
}

void mostrarTotalAPagar(int i) {
    float costo_cita;
    
    int tipo_cita_seleccionada;
    cout << "Seleccione el tipo de cita:\n";
    cout << "1. Médico General ($25,000)\n";
    cout << "2. Especialista ($80,000)\n";
    cout << "3. Revisión (Gratis)\n";
    
    cin >> tipo_cita_seleccionada;
    
    costo_cita = calcularCostoCita(tipo_cita_seleccionada);
    
    total_recaudado += costo_cita;

    float total_medicamentos = 0;
    
    for (int j = 0; j < 10 && !medicamentos[i][j].empty(); j++) {
        total_medicamentos += precios_med[i][j];
        if (precios_med[i][j] > 10000) {
            // Contador para medicamentos costosos puede ser implementado aquí si se desea.
        }
    }

    float descuento = (edad[i] < 5) ? total_medicamentos * 0.10 : 
                      (edad[i] > 60) ? total_medicamentos * 0.20 : 
                      0;

    float total_a_pagar = costo_cita + total_medicamentos - descuento;

    descuentos_aplicados += descuento;

    cout << fixed << setprecision(2);
    cout << "\nTotal a pagar por la cita y medicamentos: $" << total_a_pagar << endl;

    // Actualizar el paciente que más y menos pagó
    if (total_a_pagar > max_pago) {
        max_pago = total_a_pagar;
        paciente_max = i;
    }
    
    if (total_a_pagar < min_pago) {
        min_pago = total_a_pagar;
        paciente_min = i;
    }
}

void mostrarReporte() {
   cout << "\nREPORTE DEL DIA\n";
   cout << "Pacientes atendidos: " << total_pacientes << "\n";
   cout << fixed << setprecision(2);
   cout << "Total recaudado: $" << total_recaudado << "\n";
   cout << "Total descuentos aplicados: $" << descuentos_aplicados << "\n";

   // Porcentajes de tipos de cita
   cout << "\nPorcentaje de citas:\n";
   for (int i = 0; i < 3; i++) {
       string tipo[] = {"Medico General", "Medico Especialista", "Revision"};
       int contador_tipo[] = {tipo_cita[0], tipo_cita[1], tipo_cita[2]};
       if (total_pacientes > 0) {
           cout << tipo[i] + ": "
                + to_string((contador_tipo[i] * 100.0 / total_pacientes)) + "%\n";
       }
   }

   // Paciente que más y menos pagó
   if (paciente_max != -1 && paciente_min != -1) {
       cout << "\nPaciente que más pagó: "
            + nombre[paciente_max] + " "
            + apellido[paciente_max] + ", $" 
            + to_string(max_pago) + "\n";

       cout << "\nPaciente que menos pagó: "
            + nombre[paciente_min] + " "
            + apellido[paciente_min] + ", $" 
            + to_string(min_pago) + "\n";
   }

   // Listado de médicos con pacientes atendidos
   cout << "\nPacientes atendidos por médico:\n";
   for (int i = 0; i < 5; i++) {
       cout << medicos[i] + ": "
            + to_string(pacientes_por_medico[i]) + 
            (pacientes_por_medico[i] == 1 ? 
            " paciente\n" : 
            " pacientes\n");
   }
}

int main() {
   int opcion;

   do {
       cout << "\nMENU PRINCIPAL\n";
       cout << "1. Atender paciente\n";
       cout << "2. Mostrar total del día\n";
       cout << "3. Salir\n";
       cout << "Seleccione una opción: ";
       cin >> opcion;

       switch (opcion) {
           case 1:
               if (total_pacientes < MAX_PACIENTES) {
                   int subopcion;
                   do {
                       cout << "\nSUBMENU ATENDER PACIENTE\n";
                       cout << "1. Ingresar datos del paciente\n";
                       cout << "2. Asignar médico\n";
                       cout << "3. Registrar historia clínica\n";
                       cout << "4. Asignar medicamentos\n";
                       cout << "5. Mostrar total a pagar\n";
                       cout << "6. Regresar al menú principal\n";
                       cout << "Seleccione una opción: ";
                       cin >> subopcion;

                       switch (subopcion) {
                           case 1:
                               ingresarDatosPaciente(total_pacientes);
                               break;

                           case 2:
                               asignarMedico(total_pacientes);
                               break;

                           case 3:
                               registrarHistoriaClinica(total_pacientes);
                               break;

                           case 4:
                               asignarMedicamentos(total_pacientes);
                               break;

                           case 5:
                               mostrarTotalAPagar(total_pacientes);
                               break;

                           case 6:
                               break;

                           default:
                               cout << "Opción no válida.\n";
                       }
                   } while (subopcion != 6);
                   total_pacientes++;
               } else {
                   cout << "Capacidad máxima de pacientes alcanzada.\n";
               }
               break;

           case 2:
               mostrarReporte();
               break;

           case 3:
               cout << "Saliendo del programa.\n";
               break;

           default:
               cout << "Opción no válida.\n";
               break;
       }

   } while (opcion != 3);

   return 0;
}
