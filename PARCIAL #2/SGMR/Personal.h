#ifndef PERSONAL_H
#define PERSONAL_H

#include "Recurso.h"

/*
 * Clase intermedia ABSTRACTA que representa al talento humano del sistema.
 */
class Personal : public Recurso {
protected:
    string especialidad;

public:
    Personal(const string& nombre, const string& codigo, const string& especialidad);
    virtual ~Personal();

    void mostrarInfo() const override;
    string getEspecialidad() const;
};

#endif
