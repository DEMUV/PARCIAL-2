#include "Helicoptero.h"
#include <iostream>
using namespace std;

Helicoptero::Helicoptero(const string& nombre, const string& codigo, const string& placa, int capacidad)
    : Vehiculo(nombre, codigo, placa, capacidad) {
}

void Helicoptero::ejecutarAccion() {
    cout << "  [HELICOPTERO " << codigo << "] Realizando extraccion aerea." << endl;
}

void Helicoptero::mostrarInfo() const {
    cout << "[Helicoptero] ";
    Vehiculo::mostrarInfo();
    cout << endl;
}
