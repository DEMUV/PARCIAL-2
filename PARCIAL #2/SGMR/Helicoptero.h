#ifndef HELICOPTERO_H
#define HELICOPTERO_H

#include "Vehiculo.h"

class Helicoptero : public Vehiculo {
public:
    Helicoptero(const string& nombre, const string& codigo, const string& placa, int capacidad);
    void ejecutarAccion() override;
    void mostrarInfo() const override;
};

#endif
