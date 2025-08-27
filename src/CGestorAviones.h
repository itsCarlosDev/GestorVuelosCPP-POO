
#ifndef CGESTORAVIONES_H
#define CGESTORAVIONES_H

#include "CAvion.h"

class CGestorAviones
{
    public:
        CGestorAviones(int maxAviones);
        ~CGestorAviones();

        bool crearAvion(int id, int maxPasajeros);
        void mostrarAviones();

        bool encontrarAvion(int id);
        CAvion buscarporID(int id);

        /* Getters */
        int getCantidadActual() { return m_cantidadActualAviones; }
        int getID() { return m_aviones->getIDAvion(); }
        
    private:
        CAvion* m_aviones = nullptr;
        int m_cantidadActualAviones = 0;
        int m_AvionesMaximos = 0;
    
    };

#endif