
#include "CVuelo.h"
#include <iostream>

using namespace std;

// ============================
// TODO LIST - GESTOR DE VUELOS
// ============================

// ✈️ Gestión de vuelos
// TODO: Implementar función para eliminar un vuelo (eliminarVuelo)
// TODO: Implementar función para modificar un vuelo (modificarVuelo)
// TODO: Implementar función para mostrar todos los vuelos actuales (vuelosActuales)

// 📊 Ordenación y búsqueda
// TODO: Implementar ordenación de vuelos por precio (ordenarPorPrecio)
// TODO: Implementar ordenación de vuelos por duración (ordenarPorDuracion)
// TODO: Implementar búsqueda de vuelo por ID (buscarVueloPorID)

// 🌍 Rutas y conexiones
// TODO: Implementar búsqueda de ruta entre origen y destino (buscarRuta)
// TODO: Implementar visualización de todas las rutas (mostrarRutas)
// TODO: Implementar algoritmo DFS para recorridos de rutas (DFS)

// 👨‍✈️ Gestión de pilotos
// TODO: Implementar visualización de experiencia del piloto (getExperiencia)
// TODO: Implementar visualización de cantidad de vuelos del piloto (getVuelos)
// TODO: Implementar asignación de piloto a avión

// 🧍 Gestión de pasajeros y acompañantes
// TODO: Implementar inserción de pasajero (CPasajero)
// TODO: Implementar gestión de clase del pasajero (Business/Normal)
// TODO: Implementar asignación de acompañantes al pasajero (m_Acompanantes)

// 🧾 Gestión de personas
// TODO: Implementar obtención de nombre de persona (getNombre)
// TODO: Implementar obtención de teléfono de persona (getTelefono)
// TODO: Implementar obtención de DNI de persona (getDNI)

// 🛫 Gestión de aviones
// TODO: Implementar visualización de datos de avión (capacidad, velocidad, ID)
// TODO: Implementar asignación de avión a piloto

// 🔧 Utilidades generales
// TODO: Implementar estructura de menú en consola (main menu + submenús)
// TODO: Validar entradas de usuario (fechas, ID, clase, etc.)
// TODO: Integrar estructura de lista genérica (CLista<T>)
// TODO: Implementar sistema de mensajes de error y validación

void mostrarMenu() {
    cout << "\n=== GESTOR DE VUELOS ===\n";
    cout << "1. Añadir vuelo\n";
    cout << "2. Eliminar vuelo\n";
    cout << "3. Buscar vuelo por ID\n";
    cout << "4. Mostrar vuelos actuales\n";
    cout << "5. Ordenar por precio\n";
    cout << "6. Ordenar por duración\n";
    cout << "7. Buscar ruta entre ciudades\n";
    cout << "0. Salir\n";
    cout << "\nSelecciona una opción: ";
}

int main(int argc, char const *argv[])
{
    int opcion; // Menu selection 
    CVuelo vuelo[10]; // Array, only can be 10 fly's

    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "\n[Añadir vuelo]\n";
                int id, dur, prec;
                cout << "\nIntroduce el ID del vuelo: ";
                cin >> id;
                cout << "Introduce la duración (minutos): ";
                cin >> dur;
                cout << "Introduce el precio: ";
                cin >> prec;
                vuelo[0].crearVuelo(id, dur, prec); 
                break;
            case 2:
                cout << "[Eliminar vuelo] - Administrador\n";
                // TODO: Eliminar vuelo
                break;
            case 3:
                cout << "[Buscar vuelo por ID]\n";
                // TODO: Buscar vuelo
                break;
            case 4:
                cout << "[Mostrar vuelos actuales]\n";
                // TODO: Mostrar vuelos
                break;
            case 5:
                cout << "[Ordenar por precio]\n";
                // TODO: Ordenar por precio
                break;
            case 6:
                cout << "[Ordenar por duración]\n";
                // TODO: Ordenar por duración
                break;
            case 7:
                cout << "[Buscar ruta entre ciudades]\n";
                // TODO: Buscar ruta
                break;
            case 0:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opción inválida. Inténtalo de nuevo.\n";
        }

    } while (opcion != 0);

    return 0;
}
