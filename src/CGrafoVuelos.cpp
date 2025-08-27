
/* Funciones que añade <vector>*/

// push_back(x) → mete un elemento al final.
// erase(it) → borra el elemento en la posición del iterador.
// at(i) → accede al elemento en posición i y comprueba rango.
// operator[](i) → accede al elemento en posición i (rápido, pero sin comprobación).
// size() → cuántos elementos tiene ahora.
// capacity() → cuánta memoria reservada tiene (puede ser mayor que size).
// clear() → borra todos los elementos.

#include "CGrafoVuelos.h"

bool CGrafoVuelos::añadirVuelo(const CVuelo& vuelo, int tiempoVuelo)
{
    adj_.push_back(arista{vuelo, tiempoVuelo});
    return true;
}