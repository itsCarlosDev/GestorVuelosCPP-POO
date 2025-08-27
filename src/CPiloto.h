
#ifndef CPILOTO_H
#define CPILOTO_H

#include "CPersona.h"

class CPiloto
{
    public:

    // Constructor por defecto
    CPiloto() : m_IDPiloto(0), m_experiencia(0) {}

    // Getters
    int getExperiencia(){ return m_experiencia; }
    int getID() const { return m_IDPiloto; }
    CCadena getNombre() const { return piloto.getNombre(); }

    // Setters
    void setExperiencia(int experiencia){ m_experiencia = experiencia; }
    void setPersona(CPersona& persona) { piloto = persona; }
    void setID(int id) { m_IDPiloto = id; }

    CPiloto& operator=(const CPiloto& copia);
    // Colocar friend delante del operador permite 
    // acceder a los datos privados

    friend ostream& operator<<(std::ostream& out, const CPiloto& piloto);

    private:
        CPersona piloto; // Composicion, de esta manera CPiloto no es un CPersona ** No hay polimorfismo **
        // Seria necesario tener polimorfismo si juntara a las personas, si tubiera pilotos y pasajeros juntos
        int m_IDPiloto;
        int m_experiencia;

};

#endif