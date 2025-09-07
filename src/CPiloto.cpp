
#include "CPiloto.h"

// this sirve para indicar si por ejemplo a = b
// si a es diferente de b (this es a, b es el objeto copia)

CPiloto& CPiloto::operator=(const CPiloto& copia){
    if (this != &copia) { // Evitar auto‑asignación
        // Copiamos los miembros de CPiloto
        this->m_experiencia = copia.m_experiencia;
        this->m_IDPiloto = copia.m_IDPiloto;
        
        // Copiamos la persona asociada
        this->setDNI(copia.getDni());
        this->setNombre(copia.getNombre());
    }
    return *this;   
}

ostream& operator<<(std::ostream& out, const CPiloto& piloto)
{
    out << "-> Piloto con ID: " << piloto.m_IDPiloto << "\n"
        << "- Nombre: " << piloto.getNombre() << "\n"
        << "- Experiencia: " << piloto.m_experiencia << " años\n"
        << "- DNI: " << piloto.getDni()
        ;
    return out;
}
