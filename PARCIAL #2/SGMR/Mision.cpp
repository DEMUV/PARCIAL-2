#include "Mision.h"
#include <iostream>
using namespace std;

Mision::Mision(const string& nombre, const string& zonaAfectada)
    : nombre(nombre), zonaAfectada(zonaAfectada), estado("Pendiente"),
      cantidadRecursos(0), capacidadRecursos(4) {
    recursosAsignados = new Recurso*[capacidadRecursos];
}

Mision::~Mision() {
    // Solo se libera el arreglo de PUNTEROS, no los objetos Recurso
    // (su dueno real es el Controlador -> evita doble free / dangling pointers).
    delete[] recursosAsignados;
}

void Mision::redimensionar() {
    int nuevaCapacidad = capacidadRecursos * 2;
    Recurso** nuevoArreglo = new Recurso*[nuevaCapacidad];
    for (int i = 0; i < cantidadRecursos; i++) {
        nuevoArreglo[i] = recursosAsignados[i];
    }
    delete[] recursosAsignados;
    recursosAsignados = nuevoArreglo;
    capacidadRecursos = nuevaCapacidad;
}

void Mision::asignarRecurso(Recurso* recurso) {
    if (recurso == nullptr) return;
    if (cantidadRecursos == capacidadRecursos) {
        redimensionar();
    }
    recursosAsignados[cantidadRecursos] = recurso;
    cantidadRecursos++;
    recurso->setDisponible(false);
}

void Mision::ejecutarMision() {
    if (cantidadRecursos == 0) {
        cout << "La mision \"" << nombre << "\" no tiene recursos asignados." << endl;
        return;
    }
    cout << "\n>>> Ejecutando mision: " << nombre << " (" << zonaAfectada << ") <<<" << endl;
    for (int i = 0; i < cantidadRecursos; i++) {
        // Llamada polimorfica: cada recurso decide como ejecutar su accion (HU03)
        recursosAsignados[i]->ejecutarAccion();
    }
    estado = "Finalizada";
    cout << "Mision \"" << nombre << "\" finalizada.\n" << endl;
}

void Mision::mostrarInfo() const {
    cout << "Mision: " << nombre << " | Zona: " << zonaAfectada
         << " | Estado: " << estado << " | Recursos asignados: " << cantidadRecursos << endl;
    for (int i = 0; i < cantidadRecursos; i++) {
        cout << "   - ";
        recursosAsignados[i]->mostrarInfo();
    }
}

string Mision::getNombre() const { return nombre; }
string Mision::getEstado() const { return estado; }
int Mision::getCantidadRecursos() const { return cantidadRecursos; }
