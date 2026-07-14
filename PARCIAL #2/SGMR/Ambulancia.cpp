#include "Ambulancia.h"
#include <iostream>
using namespace std;

Ambulancia::Ambulancia(const string& nombre, const string& codigo, const string& placa, int capacidad)
    : Vehiculo(nombre, codigo, placa, capacidad) {
}

void Ambulancia::ejecutarAccion() {
    cout << "  [AMBULANCIA " << codigo << "] Transportando paciente via terrestre." << endl;
}

void Ambulancia::mostrarInfo() const {
    cout << "[Ambulancia] ";
    Vehiculo::mostrarInfo();
    cout << endl;
}
