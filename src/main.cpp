#include "../include/vuelo.h"
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void mostrarMenu() {
    cout << endl;
    cout << setw(40) << setfill('=') << "" << endl;
    cout << setw(25) << setfill(' ') << "=== Menu Principal ===" << endl;
    cout << setw(40) << setfill(' ') << "" << endl;
    cout << left << setw(30) << "1. Agregar vuelo" << right << setw(10) << "" << endl;
    cout << left << setw(30) << "2. Editar vuelo" << right << setw(10) << "" << endl;
    cout << left << setw(30) << "3. Eliminar vuelo" << right << setw(10) << "" << endl;
    cout << left << setw(30) << "4. Consultar vuelo" << right << setw(10) << "" << endl;
    cout << left << setw(30) << "5. Listar todos los vuelos activos" << right << setw(10) << "" << endl;
    cout << left << setw(30) << "6. Guardar todos los datos en un archivo" << right << setw(10) << "" << endl;
    cout << left << setw(30) << "7. Cargar datos desde archivo" << right << setw(10) << "" << endl;
    cout << left << setw(30) << "8. Salir" << right << setw(10) << "" << endl;
    cout << setw(40) << setfill('-') << "" << endl; // Línea decorativa final
    cout << "Seleccione una opción: ";
}

int main() {
    vector<Vuelo> listaVuelos; // Lista que almacena la información de todos los vuelos
    string nombreArchivo = "data/vuelos.txt"; // Ruta del archivo de texto

    // Cargar datos desde el archivo al iniciar el programa
    listaVuelos = cargarVuelos(nombreArchivo);

    int opcion;
    do {
        mostrarMenu();
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                agregarVuelo(listaVuelos);
                break;
            case 2:
                editarVuelo(listaVuelos);
                break;
            case 3:
                eliminarLogicoVuelo(listaVuelos);
                break;
            case 4:
                consultarVuelo(listaVuelos);
                break;
            case 5:
                listarVuelos(listaVuelos);
                break;
            case 6:
                guardarVuelos(listaVuelos, nombreArchivo);
                break;
            case 7:
                listaVuelos = cargarVuelos(nombreArchivo);
                break;
            case 8:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opción no válida. Intente de nuevo\n";
        }
    } while (opcion != 8);

    // Guardar datos automáticamente al salir
    guardarVuelos(listaVuelos, nombreArchivo);

    return 0;
}