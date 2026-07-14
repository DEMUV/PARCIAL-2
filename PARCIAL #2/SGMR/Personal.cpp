#include "Personal.h"
#include <iostream>
using namespace std;

Personal::Personal(const string& nombre, const string& codigo, const string& especialidad)
    : Recurso(nombre, codigo), especialidad(especialidad) {
}

Personal::~Personal() {
}

void Personal::mostrarInfo() const {
    Recurso::mostrarInfo();
    cout << " | Especialidad: " << especialidad;
}

string Personal::getEspecialidad() const { return especialidad; }
