
#include "CGestorVuelos.h";
#include <iostream> 

// TODO Se puede mejorar para que el login sea mucho mas seguro
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
                if(m_numVuelos > 1){
                    for(int j=i+1; j <= m_numVuelos; j++){
                        m_vuelo[j].setDuracion(m_vuelo[j-1].getDuracion());
                        m_vuelo[j].setId(m_vuelo[j-1].getId());
                        m_numVuelos--;
                    }
                } else {
                    m_numVuelos--;
                }
            }
        }
        return true;
    } else {
        return false;
    }
}

bool CGestorVuelos::modificarVuelos(int id, CVuelo vuelo){
    int contador;
    if(m_numVuelos != 0){
        for(int i=0; i <=m_numVuelos; i++){
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

void CGestorVuelos::ordenarPorID(){
    int id, duracion, precio;
    int suma, posicion;

    id = m_vuelo[0].getId();
    duracion = m_vuelo[0].getDuracion();
    precio = m_vuelo[0].getPrecio();

    if(m_numVuelos >= 1){
        for(int i=1; i<m_numVuelos; i++){
            if(suma != m_numVuelos){
                if(m_vuelo[i].getId()<id){
                    id = m_vuelo[i].getId();
                    duracion = m_vuelo[i].getDuracion();
                    precio = m_vuelo[i].getPrecio();
                } else {
                    suma++;
                }
            } else {
                m_vuelo[posicion].setId(id);
                m_vuelo[posicion].setDuracion(duracion);
                m_vuelo[posicion].setPrecio(precio);
                posicion++;
                id = m_vuelo[posicion].getId();
                suma =0;
            }
        }
        
    }
}
