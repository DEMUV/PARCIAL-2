#ifndef AMBULANCIA_H
#define AMBULANCIA_H

#include "Vehiculo.h"

class Ambulancia : public Vehiculo {
public:
    Ambulancia(const string& nombre, const string& codigo, const string& placa, int capacidad);
    void ejecutarAccion() override;
    void mostrarInfo() const override;
};

#endif
