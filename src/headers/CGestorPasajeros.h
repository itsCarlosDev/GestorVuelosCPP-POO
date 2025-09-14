
#ifndef CGESTORPASAJEROS_H
#define CGESTORPASAJEROS_H

#include "CPasajero.h"

class CGestorPasajeros
{
    public:
        /*Constructor y destructor*/
        CGestorPasajeros(int maxAviones);
        ~CGestorPasajeros();

        /*Funciones*/
        bool crearPasajeros(int id, int maxPasajeros);
        void mostrarPasajeros();
        bool encontrarPasajero(int id);
        CPasajero buscarporID(int id);
        
    private:
        
    
    };

#endif