
#include "CGestorPilotos.h"
#include "CPiloto.h"
#include "CPersona.h"

CGestorPilotos::CGestorPilotos(int maxPilotos){
    if (maxPilotos > 0){
        m_piloto = new CPiloto[maxPilotos];
    } else {
        m_piloto = nullptr;
    }
}

CGestorPilotos::~CGestorPilotos()
{
    delete[] m_piloto;    // liberar todo el bloque
}

bool CGestorPilotos::crearPiloto(const CCadena& nombre, int dni, int experiencia, int ID){
    CPiloto piloto;
    CPersona persona;

    if(m_numPilotosActuales < m_numPlantilla){
        persona.setDNI(dni);
        persona.setNombre(nombre);

        piloto.setExperiencia(experiencia);
        piloto.setPersona(persona);
        piloto.setID(ID);

        m_piloto[m_numPilotosActuales] = piloto;
        m_numPilotosActuales++;

        return true;
    } else {
        return false;
    }
}

bool CGestorPilotos::encontrarPiloto(int id){
    for (int i = 0; i < m_numPilotosActuales; i++)
    {
        if(m_piloto[i].getID() == id){
            return true;
        }
    }
    return false;
}

// Siempre se encontrara el piloto ya que antes hacemos encontrarPiloto() en el main el cual
// si el piloto no existe devuelve un false y avisa al usuario.

CPiloto CGestorPilotos::buscarporID(int id){
    for (int i = 0; i < m_numPilotosActuales; i++)
    {
        if(m_piloto[i].getID() == id){
            return m_piloto[i];
        }
    }
}

void CGestorPilotos::mostrarPilotos(){
    if(m_numPilotosActuales != 0){
        for(int i=0; i < m_numPilotosActuales; i++){
                cout << m_piloto[i] << "\n";
        }
    } else {
        cout << "No hay pilotos que mostrar. ";
    }
}