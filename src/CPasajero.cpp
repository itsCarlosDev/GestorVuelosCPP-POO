
#include "CPasajero.h"

CPasajero& CPasajero::operator=(const CPasajero& copia){
    if(this != &copia){
        this->setDNI(copia.getDni());
        this->setNombre(copia.getNombre());
    }
    return *this;
}