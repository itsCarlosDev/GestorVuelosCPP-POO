
#include "./headers/CAvion.h"
#include "./headers/CPasajero.h"

CAvion::CAvion(int id, int maxPasajeros)
    : m_IDAvion(id), m_maxPasajeros(maxPasajeros), m_numPasajeros(0)
{
    if (m_maxPasajeros > 0) {
        m_pasajeros = new CPasajero[m_maxPasajeros];
    } else {
        m_pasajeros = nullptr;
    }
}

CAvion::~CAvion()
{
    delete[] m_pasajeros;
    m_pasajeros = nullptr;
    m_numPasajeros = 0;
    m_maxPasajeros = 0;
}

std::ostream& operator<<(std::ostream& out, const CAvion& avion) {
    out << "-> ID Avion: " << avion.m_IDAvion
        << "\n- Pasajeros Maximos: " << avion.m_maxPasajeros
        << "\n- Pasajeros Actuales: " << avion.m_numPasajeros;
    return out;
}
