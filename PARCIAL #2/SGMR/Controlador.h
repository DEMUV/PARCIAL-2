#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include "Recurso.h"
#include "Mision.h"
#include "Ambulancia.h"
#include "Helicoptero.h"
#include "Medico.h"
#include "Rescatista.h"

/*
 * Clase Controladora (HU04). Es la UNICA clase que main.cpp instancia.
 * Administra dos colecciones generales del sistema usando arreglos de
 * punteros dinamicos (prohibido std::vector, ver HT01):
 *   - listaRecursos: todos los vehiculos y personal registrados.
 *   - listaMisiones: todas las misiones creadas.
 * Es la DUENA real de todos los objetos Recurso y Mision: los crea con
 * new y los libera con delete en su destructor (HT02).
 */
class Controlador {
private:
    Recurso** listaRecursos;
    int cantidadRecursos;
    int capacidadRecursos;

    Mision** listaMisiones;
    int cantidadMisiones;
    int capacidadMisiones;

    void redimensionarRecursos();
    void redimensionarMisiones();
    void agregarRecurso(Recurso* nuevo);

    void cargarDatosPrueba(); // HU05: datos quemados

    void mostrarMenu() const;
    void verRecursos() const;
    void registrarRecurso();
    void crearMision();
    void asignarRecursoAMision();
    void ejecutarMisionMenu();

public:
    Controlador();
    ~Controlador();

    void iniciar(); // unico metodo publico que invoca main.cpp
};

#endif
