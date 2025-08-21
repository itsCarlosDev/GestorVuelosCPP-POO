#ifndef CPERSONA.H
#define CPERSONA.H

#include "CCadena.h"

class CPersona
{
    public:

    CPersona(CCadena nombre, int dni);
    CPersona();

    /* Getters */
    // Se ha añadido constante para hacer funcionar la sobrecarga
    // del operador =, ya que este es constante.
    CCadena getNombre() const { return m_nombre; }
    int getDni() const { return m_dni; }

    /* Setters */
    void setDNI(int dni) { m_dni = dni; }
    void setNombre(CCadena nombre) { m_nombre = nombre; }

    private:
        CCadena m_nombre;
        int m_dni;
};

#endif