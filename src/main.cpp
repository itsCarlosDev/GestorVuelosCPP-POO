
/**
 * FITXER: main.cpp
 * AUTOR: Carlos Morales
 * DATA: 13/09/2025
 * VERSIO: 6.0
 * Descripció: Mostrar el menu y ejecutar todos los comandos necesarios
 */

#include <fstream> // include para hacer lectura/escritura de archivos
#include <iostream>
#include <thread>   // std::this_thread::sleep_for
#include <chrono>   // std::chrono::seconds, std::chrono::milliseconds
#include <cstdlib>  // std::system
#include <cstdio>   // fileno / _fileno

/*Apartado para limpiar la pantalla en Windows/MacOS */
#ifdef _WIN32
#  include <io.h>      // _isatty
#  include <windows.h> // WinAPI console clear
#else
#  include <unistd.h> // isatty
#endif

#include "./headers/CVuelo.h"
#include "./headers/CGestorVuelos.h"
#include "./headers/CPersona.h"
#include "./headers/CPasajero.h"
#include "./headers/CGestorPilotos.h"
#include "./headers/CGestorAviones.h"

#include "./headers/CVuelo.h"
#include "./headers/CGestorVuelos.h"
#include "./headers/CPersona.h"
#include "./headers/CPasajero.h"
#include "./headers/CGestorPilotos.h"
#include "./headers/CGestorAviones.h"

using namespace std;

/* Se utilizan sobrecargas de operadores porque utilizamos colecciones como CGestorPilotos */

//Sobrecarga del operador de escritura de ficheros (genérico)
ostream& operator<<(ostream& output, const CGestorPilotos& gestor){
    for (int i = 0; i < gestor.m_numPilotosActuales; ++i) {
        output << gestor.m_piloto[i] << '\n';
    }
    return output;
}

//Sobrecarga del operador de lectura para cargar pilotos en el gestor
// Lee: ID Nombre Apellido DNI Experiencia por línea
istream& operator>>(istream& input, CGestorPilotos& gestor) {
    int id, dni, experiencia;
    CCadena nombre, apellido;
    while (input >> id >> nombre >> apellido >> dni >> experiencia) {
        CCadena completo = nombre + CCadena(" ") + apellido;
        gestor.crearPiloto(completo, dni, experiencia, id);
    }
    return input;
}

// Created by AI
// Detecta si stdout es un terminal interactivo (no el Debug Console de VS Code)
inline bool isInteractiveTerminal() {
#ifdef _WIN32
    return _isatty(_fileno(stdout)) != 0;
#else
    return isatty(fileno(stdout)) != 0;
#endif
}

#ifdef _WIN32
// Intenta habilitar secuencias ANSI en Windows (VT processing)
inline void enableVTIfPossible() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut == INVALID_HANDLE_VALUE) return;
    DWORD mode = 0;
    if (!GetConsoleMode(hOut, &mode)) return; // No es consola, probablemente conpty/pipe; igualmente ANSI suele funcionar
    mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, mode);
}
#endif

void esperar(int segundos) {
    std::this_thread::sleep_for(std::chrono::seconds(segundos));
}

void animacionPuntos(const std::string& prefix, int ciclos = 9, int delay_ms = 200) {
<<<<<<< HEAD
    // En entornos no interactivos (Debug Console), muestra una sola vez
    if (!isInteractiveTerminal()) {
        std::cout << prefix << "..." << std::endl;
        return;
    }
#ifdef _WIN32
    enableVTIfPossible();
#endif
    static const char* estados[] = {".", "..", "..."};
    for (int i = 0; i < ciclos; ++i) {
        std::cout << "\r" << prefix << estados[i % 3]
#ifdef _WIN32
                  << "\x1b[K"
#else
                  << "\x1b[K"
#endif
                  << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(delay_ms));
    }
    // Deja la línea final y salta de línea para no solapar
    std::cout << "\r" << prefix << "...\x1b[K" << std::endl;
}

// Limpieza de consola portable (Windows/macOS/Linux)
inline void clearScreen() {
#ifdef _WIN32
    if (!isInteractiveTerminal()) {
        // En Debug Console no se puede limpiar: separa con saltos
        std::cout << "\n\n\n" << std::flush;
        return;
    }
    // Intento 1: WinAPI
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (hOut != INVALID_HANDLE_VALUE && GetConsoleScreenBufferInfo(hOut, &csbi)) {
        DWORD cellCount = static_cast<DWORD>(csbi.dwSize.X) * static_cast<DWORD>(csbi.dwSize.Y);
        DWORD count;
        COORD homeCoords = {0, 0};
        FillConsoleOutputCharacter(hOut, (TCHAR)' ', cellCount, homeCoords, &count);
        FillConsoleOutputAttribute(hOut, csbi.wAttributes, cellCount, homeCoords, &count);
        SetConsoleCursorPosition(hOut, homeCoords);
        return;
    }
    // Intento 2: ANSI (VT) para consolas tipo conpty
    enableVTIfPossible();
    std::cout << "\x1b[2J\x1b[H\x1b[3J" << std::flush;
#else
    if (!isInteractiveTerminal()) {
        std::cout << "\n\n\n" << std::flush;
        return;
    }
    // Intenta usar el binario 'clear' (respeta terminfo). Si falla, usa ANSI.
    int rc = std::system("clear");
    if (rc != 0) {
        std::cout << "\x1b[H\x1b[2J\x1b[3J" << std::flush; // home + clear + clear scrollback
    }
#endif
=======
    static const char* estados[] = {".", "..", "..."};
    for (int i = 0; i < ciclos; ++i) {
        std::cout << "\r" << prefix << estados[i % 3] << "   " << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(delay_ms));
    }
    // Limpia/restaura la línea al final
    std::cout << "\r" << prefix << "...   " << std::endl;
>>>>>>> 7fe59fd07166bef4c32246d88d85878eef614e6c
}

////////////////

/**
 * calculaMitja
 * Calcula la mitjana de dos nombres reals.
 * @param x primer nombre
 * @param y segon nombre
 * @return mitjana dels dos
 */
void mostrarMenu() {
<<<<<<< HEAD
    clearScreen();
=======
    std::cout << "\x1b[2J\x1b[H" << std::flush; // Created by AI
>>>>>>> 7fe59fd07166bef4c32246d88d85878eef614e6c
    cout << "\n=== GESTOR DE VUELOS ===\n";
    cout << "\n. Añadir vuelo\n";
    cout << "2. Eliminar vuelo\n";
    cout << "3. Modificar vuelo por ID\n";
    cout << "4. Mostrar vuelos actuales\n";
    cout << "5. Ordenar por id\n";
    cout << "6. Ordenar por precio\n";
    cout << "7. Ordenar por duracion\n";

    cout << "\n=== GESTOR DE PILOTOS ===\n";
    cout << "\n8. Actualizar Pilotos\n";
    cout << "9. Mostrar Pilotos\n";

    cout << "\n=== GESTOR DE CLIENTES ===\n";
    cout << "\n8. Añadir Pasajero\n";
    cout << "9. Eliminar pasajero\n";
    cout << "10. Modificar pasajero por DNI\n";

    cout << "\n=== GESTOR DE AVIONES ===\n";
    cout << "\n12. Añadir Avion\n";
    cout << "13. Mostrar Aviones\n";

    cout << "\n0. Salir\n";
    cout << "\nSelecciona una opción: ";
}

int main(int argc, char const *argv[])
{
    int opcion, plantillaPilotos, avionesTotales; // Menu selection 
    CGestorVuelos gestor;
    CPasajero pasajero;
<<<<<<< HEAD
    clearScreen();
=======
    std::cout << "\x1b[2J\x1b[H" << std::flush; // Created by AI
>>>>>>> 7fe59fd07166bef4c32246d88d85878eef614e6c
    animacionPuntos("Contando pilotos actuales");
    
    /*Contar la cantidad de pilotos dentro del archivo*/
    ifstream fitxer("src/files/pilotos.txt");
    string linea;
    int contador = 0;
    if (fitxer) {
        while (getline(fitxer, linea)) {   // lee cada línea completa
            contador++;
        }
        fitxer.close();
    } else {
        cout << "No se ha encontrado el archivo. ";
    }
<<<<<<< HEAD
    clearScreen();
    cout << "Se han encontrado un total de: " << contador;
    esperar(2);
    clearScreen();
=======
    std::cout << "\x1b[2J\x1b[H" << std::flush; // Created by AI
    cout << "Se han encontrado un total de: " << contador;
    esperar(2);
    std::cout << "\x1b[2J\x1b[H" << std::flush; // Created by AI
>>>>>>> 7fe59fd07166bef4c32246d88d85878eef614e6c

    /*Necesita el constructor el numero de 
    pilotos para crear el array reservado*/
    CGestorPilotos pilotos(contador);
    cout << "Introduce el numero de aviones que caben en el aeropuerto: ";
    cin >> avionesTotales;
    CGestorAviones aviones(avionesTotales);

    do {
        mostrarMenu();
        cin >> opcion;

        // The keys {} are to close each case for the variation independence.
        switch (opcion) {
            /*Apartado de Vuelos*/
            case 1: {

                if(pilotos.getPilotos() >= 2){

                    int id, dur, prec;
                    CCadena origen, destino;
                    int idAvion, idPiloto1, idPiloto2, maxPasajeros;
                    bool encontradoUno = false;
                    CPiloto piloto1;
                    bool encontradoDos = false;
                    CPiloto piloto2;
                    bool encontradoTres = false;
                    CAvion avion;

                    cout << "\n-> Has seleccionado Añadir vuelo\n";

                    cout << "\nIntroduce el ID del vuelo: ";
                    cin >> id;

                    cout << "Coloca el origen del vuelo: ";
                    cin >> origen;

                    cout << "Coloca el destino del vuelo: ";
                    cin >> destino;

                    cout << "Introduce la duración (minutos): ";
                    cin >> dur;

                    cout << "Introduce el precio: ";
                    cin >> prec;

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

                    do
                    {
                        cout << "Indica el ID del avion: ";
                        cin >> idAvion;
                        if(aviones.encontrarAvion(idAvion)){
                            cout << "¡Avion encontrado! \n";
                            avion = aviones.buscarporID(idAvion);
                            encontradoTres = true;
                        } else {
                            cout << "No se ha encontrado el avion. \n";
                            encontradoTres = false;
                        }
                    } while (encontradoTres == false);

                    CVuelo vuelo(origen, destino, id, dur, prec, maxPasajeros, 
                                piloto1, piloto2, avion);

                    if(gestor.crearVuelo(vuelo))
                    { 
                        cout << "Creado correctamente.\n"; 
                        esperar(2); 
                    } else { 
                        cout << "Se ha alcanzado el maximo de vuelos posible.\n"; 
                        esperar(2);
                    };
                
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

                    CCadena origen, destino;
                    cout << "Coloca el origen del vuelo: ";
                    cin >> origen;
                    cout << "Coloca el destino del vuelo: ";
                    cin >> destino;

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

                    cout << "Indica el ID del avion asignado: ";
                    cin >> idAvion;

                    bool encontradoTres = false;
                    CAvion avion;

                    do
                    {
                        cout << "Indica el ID del avion: ";
                        cin >> idAvion;
                        if(aviones.encontrarAvion(idAvion)){
                            cout << "¡Avion encontrado! \n";
                            avion = aviones.buscarporID(idAvion);
                            encontradoTres = true;
                        } else {
                            cout << "No se ha encontrado el avion. \n";
                            encontradoTres = false;
                        }
                    } while (encontradoTres == false);

                    CVuelo vuelo(origen, destino, id, dur, prec, maxPasajeros, piloto1, piloto2, avion);

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
            /*Apartado de Pilotos*/
            case 8: {
<<<<<<< HEAD
                clearScreen();
=======
                std::cout << "\x1b[2J\x1b[H" << std::flush; // Created by AI
>>>>>>> 7fe59fd07166bef4c32246d88d85878eef614e6c
                cout << "\n-> Has seleccionado actualizar pilotos\n";
                cout << "\n-> Pilotos de la lista: \n";

                ifstream fitxer("src/files/pilotos.txt"); // lectura

                string linea;
                int contador = 0;
                if (fitxer) {
                    while (getline(fitxer, linea)) {   // lee cada línea completa
                        cout << linea;
                        cout << "\n";
                    }
                    fitxer.close(); 
                } else {
                    cout << "No se ha encontrado el archivo. ";
                }

                esperar(2);

                fitxer.open("src/files/pilotos.txt");
                animacionPuntos("Actualizando array reservado");

                if (fitxer) {
                    fitxer >> pilotos; // usa la sobrecarga operator>>(istream&, CGestorPilotos&)
                    fitxer.close();
                    cout << "Pilotos actualizados.\n";
                } else {
                    cout << "No se ha encontrado el archivo. ";
                }
                esperar(2);
                break;
            }
            case 9: {
                cout << "\n-> Has seleccionado mostrar Pilotos en mémoria\n";
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
                cout << "\n-> Has seleccionado crear Avion\n";

                int maxPasajeros, id;

                cout << "Indica el ID del avion: ";
                cin >> id;

                cout << "Indica el maximo de pasajeros: ";
                cin >> maxPasajeros;

                CAvion avion(id, maxPasajeros);
                
                esperar(2);
                break;
            }
            case 13: {
                cout << "\n-> Has seleccionado mostrar Aviones\n";
                aviones.mostrarAviones();
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
