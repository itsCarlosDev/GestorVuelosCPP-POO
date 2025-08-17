#ifndef CGESTORVUELO_H
#define CGESTORVUELO_H

#include "CVuelo.h"

class CGestorVuelos
{
    public:
        void esperar(int segundos);
        bool crearVuelo(CVuelo vuelo);
        bool modificarVuelos(int id, CVuelo vuelo);
        bool eliminarVuelo(int id);
        void buscarporID(int id);
        void mostrarVuelos();
        void ordenarPorID();

        /* Getters */
        int getnumVuelos(){
            return m_numVuelos;
        }

    private:
        CVuelo m_vuelo[5];
        int m_numVuelos = 0; // It has to be inicialiced

};

#endif