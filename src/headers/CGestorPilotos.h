#ifndef CGESTORPILOTOS_H
#define CGESTORPILOTOS_H

#include "CPiloto.h"

class CGestorPilotos
{
    public:
        //Constructor y destructor
        CGestorPilotos(int maxPilotos);
        ~CGestorPilotos();

        bool crearPiloto(const CCadena& nombre, int dni, int experiencia, int ID);
        bool encontrarPiloto(int id);
        CPiloto buscarporID(int id);

        void mostrarPilotos();

        // CPiloto* -> No sabemos si existe y CPiloto& -> Sabemos que si existe

        /* Getters y Setters*/
        int getPilotos(){ return m_numPilotosActuales; }
        void setPlantilla(int num){ m_numPlantilla = num; }

        // Sobrecarga de operadores para E/S
        friend ostream& operator<<(ostream& out, const CGestorPilotos& gestor);

    private:
        CPiloto* m_piloto;
        int m_numPlantilla;
        int m_numPilotosActuales;
        
};

#endif
