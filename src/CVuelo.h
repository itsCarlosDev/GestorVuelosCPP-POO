#ifndef CVUELO_H
#define CVUELO_H

#include "CCadena.h"

class CVuelo
{
    public:
        // Class constructor
        CVuelo(int ID, int Duracion, int Precio);
        //Default constructor
        CVuelo();
        /*// Class destructor
        ~CVuelo();

        // Puntero necesario para que funcione el destructor
        CVuelo* vuelos;*/

        // Delete all relacionated with the Fly ID
        void eliminarVuelo(int idVuelo); 
        // Modifies 
        // Modifica el vuelo indicado por la ID de vuelo
        /*void modificarVuelo(int idVuelo, CCadena m_Origen, CCadena m_Destino, int m_Duracion, 
                            int m_Precio, CFecha m_FechaSalida, CHora m_HoraSalida);  */
        // Muestra toidos los vuelos actuales guardados
        void vuelosActuales();
        // Ordenar por precio los vuelos y mostrarlos
        void ordenarPorPrecios();
        // Ordenar por Duracion
        void ordenarPorDuracion();
        // buscar vuelo por ID y mostrar por pantalla la informacion del vuelo
        CVuelo buscarVueloPorID(int idVuelo);

        // Getters and Setters
        int getId(){
            return m_IDVuelo;
        }

        int getDuracion(){
            return m_duracion;
        }

        int getPrecio(){
            return m_precio;
        }
    
    private:
        int m_IDVuelo;
        int m_duracion;
        int m_precio;
        //CCadena m_origen;
        //CCadena m_destino;
        //CFecha m_fechaSalida;
        //CHora m_horaSalida;
};

#endif