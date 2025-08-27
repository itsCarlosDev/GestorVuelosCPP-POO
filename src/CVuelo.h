#ifndef CVUELO_H
#define CVUELO_H

#include "CCadena.h"
#include "CAvion.h"
#include "CPiloto.h"

class CVuelo
{
    public:
        
        CVuelo();
        CVuelo(string origen, string destino ,int id, int Duracion, int Precio, int maxPasajeros, CPiloto piloto1, CPiloto piloto2, CAvion avion); // Constructor con parametros
        //~CVuelo(); // Destructor

        /* Getter's */
        int getId(){ return m_IDVuelo; }
        int getDuracion(){ return m_duracion; }
        int getPrecio(){ return m_precio; }

        /* Setters */
        void setId(int id){ m_IDVuelo = id; }
        void setDuracion(int duracion){ m_duracion = duracion; }
        void setPrecio(int precio){ m_precio = precio; }

    private:
        int m_IDVuelo;
        int m_duracion;
        int m_precio;
        
        //CCadena m_origen;
        //CCadena m_destino;
        //CFecha m_fechaSalida;
        //CHora m_horaSalida;

        CPiloto m_pilotos[2]; // Dos pilotos fijos

        CPasajero* pasajeros = nullptr; // Array reservado
        int m_numMaxPasajeros;

        CAvion avionAsignado;

        string m_origen;
        string m_destino;
        
    friend std::ostream& operator<<(std::ostream&, const CVuelo&);
};

#endif