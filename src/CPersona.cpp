
#include "CPersona.h";

CPersona::CPersona(CCadena nombre, int dni){
    m_nombre = nombre;
    m_dni = dni;
}

CPersona::CPersona(){
    m_nombre = "Error";
    m_dni = 12345;
}

