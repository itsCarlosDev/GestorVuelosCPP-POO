
#include "CVuelo.h"
#include "CGestorVuelos.h"
#include <iostream>
#include <thread>   // std::this_thread::sleep_for
#include <chrono>   // std::chrono::seconds, std::chrono::milliseconds
#include <cstdlib>   // system

using namespace std;

// ============================
// TODO LIST - GESTOR DE VUELOS
// ============================

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

// Created by AI (ChatGPT)
void esperar(int segundos) {
    std::this_thread::sleep_for(std::chrono::seconds(segundos));
}

void mostrarMenu() {
    cout << "\n=== GESTOR DE VUELOS ===\n";
    cout << "\n1. Añadir vuelo\n";
    cout << "2. Eliminar vuelo\n";
    cout << "3. Modificar vuelo por ID\n";
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
    CGestorVuelos gestor;

    do {
        mostrarMenu();
        cin >> opcion;

        // The keys {} are to close each case for the variation independence.
        switch (opcion) {
            case 1: {
                cout << "\n-> Has seleccionado Añadir vuelo\n";
                int id, dur, prec;
                cout << "\nIntroduce el ID del vuelo: ";
                cin >> id;
                cout << "Introduce la duración (minutos): ";
                cin >> dur;
                cout << "Introduce el precio: ";
                cin >> prec;

                CVuelo vuelo(id, dur, prec);
                if(gestor.crearVuelo(vuelo)){ cout << "Creado correctamente.\n"; esperar(2); } else{ cout << "Se ha alcanzado el maximo de vuelos posible.\n"; esperar(2);};
                
                break;
            }
            case 2: {
                int id;

                if(gestor.getnumVuelos() != 0){
                    cout << "\n-> Has seleccionado Eliminar vuelo\n";
                    cout << "Introduce el ID del vuelo a eliminar: ";
                    cin >> id;

                    if(gestor.eliminarVuelo(id)){ cout << "Eliminado correctamente.\n"; esperar(2); } else{ cout << "No hay vuelos a eliminar. \n"; esperar(2);};
                } else {
                    cout << "No hay vuelos a eliminar. ";
                }
                break;
            }
            case 3: {
                int id, dur, prec;

                cout << "\n-> Has seleccionado modificar vuelo\n";

                if(gestor.getnumVuelos() != 0){
                    cout << "Introduce el ID del vuelo a modificar: ";
                    cin >> id;

                    cout << "Introduce la duración (minutos): ";
                    cin >> dur;
                    cout << "Introduce el precio: ";
                    cin >> prec;

                    CVuelo vuelo(id, dur, prec);

                    if(gestor.modificarVuelos(id, vuelo)){ cout << "Vuelo modificado.\n"; esperar(2); } else{ cout << "No hay vuelos a modificar. \n"; esperar(2);};
                } else {
                    cout << "No hay vuelos a modificar. ";
                }    
                break;
            }
            case 4: {
                cout << "\n-> Has seleccionado Mostrar vuelos\n";
                gestor.mostrarVuelos();
                esperar(3);
                break;
            }
            case 5: {
                cout << "[Ordenar por precio]\n";
                // TODO: Ordenar por precio
                break;
            }
            case 6: {
                cout << "[Ordenar por duración]\n";
                // TODO: Ordenar por duración
                break;
            }
            case 7: {
                cout << "[Buscar ruta entre ciudades]\n";
                // TODO: Buscar ruta
                break;
            }
            case 0: {
                cout << "Saliendo del programa...\n";
                break;
            }
            default: {
                cout << "Opción inválida. Inténtalo de nuevo.\n";
            }
        }

    } while (opcion != 0);

    return 0;
}
