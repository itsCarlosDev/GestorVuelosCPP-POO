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

        /* Setters */
        int setId(int id){
            m_IDVuelo = id;
        }
        int setDuracion(int duracion){
            m_duracion = duracion;
        }
        int setPrecio(int precio){
            m_precio = precio;
        }

    private:
        int m_IDVuelo;
        int m_duracion;
        int m_precio;
        //CCadena m_origen;
        //CCadena m_destino;
        //CFecha m_fechaSalida;
        //CHora m_horaSalida;

        
    friend std::ostream& operator<<(std::ostream&, const CVuelo&);
};

#endif