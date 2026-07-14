#include "Vehiculo.h"
#include <iostream>
using namespace std;

Vehiculo::Vehiculo(const string& nombre, const string& codigo, const string& placa, int capacidad)
    : Recurso(nombre, codigo), placa(placa), capacidad(capacidad) {
}

Vehiculo::~Vehiculo() {
}

void Vehiculo::mostrarInfo() const {
    Recurso::mostrarInfo();
    cout << " | Placa: " << placa << " | Capacidad: " << capacidad;
}

string Vehiculo::getPlaca() const { return placa; }
int Vehiculo::getCapacidad() const { return capacidad; }
