#ifndef CPERSONA_H
#define CPERSONA_H

#include "CCadena.h"

class CPersona
{
    public:

    CPersona(CCadena nombre, int dni);
    CPersona();

    /* Getters y Setters */
    CCadena getNombre() const { return m_nombre; }
    int getDni() const { return m_dni; }
    
    void setDNI(int dni) { m_dni = dni; }
    void setNombre(CCadena nombre) { m_nombre = nombre; }

    private:
        CCadena m_nombre;
        int m_dni;
};

#endif