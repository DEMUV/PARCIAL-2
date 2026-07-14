#include "Controlador.h"

/*
 * Punto de entrada del programa (HU04).
 * main.cpp UNICAMENTE instancia el Controlador e invoca su metodo iniciar().
 * Toda la logica del sistema vive dentro de la clase Controlador.
 */
int main() {
    Controlador controlador;
    controlador.iniciar();
    return 0;
}
