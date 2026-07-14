#include "Controlador.h"
#include <iostream>
#include <limits>
using namespace std;

Controlador::Controlador()
    : cantidadRecursos(0), capacidadRecursos(4),
      cantidadMisiones(0), capacidadMisiones(4) {
    listaRecursos = new Recurso*[capacidadRecursos];
    listaMisiones = new Mision*[capacidadMisiones];
    cargarDatosPrueba();
}

Controlador::~Controlador() {
    // Liberacion segura y completa de toda la memoria dinamica (HT02)
    for (int i = 0; i < cantidadRecursos; i++) {
        delete listaRecursos[i]; // delete polimorfico gracias al destructor virtual
    }
    delete[] listaRecursos;

    for (int i = 0; i < cantidadMisiones; i++) {
        delete listaMisiones[i];
    }
    delete[] listaMisiones;

    cout << "Memoria liberada correctamente. Hasta pronto." << endl;
}

void Controlador::redimensionarRecursos() {
    int nuevaCapacidad = capacidadRecursos * 2;
    Recurso** nuevoArreglo = new Recurso*[nuevaCapacidad];
    for (int i = 0; i < cantidadRecursos; i++) nuevoArreglo[i] = listaRecursos[i];
    delete[] listaRecursos;
    listaRecursos = nuevoArreglo;
    capacidadRecursos = nuevaCapacidad;
}

void Controlador::redimensionarMisiones() {
    int nuevaCapacidad = capacidadMisiones * 2;
    Mision** nuevoArreglo = new Mision*[nuevaCapacidad];
    for (int i = 0; i < cantidadMisiones; i++) nuevoArreglo[i] = listaMisiones[i];
    delete[] listaMisiones;
    listaMisiones = nuevoArreglo;
    capacidadMisiones = nuevaCapacidad;
}

void Controlador::agregarRecurso(Recurso* nuevo) {
    if (cantidadRecursos == capacidadRecursos) redimensionarRecursos();
    listaRecursos[cantidadRecursos] = nuevo;
    cantidadRecursos++;
}

void Controlador::cargarDatosPrueba() {
    // HU05: al menos 2 misiones, 2 ambulancias, 1 helicoptero, 2 medicos, 2 rescatistas
    agregarRecurso(new Ambulancia("Ambulancia Cali 1", "AMB-01", "WWW111", 2));
    agregarRecurso(new Ambulancia("Ambulancia Cali 2", "AMB-02", "WWW222", 2));
    agregarRecurso(new Helicoptero("Halcon 1", "HEL-01", "HK-450", 4));
    agregarRecurso(new Medico("Dra. Laura Gomez", "MED-01", "Trauma"));
    agregarRecurso(new Medico("Dr. Andres Ruiz", "MED-02", "Urgencias"));
    agregarRecurso(new Rescatista("Carlos Perez", "RES-01", "Rescate en alturas"));
    agregarRecurso(new Rescatista("Diana Lopez", "RES-02", "Busqueda y rescate"));

    listaMisiones[cantidadMisiones++] = new Mision("Deslizamiento Ladera Norte", "Cali - Comuna 1");
    listaMisiones[cantidadMisiones++] = new Mision("Inundacion Rio Cauca", "Yumbo");

    // Asignacion de ejemplo para que HU02/HU03 se puedan probar de inmediato
    listaMisiones[0]->asignarRecurso(listaRecursos[0]); // ambulancia
    listaMisiones[0]->asignarRecurso(listaRecursos[3]); // medico
    listaMisiones[1]->asignarRecurso(listaRecursos[2]); // helicoptero
    listaMisiones[1]->asignarRecurso(listaRecursos[5]); // rescatista

    cout << "Datos de prueba cargados: " << cantidadRecursos << " recursos y "
         << cantidadMisiones << " misiones." << endl;
}

void Controlador::mostrarMenu() const {
    cout << "\n===== SISTEMA DE GESTION DE MISIONES DE RESCATE (SGMR) =====" << endl;
    cout << "1. Ver recursos" << endl;
    cout << "2. Registrar recurso" << endl;
    cout << "3. Crear mision" << endl;
    cout << "4. Asignar recurso a mision" << endl;
    cout << "5. Ejecutar mision" << endl;
    cout << "6. Salir" << endl;
    cout << "Seleccione una opcion: ";
}

void Controlador::verRecursos() const {
    cout << "\n--- Recursos registrados (" << cantidadRecursos << ") ---" << endl;
    if (cantidadRecursos == 0) {
        cout << "No hay recursos registrados." << endl;
        return;
    }
    for (int i = 0; i < cantidadRecursos; i++) {
        cout << "[" << i << "] ";
        listaRecursos[i]->mostrarInfo(); // llamada polimorfica
    }

    cout << "\n--- Misiones registradas (" << cantidadMisiones << ") ---" << endl;
    for (int i = 0; i < cantidadMisiones; i++) {
        cout << "[" << i << "] ";
        listaMisiones[i]->mostrarInfo();
    }
}

void Controlador::registrarRecurso() {
    int tipo;
    cout << "\nTipo de recurso a registrar:" << endl;
    cout << "1. Ambulancia\n2. Helicoptero\n3. Medico\n4. Rescatista\nOpcion: ";
    cin >> tipo;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Opcion invalida." << endl;
        return;
    }

    string nombre, codigo;
    cout << "Nombre: ";
    cin.ignore();
    getline(cin, nombre);
    cout << "Codigo/identificador: ";
    getline(cin, codigo);

    if (tipo == 1 || tipo == 2) {
        string placa;
        int capacidad;
        cout << "Placa: ";
        getline(cin, placa);
        cout << "Capacidad: ";
        cin >> capacidad;

        if (tipo == 1) agregarRecurso(new Ambulancia(nombre, codigo, placa, capacidad));
        else agregarRecurso(new Helicoptero(nombre, codigo, placa, capacidad));

    } else if (tipo == 3 || tipo == 4) {
        string especialidad;
        cout << "Especialidad: ";
        getline(cin, especialidad);

        if (tipo == 3) agregarRecurso(new Medico(nombre, codigo, especialidad));
        else agregarRecurso(new Rescatista(nombre, codigo, especialidad));

    } else {
        cout << "Tipo de recurso no valido." << endl;
        return;
    }
    cout << "Recurso registrado exitosamente." << endl;
}

void Controlador::crearMision() {
    string nombre, zona;
    cout << "\nNombre de la mision: ";
    cin.ignore();
    getline(cin, nombre);
    cout << "Zona afectada: ";
    getline(cin, zona);

    if (cantidadMisiones == capacidadMisiones) redimensionarMisiones();
    listaMisiones[cantidadMisiones++] = new Mision(nombre, zona);
    cout << "Mision creada exitosamente." << endl;
}

void Controlador::asignarRecursoAMision() {
    if (cantidadMisiones == 0) { cout << "No hay misiones creadas." << endl; return; }
    if (cantidadRecursos == 0) { cout << "No hay recursos registrados." << endl; return; }

    cout << "\nMisiones disponibles:" << endl;
    for (int i = 0; i < cantidadMisiones; i++) {
        cout << "[" << i << "] " << listaMisiones[i]->getNombre() << endl;
    }
    cout << "Seleccione el indice de la mision: ";
    int idxMision;
    cin >> idxMision;
    if (idxMision < 0 || idxMision >= cantidadMisiones) { cout << "Indice invalido." << endl; return; }

    cout << "\nRecursos disponibles:" << endl;
    for (int i = 0; i < cantidadRecursos; i++) {
        cout << "[" << i << "] " << listaRecursos[i]->getNombre()
             << (listaRecursos[i]->isDisponible() ? " (disponible)" : " (no disponible)") << endl;
    }
    cout << "Seleccione el indice del recurso: ";
    int idxRecurso;
    cin >> idxRecurso;
    if (idxRecurso < 0 || idxRecurso >= cantidadRecursos) { cout << "Indice invalido." << endl; return; }

    // Asignacion polimorfica: la mision recibe un Recurso* sin importar el tipo real (HU02)
    listaMisiones[idxMision]->asignarRecurso(listaRecursos[idxRecurso]);
    cout << "Recurso asignado a la mision correctamente." << endl;
}

void Controlador::ejecutarMisionMenu() {
    if (cantidadMisiones == 0) { cout << "No hay misiones creadas." << endl; return; }

    cout << "\nMisiones disponibles:" << endl;
    for (int i = 0; i < cantidadMisiones; i++) {
        cout << "[" << i << "] " << listaMisiones[i]->getNombre()
             << " (" << listaMisiones[i]->getEstado() << ")" << endl;
    }
    cout << "Seleccione el indice de la mision a ejecutar: ";
    int idx;
    cin >> idx;
    if (idx < 0 || idx >= cantidadMisiones) { cout << "Indice invalido." << endl; return; }

    // La mision recorre sus recursos y cada uno ejecuta su accion de forma polimorfica (HU03)
    listaMisiones[idx]->ejecutarMision();
}

void Controlador::iniciar() {
    int opcion = 0;
    do {
        mostrarMenu();
        cin >> opcion;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada invalida, intente de nuevo." << endl;
            continue;
        }

        switch (opcion) {
            case 1: verRecursos(); break;
            case 2: registrarRecurso(); break;
            case 3: crearMision(); break;
            case 4: asignarRecursoAMision(); break;
            case 5: ejecutarMisionMenu(); break;
            case 6: cout << "Cerrando el sistema..." << endl; break;
            default: cout << "Opcion no valida, intente de nuevo." << endl;
        }
    } while (opcion != 6);
}
