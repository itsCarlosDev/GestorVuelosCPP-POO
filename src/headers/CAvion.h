
#ifndef CAVION_H
#define CAVION_H

#include "CPasajero.h"
#include "CPersona.h"

class CAvion{

    public:

        // Constructor por defecto
        CAvion() : m_IDAvion(0), m_maxPasajeros(0), m_pasajeros(nullptr), m_numPasajeros(0) {}

        CAvion(int id, int maxPasajeros);
        ~CAvion();
        void crearPasajero(CPasajero persona);

        /* Getters */
        int getIDAvion() const { return m_IDAvion; }
        int getPasajerosActuales(){ return m_numPasajeros; }

        /* Setters */
        void setIDAvion(int id) { m_IDAvion = id; }
        void setMaxPasajeros(int max) { m_maxPasajeros = max; }

        //CAvion& operator=(const CAvion& copia);
        friend ostream& operator<<(std::ostream& out, const CAvion& avion);

    private: 
        int m_IDAvion;
        int m_maxPasajeros;

        CPasajero *m_pasajeros = nullptr;
        int m_numPasajeros;
};

#endif