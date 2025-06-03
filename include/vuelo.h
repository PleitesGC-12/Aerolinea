#ifndef VUELO_H
#define VUELO_H

#include <string>
#include <vector>

using namespace std;

class Vuelo {
private:
    string codigoVuelo;
    string origen;
    string destino;
    string horaSalida;
    string horaLlegada;
    int capacidad;
    string tipoAvion;
    bool activo;

public:
    // Constructor
    Vuelo(string cod, string orig, string dest,
          string hSalida, string hLlegada, int cap, string tipo);

    // Getters
    string getCodigo() const;
    string getOrigen() const;
    string getDestino() const;
    string getHoraSalida() const;
    string getHoraLlegada() const; 
    int getCapacidad() const;      
    string getTipoAvion() const;
    bool estaActivo() const;   
    
    // Setters
    void setOrigen(string nuevo);
    void setDestino(string nuevo);
    void setHoraSalida(string nueva);
    void setHoraLlegada(string nueva);
    void setCapacidad(int nueva);
    void setTipoAvion(string nuevo);

    // Otros métodos
    void desactivar();       
    void mostrar();

};

//  Funciones Externas 
void agregarVuelo(vector<Vuelo>& lista);
void editarVuelo(vector<Vuelo>& lista);
void eliminarLogicoVuelo(vector<Vuelo>& lista);
void consultarVuelo(vector<Vuelo>& lista);
void listarVuelos(vector<Vuelo>& lista);

// Guardara los vuelos en el archivo binario
void guardarVuelos(const vector<Vuelo>& lista, const string& nombreArchivo);
// Cargara los vuelos desde el archivo binario
vector<Vuelo> cargarVuelos(const string& nombreArchivo);

#endif // 