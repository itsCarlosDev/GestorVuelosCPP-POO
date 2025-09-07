#ifndef CPASAJERO_H
#define CPASAJERO_H

#include "CPersona.h"
#include "CClase.h"
#include <list>

class CPasajero : public CPersona
{

    public:

        

        // Un puntero (CPersona*) no es lo mismo que una instancia (CPersona).
        // - Con un puntero, se usa "->" para acceder a métodos/atributos: pasajero->getNombre()
        // - Con una instancia (objeto directo), se usa "." : pasajero.getNombre()

        CPasajero& operator=(const CPasajero& copia);

    private:
        std::list<CClase> m_clase;
};

#endif