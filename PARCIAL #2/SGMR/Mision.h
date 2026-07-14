#ifndef MISION_H
#define MISION_H

#include <string>
#include "Recurso.h"
using namespace std;

/*
 * Representa una mision de rescate. Almacena un arreglo dinamico de PUNTEROS
 * a Recurso (clase base) para poder guardar de forma homogenea recursos
 * heterogeneos (ambulancias, helicopteros, medicos, rescatistas) -> HU02.
 *
 * IMPORTANTE: la Mision NO es duena de los objetos Recurso (esos los crea y
 * destruye el Controlador). La Mision solo guarda punteros de referencia,
 * por eso su destructor unicamente libera el arreglo de punteros (delete[])
 * y jamas hace delete sobre cada Recurso*.
 */
class Mision {
private:
    string nombre;
    string zonaAfectada;
    string estado; // "Pendiente" | "En ejecucion" | "Finalizada"

    Recurso** recursosAsignados; // arreglo dinamico de punteros (HT01)
    int cantidadRecursos;
    int capacidadRecursos;

    void redimensionar();

public:
    Mision(const string& nombre, const string& zonaAfectada);
    ~Mision();

    void asignarRecurso(Recurso* recurso); // paso por puntero (HT03)
    void ejecutarMision();                  // recorre y ejecuta polimorficamente (HU03)
    void mostrarInfo() const;

    string getNombre() const;
    string getEstado() const;
    int getCantidadRecursos() const;
};

#endif
