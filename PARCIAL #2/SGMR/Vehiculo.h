#ifndef VEHICULO_H
#define VEHICULO_H

#include "Recurso.h"

/*
 * Clase intermedia ABSTRACTA que representa recursos de tipo vehicular.
 * Sigue siendo abstracta: no implementa ejecutarAccion().
 */
class Vehiculo : public Recurso {
protected:
    string placa;
    int capacidad;

public:
    Vehiculo(const string& nombre, const string& codigo, const string& placa, int capacidad);
    virtual ~Vehiculo();

    void mostrarInfo() const override;

    string getPlaca() const;
    int getCapacidad() const;
};

#endif
