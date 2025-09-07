
#ifndef CPILOTO_H
#define CPILOTO_H

#include "CPersona.h"

class CPiloto : public CPersona
{
    public:

    // Constructor por defecto
    CPiloto() : m_IDPiloto(0), m_experiencia(0) {}

    /* Getters y Setters */
    int getExperiencia(){ return m_experiencia; }
    int getID() const { return m_IDPiloto; }
    void setExperiencia(int experiencia){ m_experiencia = experiencia; }
    void setID(int id) { m_IDPiloto = id; }

    CPiloto& operator=(const CPiloto& copia);
    // Colocar friend delante del operador permite 
    // acceder a los datos privados
    friend ostream& operator<<(std::ostream& out, const CPiloto& piloto);

    private:
        int m_IDPiloto;
        int m_experiencia;        

};

#endif