/*Para solucionar el problema de 
#include errors detected
y el de 
cannot open source file vuelo.h 
se debe incluir la ruta relativa del archivo 

Como en este caso vuelo se encuentra en la carpeta source

#include "../include/vuelo.h"

esto nos dice: 
"Busca hacia atrás un nivel (../) y luego entra en la carpeta include/ para encontrar vuelo.h".
*/
#include "../include/vuelo.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

// Implementacion del constructor

Vuelo::Vuelo(string cod, string orig, string dest,
string hSalida, string hLlegada, int cap, string tipo) {
    codigoVuelo = cod;
    origen = orig;
    destino = dest;
    horaSalida = hSalida;
    horaLlegada = hLlegada;
    capacidad = cap;
    tipoAvion = tipo;
    activo = true; // Esta activo por defecto    
}

// Implementacion de Getters
string Vuelo::getCodigo() const {
    return codigoVuelo;
}

string Vuelo::getOrigen() const {
    return origen;
}

string Vuelo::getDestino() const {
    return destino;
}

string Vuelo::getHoraSalida() const {
    return horaSalida;
}

string Vuelo::getHoraLlegada() const {
    return horaLlegada;
}

int Vuelo::getCapacidad() const {
    return capacidad;
}

string Vuelo::getTipoAvion() const {
    return tipoAvion;
}

bool Vuelo::estaActivo() const {
    return activo;
}

// Otros metodos de la clase
void Vuelo::desactivar() {
    activo = false;
}

// Implementacion de los setters
void Vuelo::setOrigen(string nuevo) {
    origen = nuevo;
}

void Vuelo::setDestino(string nuevo) {
    destino = nuevo;
}

void Vuelo::setHoraSalida(string nueva) {
    horaSalida = nueva;
}

void Vuelo::setHoraLlegada(string nueva) {
    horaLlegada = nueva;
}

void Vuelo::setCapacidad(int nueva) {
    capacidad = nueva;
}

void Vuelo::setTipoAvion(string nuevo) {
    tipoAvion = nuevo;
}


// Metodo para mostrar los detalles del vuelo
void Vuelo::mostrar() {
cout << "\nCodigo: " << codigoVuelo << endl;    
cout << "Origen: " << origen << endl ;
cout << "Destino: " << destino<< endl ;
cout << "Hora Salida: " << horaSalida << endl ;
cout << "Hora Llegada: " << horaLlegada<< endl ;
cout << "Capacidad: " << capacidad << endl ;
cout << "Tipo Avion: " << tipoAvion << endl ;
cout << "Estado: " << (activo ? "Activo" : "Inactivo") << endl ;   
}

// Funcion externa para agregar un vuelo nuevo a la lista
void agregarVuelo(vector<Vuelo>& lista) {
    string codigo, origen, destino, horaSalida, horaLlegada, tipoAvion;
    int capacidad;

    cout << "Ingrese código del vuelo: ";
    cin >> codigo;

    // Validación: evitar duplicados
    for (auto v : lista) {
        if (v.getCodigo() == codigo && v.estaActivo()) {
            cout << "Error: Ya existe un vuelo con ese código.\n";
            return;
        }
    }

    cout << "Origen: ";
    cin.ignore();
    getline(cin, origen);

    cout << "Destino: ";
    getline(cin, destino);

    cout << "Hora de salida (HH:MM): ";
    getline(cin, horaSalida);

    cout << "Hora de llegada (HH:MM): ";
    getline(cin, horaLlegada);

    cout << "Capacidad del avión: ";
    cin >> capacidad;

    cout << "Tipo de avión: ";
    cin.ignore();
    getline(cin, tipoAvion);

    // Agregar nuevo vuelo al vector
    lista.push_back(Vuelo(codigo, origen, destino, horaSalida, horaLlegada, capacidad, tipoAvion));
    cout << "Vuelo agregado exitosamente.\n";
}

// Editar un vuelo existente
void editarVuelo(vector<Vuelo>& lista) {
    string codigo;
    cout << "Ingrese el codigo del vuelo a editar: ";
    cin >> codigo;

    for(int i = 0 ; i < lista.size() ; i++ ) {
        if(lista[i].getCodigo() == codigo && lista[i].estaActivo()) {
            int opcion;
            do {
                cout << "\n Editar un vuelo \n";
                cout << "1. Origen: \n";
                cout << "2. Destino: \n";
                cout << "3. Hora de Salida: \n";
                cout << "4. Hora de salida: \n";
                cout << "5. Capacidad: \n";
                cout << "6. Tipo de avion: \n";
                cout << "7. Finalizar edicion\n ";
                cout << "Seleccione una opcion: ";
                cin >> opcion ;

                switch (opcion) {
                    case 1: {
                        string nuevo;
                        cout << "Nuevo origen: ";
                        cin.ignore();
                        getline(cin,nuevo);
                        lista[i].setOrigen(nuevo);
                        break;
                    }
                    case 2: {
                        string nuevo;
                        cout << "Nuevo destino: ";
                        cin.ignore();
                        getline(cin,nuevo);
                        lista[i].setDestino(nuevo);
                        break;
                    }
                    case 3: {
                        string nueva;
                        cout << "Nueva hora de salida (HH:MM): ";
                        cin >> nueva;
                        lista[i].setHoraSalida(nueva);
                        break;
                    }
                    case 4: {
                        string nueva;
                        cout << "Nueva hora de llegada (HH:MM): ";
                        cin >> nueva;
                        lista[i].setHoraLlegada(nueva);
                        break;
                    }
                    case 5: {
                        int nueva;
                        cout << "Nueva capacidad: ";
                        cin >> nueva;
                        lista[i].setCapacidad(nueva);
                        break;
                    }

                    case 6: {
                        string nuevo;
                        cout << "Nuevo tipo de avion: ";
                        cin.ignore();
                        getline(cin, nuevo);
                        lista[i].setTipoAvion(nuevo);
                        break;
                    }
                    case 7: 
                        cout << "Cambios guardados.\n";
                            break;
                    default:
                        cout << "Opcion no valida \n";      
                }
            } while (opcion != 7);
            return;
        }
    }
    cout << "No se encontro el vuelo o esta inactivo \n";
}

// Eliminar un vuelo
void eliminarLogicoVuelo(vector<Vuelo>& lista) {
    string codigo;
    cout << "Ingrese el codigo del vuelo a eliminar: ";
    cin >> codigo;

    for (int i = 0 ; i < lista.size(); i++) {
        if(lista[i].getCodigo() == codigo && lista[i].estaActivo()) {
            char confirmacion;
            cout << "Esta seguro de eliminar este vuelo? (S/N): ";
            cin >> confirmacion;
            
            if(confirmacion == 'S' || confirmacion == 's') {
                lista[i].desactivar();
                cout << "Vuelo marcado como inactivo. \n";
            } else {
                cout << "Accion cancelada \n";
            }
        }
        return;
    }
    cout << "Vuelo no encontrado o ya esta inactivo \n";
}


// Consultar un vuelo especifico
// Cambio: Quite el const
void consultarVuelo(vector<Vuelo>& lista) {
    string codigo;
    cout << "Ingrese el codigo del vuelo a consultar: ";
    cin >> codigo;

    for (auto v : lista) {
        if (v.getCodigo() == codigo && v.estaActivo()) {
            v.mostrar();
            return;
        }
    }

    cout << "Vuelo no encontrado o inactivo.\n";
}

// Listar todos los vuelos activos
void listarVuelos(const vector<Vuelo>& lista) {
    cout << "\n Listado de vuelos activos \n";

    bool hayActivos = false;

    for (auto v: lista) {
        if (v.estaActivo()) {
            v.mostrar();
            cout << "----------------------\n";
            hayActivos = true;
        }
    }

    if (!hayActivos) {
        cout << "No hay vuelos activos \n";
    }
}


// Guardar vuelos en archivo de texto
void guardarVuelos(const vector<Vuelo>& lista, const string& nombreArchivo) {
    ofstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cout << " Error al abrir el archivo para guardar.\n";
        return;
    }

    for (const auto& v : lista) {
        if (v.estaActivo()) {
            archivo << v.getCodigo() << "\n"
                    << v.getOrigen() << "\n"
                    << v.getDestino() << "\n"
                    << v.getHoraSalida() << "\n"
                    << v.getHoraLlegada() << "\n"
                    << v.getCapacidad() << "\n"
                    << v.getTipoAvion() << "\n"
                    << (v.estaActivo() ? "1\n" : "0\n");
        }
    }

    archivo.close();
    cout << " Datos guardados correctamente.\n";
}

// Cargar vuelos desde archivo de texto
vector<Vuelo> cargarVuelos(const string& nombreArchivo) {
    vector<Vuelo> lista;
    ifstream archivo(nombreArchivo);

    if (!archivo.is_open()) {
        cout << " Archivo no encontrado. Iniciando con lista vacía.\n";
        return lista;
    }

    string codigo, origen, destino, horaSalida, horaLlegada, tipoAvion;
    int capacidad;
    string estadoStr;
    bool activo;

    while (getline(archivo, codigo)) {
        getline(archivo, origen);
        getline(archivo, destino);
        getline(archivo, horaSalida);
        getline(archivo, horaLlegada);
        archivo >> capacidad;
        archivo.ignore();  // Saltar el salto de línea
        getline(archivo, tipoAvion);
        archivo >> estadoStr;
        archivo.ignore();

        Vuelo nuevo(codigo, origen, destino, horaSalida, horaLlegada, capacidad, tipoAvion);
        activo = (estadoStr == "1");
        if (!activo) {
            nuevo.desactivar();
        }

        lista.push_back(nuevo);
    }

    archivo.close();
    cout << " Datos cargados correctamente.\n";
    return lista;
}
