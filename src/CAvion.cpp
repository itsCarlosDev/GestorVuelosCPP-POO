
#include "CAvion.h"
#include "CPasajero.h"

CAvion::CAvion(int id, int maxPasajeros){
    if(maxPasajeros > 0){
        m_pasajeros = new CPasajero[maxPasajeros];
    } else {
        m_pasajeros = nullptr;
    }
    m_IDAvion = id;
}

CAvion::~CAvion() {
    delete[] m_pasajeros;
}

void CAvion::crearPasajero(CPasajero persona){
    if (m_numPasajeros < m_maxPasajeros) {
        m_pasajeros[m_numPasajeros] = persona;
        m_numPasajeros++;
    }
}

std::ostream& operator<<(std::ostream& out, const CAvion& avion) {
    out << "-> ID Avion: " << avion.m_IDAvion
        << "\n- Pasajeros Maximos: " << avion.m_maxPasajeros
        << "\n- Pasajeros Actuales: " << avion.m_numPasajeros;
    return out;
}

/*
// Sobrecarga de operador especial porque es de array reservado
CAvion& CAvion::operator=(const CAvion& copia){
    if (this != &copia) {           // Evitar auto‑asignación
        // Copiamos los miembros de CAvion
        this->m_maxPasajeros = copia.m_maxPasajeros;
        this->m_IDAvion = copia.m_IDAvion;
        
        // Copiamos los pasajeros, helped with ai
        delete[] this->m_pasajeros;
        if (copia.m_maxPasajeros > 0) {
            this->m_pasajeros = new CPasajero[copia.m_maxPasajeros];
            for (int i = 0; i < copia.m_numPasajeros; ++i) {
                this->m_pasajeros[i] = copia.m_pasajeros[i];
            }
        } else {
            this->m_pasajeros = nullptr;
        }
        this->m_numPasajeros = copia.m_numPasajeros;
    }
    return *this;   
}

*/
