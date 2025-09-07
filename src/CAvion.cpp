
#include "CAvion.h"
#include "CPasajero.h"

std::ostream& operator<<(std::ostream& out, const CAvion& avion) {
    out << "-> ID Avion: " << avion.m_IDAvion
        << "\n- Pasajeros Maximos: " << avion.m_maxPasajeros
        << "\n- Pasajeros Actuales: " << avion.m_numPasajeros;
    return out;
}
