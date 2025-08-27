#ifndef CPASAJERO_H
#define CPASAJERO_H

#include "CPersona.h"

class CPasajero{

    public:

        // Un puntero (CPersona*) no es lo mismo que una instancia (CPersona).
        // - Con un puntero, se usa "->" para acceder a métodos/atributos: pasajero->getNombre()
        // - Con una instancia (objeto directo), se usa "." : pasajero.getNombre()

        CPasajero& operator=(const CPasajero& copia);

        CCadena getNombre() const { return pasajero.getNombre(); }
        int getDni() const { return pasajero.getDni(); }

        void setDNI(int dni) { pasajero.setDNI(dni); }
        void setNombre(CCadena nombre) { pasajero.setNombre(nombre); }

    private:
        CPersona pasajero;
};

#endif