#include "Recurso.h"
#include <iostream>
using namespace std;

Recurso::Recurso(const string& nombre, const string& codigo)
    : nombre(nombre), codigo(codigo), disponible(true) {
}

Recurso::~Recurso() {
    // Destructor virtual vacio: garantiza liberacion polimorfica correcta (HT02)
}

void Recurso::mostrarInfo() const {
    cout << "Codigo: " << codigo << " | Nombre: " << nombre
         << " | Disponible: " << (disponible ? "Si" : "No");
}

string Recurso::getNombre() const { return nombre; }
string Recurso::getCodigo() const { return codigo; }
bool Recurso::isDisponible() const { return disponible; }
void Recurso::setDisponible(bool valor) { disponible = valor; }
