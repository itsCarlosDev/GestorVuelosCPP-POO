
#include "CPasajero.h"

CPasajero& CPasajero::operator=(const CPasajero& copia){
    if(this != &copia){
        this->pasajero.setDNI(copia.pasajero.getDni());
        this->pasajero.setNombre(copia.pasajero.getNombre());
    }
    return *this;
}