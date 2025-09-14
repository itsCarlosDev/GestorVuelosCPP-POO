
#include "./headers/CGestorVuelos.h"
#include <iostream>

bool CGestorVuelos::crearVuelo(CVuelo vuelo){
    if(m_numVuelos < 5){
        m_vuelo[m_numVuelos] = vuelo;
        m_numVuelos++;
        return true;
    } else {
        return false;
    } 
}

bool CGestorVuelos::eliminarVuelo(int id){
    if(m_numVuelos != 0){
        for(int i=0; i <= m_numVuelos; i++){
            if(m_vuelo[i].getId()==id){
                for(int j=i+1; j < m_numVuelos; j++){
                    m_vuelo[j-1].setDuracion(m_vuelo[j].getDuracion());
                    m_vuelo[j-1].setId(m_vuelo[j].getId());
                    m_vuelo[j-1].setPrecio(m_vuelo[j].getPrecio());
                }
            }
        }
        m_numVuelos--;
        return true;
    } else {
        return false;
    }
}

bool CGestorVuelos::modificarVuelos(int id, CVuelo vuelo){
    int contador;
    if(m_numVuelos != 0){
        for(int i=0; i < m_numVuelos; i++){
            if(contador != m_numVuelos){
                if(m_vuelo[i].getId()==id){
                    m_vuelo[i] = vuelo;
                    contador++;
                    return true;
                }
            } else {
                cout << "No existe ningun vuelo con el ID: " << id << "\n";
                return false;
            }
        }
    } else {
        return false;
    }
}

void CGestorVuelos::mostrarVuelos(){
    if(m_numVuelos != 0){
        for(int i=0; i < m_numVuelos; i++){
                cout << m_vuelo[i] << "\n";
        }
    } else {
        cout << "No hay vuelos que mostrar. ";
    }
}

void CGestorVuelos::buscarporID(int id){
    if(m_numVuelos != 0){
        for(int i=0; i <=m_numVuelos; i++){
            if(m_vuelo[i].getId()==id){
                cout << "Se encontro un vuelo con id: " << id;
                cout << m_vuelo[i];
            }
        }
    }
}

