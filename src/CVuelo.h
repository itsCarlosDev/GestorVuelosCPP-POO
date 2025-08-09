#ifndef CVUELO_H
#define CVUELO_H

#include "CCadena.h"

    class CVuelo
    {
        public:
            
            CVuelo(int ID, int Duracion, int Precio); // Constructor with parameters
            CVuelo(); // Default constructor

            void crearVuelo(int idVuelo, int duracion, int precio);

            /* Getter's */
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