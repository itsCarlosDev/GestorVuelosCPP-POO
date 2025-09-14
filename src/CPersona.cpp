
#include "./headers/CPersona.h"

CPersona::CPersona() : m_nombre(), m_dni(0) {}

CPersona::CPersona(CCadena nombre, int dni){
    m_nombre = nombre;
    m_dni = dni;
}

