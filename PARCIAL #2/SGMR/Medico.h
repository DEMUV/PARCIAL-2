#ifndef MEDICO_H
#define MEDICO_H

#include "Personal.h"

class Medico : public Personal {
public:
    Medico(const string& nombre, const string& codigo, const string& especialidad);
    void ejecutarAccion() override;
    void mostrarInfo() const override;
};

#endif
