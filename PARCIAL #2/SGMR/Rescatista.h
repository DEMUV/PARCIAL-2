#ifndef RESCATISTA_H
#define RESCATISTA_H

#include "Personal.h"

class Rescatista : public Personal {
public:
    Rescatista(const string& nombre, const string& codigo, const string& especialidad);
    void ejecutarAccion() override;
    void mostrarInfo() const override;
};

#endif
