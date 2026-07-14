# Sistema de Gestión de Misiones de Rescate (SGMR)
Parcial 2 — Fundamentos de Programación Orientada a Objetos — Grupo 80

## Descripción
Motor lógico en C++ para registrar personal y vehículos de rescate, crear misiones
de emergencia y asignarles recursos heterogéneos de forma polimórfica, todo a
través de un menú de consola gestionado por una clase `Controlador`.

## Compilar y ejecutar
```bash
g++ -std=c++17 -Wall -o sgmr *.cpp
./sgmr
```

## Estructura de clases

- **Recurso** (abstracta): clase base de todo lo registrable. Define `ejecutarAccion()`
  como método virtual puro.
  - **Vehiculo** (abstracta): agrega `placa` y `capacidad`.
    - **Ambulancia**: `ejecutarAccion()` → "Transportando paciente vía terrestre".
    - **Helicoptero**: `ejecutarAccion()` → "Realizando extracción aérea".
  - **Personal** (abstracta): agrega `especialidad`.
    - **Medico**: `ejecutarAccion()` → "Estabilizando signos vitales".
    - **Rescatista**: `ejecutarAccion()` → "Buscando sobrevivientes en escombros".
- **Mision**: guarda un arreglo dinámico de punteros `Recurso**` (no es dueña de
  los objetos, solo los referencia) y ejecuta la acción de cada uno con
  polimorfismo (`ejecutarMision()`).
- **Controlador**: única clase instanciada por `main.cpp`. Es la dueña real de
  todos los objetos (`Recurso**` y `Mision**`), los crea con `new`, los libera
  con `delete`/`delete[]` en su destructor, y gestiona el menú interactivo.

## Cumplimiento de requerimientos técnicos (HT01–HT03)
- Cero `std::vector` u otras colecciones de alto nivel: solo arreglos de
  punteros dinámicos (`Recurso** listaRecursos`, `Mision** listaMisiones`,
  `Recurso** recursosAsignados`) redimensionados manualmente (`new` + copia +
  `delete[]` del arreglo viejo).
- Todo objeto complejo se crea en el Heap con `new` y se libera explícitamente
  con `delete`/`delete[]` (`Controlador::~Controlador()`, `Mision::~Mision()`).
- Todo paso de objetos entre métodos se hace por referencia o puntero
  (`Recurso*`, `Mision&` no aplica porque se usan punteros en todo el flujo).
- Datos de prueba pre-cargados en `Controlador::cargarDatosPrueba()`: 2
  misiones, 2 ambulancias, 1 helicóptero, 2 médicos, 2 rescatistas.

## Qué falta que hagas tú (trabajo en pareja)
1. Crear un repositorio en GitHub (público o con acceso al profesor).
2. Subir estos archivos y hacer **varios commits** (no uno solo) que
   evidencien el trabajo de los dos integrantes — idealmente cada uno
   commiteando desde su propia cuenta/rama.
3. Reemplazar los nombres/códigos de ejemplo en este README y en el PDF de
   entrega por los reales de ambos integrantes.
4. Subir la imagen `diagrama_clases_SGMR.png` (o el `.svg`) al repositorio y
   referenciarla en el PDF de entrega.

## Checklist del PDF de entrega (el documento único que sube 1 integrante)
- [ ] Nombres completos y códigos de los dos integrantes.
- [ ] Enlace al repositorio de GitHub con el código modularizado (.h/.cpp) y
      el historial de commits visible.
- [ ] Enlace o imagen del diagrama de clases (`diagrama_clases_SGMR.png`).

## Archivos del proyecto
```
Recurso.h / Recurso.cpp
Vehiculo.h / Vehiculo.cpp
Ambulancia.h / Ambulancia.cpp
Helicoptero.h / Helicoptero.cpp
Personal.h / Personal.cpp
Medico.h / Medico.cpp
Rescatista.h / Rescatista.cpp
Mision.h / Mision.cpp
Controlador.h / Controlador.cpp
main.cpp
```
