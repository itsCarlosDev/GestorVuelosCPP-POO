#ifndef CVUELO_H
#define CVUELO_H

#include "CCadena.h"
#include "CAvion.h"
#include "CPiloto.h"

class CVuelo
{
    public:
        
        CVuelo();
        CVuelo(CCadena origen, CCadena destino ,int id, int Duracion, int Precio, int maxPasajeros, CPiloto piloto1, CPiloto piloto2, CAvion avion); // Constructor con parametros

        /* Getter's */
        int getId(){ return m_IDVuelo; }
        int getDuracion(){ return m_duracion; }
        int getPrecio(){ return m_precio; }

        /* Setters */
        void setId(int id){ m_IDVuelo = id; }
        void setDuracion(int duracion){ m_duracion = duracion; }
        void setPrecio(int precio){ m_precio = precio; }

    private:
        CCadena m_origen;
        CCadena m_destino;
        int m_IDVuelo;
        int m_duracion;
        int m_precio;
        //CFecha m_fechaSalida;
        //CHora m_horaSalida;
        CPiloto m_pilotos[2]; // Solo pueden haber 2 pilotos por avion
        int m_numMaxPasajeros;
        CAvion avionAsignado;
        
    friend std::ostream& operator<<(std::ostream&, const CVuelo&);
};

#endif