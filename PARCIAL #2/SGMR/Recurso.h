#ifndef RECURSO_H
#define RECURSO_H

#include <string>
using namespace std;

/*
 * Clase base ABSTRACTA para todo recurso del sistema (vehiculos y personal).
 * Define el contrato polimorfico ejecutarAccion() que cada recurso concreto
 * debe implementar segun su especialidad (HU02, HU03).
 */
class Recurso {
protected:
    string nombre;
    string codigo;
    bool disponible;

public:
    Recurso(const string& nombre, const string& codigo);
    virtual ~Recurso();

    // Metodo virtual puro: cada recurso concreto define su propio comportamiento
    virtual void ejecutarAccion() = 0;

    // Metodo virtual que puede ser extendido (no reemplazado) por las subclases
    virtual void mostrarInfo() const;

    string getNombre() const;
    string getCodigo() const;
    bool isDisponible() const;
    void setDisponible(bool valor);
};

#endif
