
#include "CGestorAviones.h"
#include "CAvion.h"

CGestorAviones::CGestorAviones(int numMax){
    if(numMax > 0){
        m_aviones[numMax];
    } else {
        m_aviones = nullptr;
    }
    m_AvionesMaximos = numMax;
}

CGestorAviones::~CGestorAviones(){
    delete m_aviones;
}


bool CGestorAviones::crearAvion(int id, int maxPasajeros){
    CAvion avion;
    CPasajero pasajero;

    if(m_cantidadActualAviones < m_AvionesMaximos){
        avion.setIDAvion(id);
        avion.setMaxPasajeros(maxPasajeros);

        m_cantidadActualAviones++;
        return true;
    } else {
        return false;
    }
    
}

bool CGestorAviones::encontrarAvion(int id){
    for (int i = 0; i < m_cantidadActualAviones; i++)
    {
        if(m_aviones[i].getIDAvion() == id){
            return true;
        }
    }
    return false;
}

// Siempre se encontrara el piloto ya que antes hacemos 
// encontrarPiloto() en el main el cual si el piloto no 
// existe devuelve un false y avisa al usuario.

CAvion CGestorAviones::buscarporID(int id){
    for (int i = 0; i < m_cantidadActualAviones; i++)
    {
        if(m_aviones[i].getIDAvion() == id){
            return m_aviones[i];
        }
    }
}

void CGestorAviones::mostrarAviones(){
    if(m_cantidadActualAviones != 0){
        for(int i=0; i < m_cantidadActualAviones; i++){
                cout << m_aviones[i] << "\n";
        }
    } else {
        cout << "No hay aviones que mostrar. ";
    }
}