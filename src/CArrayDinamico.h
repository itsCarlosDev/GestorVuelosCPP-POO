// HELPED BY AI (CHATGPT)

#ifndef CARRAYDINAMICO_H
#define CARRAYDINAMICO_H

#include <vector> // Implementa un array dinamico
// Permite gestionar la memoria de manera dinamica y usar new y delete

/* Funciones que añade */

// push_back(x) → mete un elemento al final.
// erase(it) → borra el elemento en la posición del iterador.
// at(i) → accede al elemento en posición i y comprueba rango.
// operator[](i) → accede al elemento en posición i (rápido, pero sin comprobación).
// size() → cuántos elementos tiene ahora.
// capacity() → cuánta memoria reservada tiene (puede ser mayor que size).
// clear() → borra todos los elementos.

template <typename T>
class CArrayDinamico
{
public:
    // recogemos referencia constante al objeto (para añadir al array)
    void anadir(const T& elem);
    void eliminar(int pos);
    T obtener(int pos);
    int tamano(); // Sin la Ñ ya que puede dar problemas de compilación

private:
    std::vector<T> elementos; // Creacion del array dinamico

};

#endif

template <typename T>
int CArrayDinamico<T>::tamano()
{
    return size(elementos);
}

template <typename T>
void CArrayDinamico<T>::anadir(const T& elem)
{
    elementos.push_back(elem);
}

template <typename T>
void CArrayDinamico<T>::eliminar(int pos)
{
    elementos.erase(pos);
}

template <typename T>
T CArrayDinamico<T>::obtener(int pos)
{
    elementos.at(pos);
}