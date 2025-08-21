
#include "CVuelo.h"
#include "CGestorVuelos.h"
#include "CPersona.h"
#include "CPasajero.h"
#include "CGestorPilotos.h"
#include <iostream>
#include <thread>   // std::this_thread::sleep_for
#include <chrono>   // std::chrono::seconds, std::chrono::milliseconds

using namespace std;

// Created by AI (ChatGPT)
void esperar(int segundos) {
    std::this_thread::sleep_for(std::chrono::seconds(segundos));
}

void mostrarMenu() {
    // Los vuelos actualmente funcionan con un array estatico
    cout << "\n=== GESTOR DE VUELOS ===\n";
    cout << "\n1. Añadir vuelo\n";
    cout << "2. Eliminar vuelo\n";
    cout << "3. Modificar vuelo por ID\n";
    cout << "4. Mostrar vuelos actuales\n";
    cout << "5. Ordenar por id\n";
    cout << "6. Ordenar por precio\n";
    cout << "7. Ordenar por duracion\n";

    // Los pilotos funcionan con un array reservado
    cout << "\n=== GESTOR DE PILOTOS ===\n";
    cout << "\n8. Añadir Piloto\n";
    cout << "9. Mostrar Pilotos\n";
    cout << "10. Eliminar piloto\n";
    cout << "11. Modificar piloto por DNI\n";

    /*cout << "\n=== GESTOR DE CLIENTES ===\n";
    cout << "\n8. Añadir Pasajero\n";
    cout << "9. Eliminar pasajero\n";
    cout << "10. Modificar pasajero por DNI\n";

    cout << "\n=== GESTOR DE AVIONES ===\n";
    cout << "\n14. Añadir Avion\n";
    cout << "15. Eliminar piloto\n";
    cout << "16. Modificar piloto por DNI\n";*/

    cout << "0. Salir\n";
    cout << "\nSelecciona una opción: ";
}

int main(int argc, char const *argv[])
{
    int opcion, plantillaPilotos; // Menu selection 
    CGestorVuelos gestor;
    CPasajero pasajero;

    /* Apartado nuevo para declarar el array reservado de pilotos en plantilla */
    cout << "Introduce el numero de plantilla de Pilotos del Aeropuerto: ";
    cin >> plantillaPilotos;
    CGestorPilotos pilotos(plantillaPilotos);

    do {
        mostrarMenu();
        cin >> opcion;

        // The keys {} are to close each case for the variation independence.
        switch (opcion) {
            case 1: {

                if(pilotos.getPilotos() >= 2){
                    cout << "\n-> Has seleccionado Añadir vuelo\n";
                    
                    /* Entrada de datos sobre el vuelo. */
                    int id, dur, prec;
                    cout << "\nIntroduce el ID del vuelo: ";
                    cin >> id;
                    cout << "Introduce la duración (minutos): ";
                    cin >> dur;
                    cout << "Introduce el precio: ";
                    cin >> prec;

                    int idAvion, idPiloto1, idPiloto2, maxPasajeros;
                    /*cout << "Indica el ID del avion asignado: ";
                    cin >> idAvion;
                    cout << "Indica el maximo de pasajeros: ";
                    cin >> maxPasajeros;*/

                    /* Asignacion de pilotos al vuelo */
                    bool encontradoUno = false;
                    CPiloto piloto1;

                    do
                    {
                        cout << "Indica el ID del 1º piloto: ";
                        cin >> idPiloto1;
                        if(pilotos.encontrarPiloto(idPiloto1)){
                            cout << "¡Piloto encontrado! \n";
                            piloto1 = pilotos.buscarporID(idPiloto1);
                            encontradoUno = true;
                        } else {
                            cout << "No se ha encontrado al piloto.\n";
                            encontradoUno = false;
                        }
                    } while (encontradoUno == false);

                    bool encontradoDos = false;
                    CPiloto piloto2;

                    do
                    {
                        cout << "Indica el ID del 2º piloto: ";
                        cin >> idPiloto2;
                        if(pilotos.encontrarPiloto(idPiloto2)){
                            cout << "¡Piloto encontrado! \n";
                            piloto2 = pilotos.buscarporID(idPiloto2);
                            encontradoDos = true;
                        } else {
                            cout << "No se ha encontrado al piloto. \n";
                            encontradoDos = false;
                        }
                    } while (encontradoDos == false);

                    CVuelo vuelo(id, dur, prec, maxPasajeros, piloto1, piloto2);

                    /* Creacion del vuelo */
                    if(gestor.crearVuelo(vuelo)){ cout << "Creado correctamente.\n"; esperar(2); } else{ cout << "Se ha alcanzado el maximo de vuelos posible.\n"; esperar(2);};
                
                } else {
                    cout << "Para la creacion de vuelos es necesario haber creado antes 2 pilotos minimo.\n";
                }
                
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

                    int idAvion, idPiloto1, idPiloto2, maxPasajeros;
                    cout << "Indica el ID del 1º Piloto: ";
                    cin >> idPiloto1;

                    bool encontradoUno = false;
                    CPiloto piloto1;

                    do
                    {
                        cout << "Indica el ID del 1º piloto: ";
                        cin >> idPiloto1;
                        if(pilotos.encontrarPiloto(idPiloto1)){
                            piloto1 = pilotos.buscarporID(idPiloto1);
                            encontradoUno == true;
                        } else {
                            cout << "No se ha encontrado al piloto: ";
                            encontradoUno = false;
                        }
                    } while (encontradoUno == false);
                    
                    cout << "Indica el ID del 2º Piloto: ";
                    cin >> idPiloto2;

                    bool encontradoDos = false;
                    CPiloto piloto2;

                    do
                    {
                        cout << "Indica el ID del 2º piloto: ";
                        cin >> idPiloto2;
                        if(pilotos.encontrarPiloto(idPiloto2)){
                            piloto2 = pilotos.buscarporID(idPiloto2);
                            encontradoDos == true;
                        } else {
                            cout << "No se ha encontrado al piloto: ";
                            encontradoDos = false;
                        }
                    } while (encontradoDos == false);

                    CVuelo vuelo(id, dur, prec, maxPasajeros, piloto1, piloto2);

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
                if(gestor.ordenar(&CVuelo::getId)){ cout << "Vuelos organizados por ID.\n"; esperar(2); } else{ cout << "No hay vuelos a organizar/Solo hay un vuelo \n"; esperar(2);};
                gestor.mostrarVuelos();
                esperar(2);
                break;
            }
            case 6: {
                cout << "\n-> Has seleccionado ordenar vuelos por precio\n";
                if(gestor.ordenar(&CVuelo::getPrecio)){ cout << "Vuelos organizados por Precio.\n"; esperar(2); } else{ cout << "No hay vuelos a organizar/Solo hay un vuelo \n"; esperar(2);};
                gestor.mostrarVuelos();
                esperar(2);
                break;
            }
            case 7: {
                cout << "\n-> Has seleccionado Añadir a Cliente\n";
                CCadena nombre;
                int dni;
                cout << "\nIntroduce el nombre del Cliente: ";
                cin >> nombre;
                cout << "Introduce el DNI: ";
                cin >> dni;

                CPersona persona;
                //if(gestor.crearVuelo(vuelo)){ cout << "Creado correctamente.\n"; esperar(2); } else{ cout << "Se ha alcanzado el maximo de vuelos posible.\n"; esperar(2);};

                break;
            }
            case 8: {
                cout << "\n-> Has seleccionado añadir pilotos\n";

                CCadena nombre;
                int DNI, experiencia, id;

                cout << "Indica la ID del piloto: ";
                cin >> id;
                cout << "Nombre del empleado: ";
                cin >> nombre;
                cout << "DNI del empleado: ";
                cin >> DNI;
                cout << "Indica la experiencia del piloto (no coloques años al final): ";
                cin >> experiencia;
                
                if((pilotos.crearPiloto(nombre, DNI, experiencia, id))){ cout << "Se ha creado el piloto correctamente.\n"; esperar(2); } else{ cout << "No se pueden crear mas pilotos \n"; esperar(2);};
                esperar(2);
                break;
            }
            case 9: {
                cout << "\n-> Has seleccionado mostrar Pilotos\n";
                pilotos.mostrarPilotos();
                esperar(2);
                break;
            }
            case 10: {
                cout << "\n-> Has seleccionado modificar informacion de los pilotos. \n";
                if(gestor.ordenar(&CVuelo::getDuracion)){ cout << "Vuelos organizados por Duracion.\n"; esperar(2); } else{ cout << "No hay vuelos a organizar/Solo hay un vuelo \n"; esperar(2);};
                gestor.mostrarVuelos();
                esperar(2);
                break;
            }
            case 11: {
                cout << "\n-> Has seleccionado eliminar informacion de los pilotos. \n";
                int id;
                if(gestor.getnumVuelos() != 0){
                    cout << "\n-> Has seleccionado Eliminar vuelo\n";
                    cout << "Introduce el ID del vuelo a eliminar: ";
                    cin >> id;

                    if(gestor.eliminarVuelo(id)){ cout << "Eliminado correctamente.\n"; esperar(2); } else{ cout << "No hay vuelos a eliminar. \n"; esperar(2);};
                } else {
                    cout << "No hay vuelos a eliminar. ";
                }
                esperar(2);
                break;
            }
            case 12: {
                cout << "\n-> Has seleccionado ordenar vuelos por duracion\n";
                if(gestor.ordenar(&CVuelo::getDuracion)){ cout << "Vuelos organizados por Duracion.\n"; esperar(2); } else{ cout << "No hay vuelos a organizar/Solo hay un vuelo \n"; esperar(2);};
                gestor.mostrarVuelos();
                esperar(2);
                break;
            }
            case 13: {
                cout << "\n-> Has seleccionado ordenar vuelos por duracion\n";
                if(gestor.ordenar(&CVuelo::getDuracion)){ cout << "Vuelos organizados por Duracion.\n"; esperar(2); } else{ cout << "No hay vuelos a organizar/Solo hay un vuelo \n"; esperar(2);};
                gestor.mostrarVuelos();
                esperar(2);
                break;
            }
            case 14: {
                cout << "\n-> Has seleccionado ordenar vuelos por duracion\n";
                if(gestor.ordenar(&CVuelo::getDuracion)){ cout << "Vuelos organizados por Duracion.\n"; esperar(2); } else{ cout << "No hay vuelos a organizar/Solo hay un vuelo \n"; esperar(2);};
                gestor.mostrarVuelos();
                esperar(2);
                break;
            }
            case 15: {
                cout << "\n-> Has seleccionado ordenar vuelos por duracion\n";
                if(gestor.ordenar(&CVuelo::getDuracion)){ cout << "Vuelos organizados por Duracion.\n"; esperar(2); } else{ cout << "No hay vuelos a organizar/Solo hay un vuelo \n"; esperar(2);};
                gestor.mostrarVuelos();
                esperar(2);
                break;
            }
            case 16: {
                cout << "\n-> Has seleccionado ordenar vuelos por duracion\n";
                if(gestor.ordenar(&CVuelo::getDuracion)){ cout << "Vuelos organizados por Duracion.\n"; esperar(2); } else{ cout << "No hay vuelos a organizar/Solo hay un vuelo \n"; esperar(2);};
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
