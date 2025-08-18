
#include "CVuelo.h"
#include "CGestorVuelos.h"
#include <iostream>
#include <thread>   // std::this_thread::sleep_for
#include <chrono>   // std::chrono::seconds, std::chrono::milliseconds
#include <cstdlib>   // system

using namespace std;

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
    cout << "5. Ordenar por id\n";
    cout << "6. Ordenar por precio\n";
    cout << "7. Ordenar por duracion\n";
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
                cout << "\n-> Has seleccionado ordenar vuelos por ID\n";
                if(gestor.ordenarPorID()){ cout << "Vuelos organizados por ID.\n"; esperar(2); } else{ cout << "No hay vuelos a organizar/Solo hay un vuelo \n"; esperar(2);};
                gestor.mostrarVuelos();
                esperar(2);
                break;
            }
            case 6: {
                cout << "\n-> Has seleccionado ordenar vuelos por precio\n";
                if(gestor.ordenarPorPrecio()){ cout << "Vuelos organizados por Precio.\n"; esperar(2); } else{ cout << "No hay vuelos a organizar/Solo hay un vuelo \n"; esperar(2);};
                gestor.mostrarVuelos();
                esperar(2);
                break;
            }
            case 7: {
                cout << "\n-> Has seleccionado ordenar vuelos por duracion\n";
                if(gestor.ordenarPorDuracion()){ cout << "Vuelos organizados por Duracion.\n"; esperar(2); } else{ cout << "No hay vuelos a organizar/Solo hay un vuelo \n"; esperar(2);};
                gestor.mostrarVuelos();
                esperar(2);
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
