#include "Medico.h"
#include <iostream>
using namespace std;

Medico::Medico(const string& nombre, const string& codigo, const string& especialidad)
    : Personal(nombre, codigo, especialidad) {
}

void Medico::ejecutarAccion() {
    cout << "  [MEDICO " << codigo << "] Estabilizando signos vitales." << endl;
}

void Medico::mostrarInfo() const {
    cout << "[Medico] ";
    Personal::mostrarInfo();
    cout << endl;
}
