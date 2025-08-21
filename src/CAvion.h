
#ifndef CAVION_H
#define CAVION_H

#include "CPasajero.h";

class CAvion{

    public:

        CAvion(int id, int maxPasajeros);

        /* Getters */
        int getIDAvion(){
            return m_IDAvion;
        }

        int getPasajerosActuales(){
            return m_numPasajeros;
        }

    private:
        int m_IDAvion;
        int m_maxPasajeros;
        // CPasajero *m_pasajeros;
        int m_numPasajeros;
};

#endif