#include "Rescatista.h"
#include <iostream>
using namespace std;

Rescatista::Rescatista(const string& nombre, const string& codigo, const string& especialidad)
    : Personal(nombre, codigo, especialidad) {
}

void Rescatista::ejecutarAccion() {
    cout << "  [RESCATISTA " << codigo << "] Buscando sobrevivientes en escombros." << endl;
}

void Rescatista::mostrarInfo() const {
    cout << "[Rescatista] ";
    Personal::mostrarInfo();
    cout << endl;
}
