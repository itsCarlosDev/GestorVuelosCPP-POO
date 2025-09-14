#ifndef CGESTORVUELO_H
#define CGESTORVUELO_H

#include "CVuelo.h"

class CGestorVuelos
{
    public:
        template <typename Getter>
        bool ordenar(Getter getter); // OrdenarporPrecio, ordenarporDuracion, ordenarPorId

        void esperar(int segundos);

        bool crearVuelo(CVuelo vuelo);
        bool modificarVuelos(int id, CVuelo vuelo);
        bool eliminarVuelo(int id);
        void buscarporID(int id);
        void mostrarVuelos();

        /* Getters */
        int getnumVuelos(){
            return m_numVuelos;
        }

    private:
        CVuelo m_vuelo[5];
        int m_numVuelos = 0;
        

};

//Ayuda con AI para lograr realizar estos cambios
template <typename Getter>
bool CGestorVuelos::ordenar(Getter getter) {
    if (m_numVuelos <= 1) return false;

    int posicion = 0;
    do {
        int MinIndex = posicion;
        for (int i = posicion + 1; i < m_numVuelos; i++) {
            // El * sirve para indicar que es un puntero 
            if ((m_vuelo[i].*getter)() < (m_vuelo[MinIndex].*getter)()) { 
                MinIndex = i;
            }
        }

        CVuelo vuelo_temp = m_vuelo[posicion];
        m_vuelo[posicion] = m_vuelo[MinIndex];
        m_vuelo[MinIndex] = vuelo_temp;

        posicion++;
    } while (posicion != m_numVuelos);

    return true;
}

#endif