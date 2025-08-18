
#include "CGestorVuelos.h";
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

//TODO se podria tener un template para evitar tener tantos ordenar...

bool CGestorVuelos::ordenarPorID(){
    int indexMin;
    int suma, posicion;

    CVuelo vuelo_temp;

    posicion = 0;

    if(m_numVuelos > 1) // Tiene que haber 1 minimo
    { 
        do
        {
            indexMin = posicion;
            for(int i = posicion + 1; i < m_numVuelos; ++i) // Empieza por segunda posicion
            { 
                if(m_vuelo[i].getId()<m_vuelo[indexMin].getId()) // Si es el id de la siguiente posicion mas grande que la anterior, se guarda.
                { 
                    indexMin = i;
                }
            }

            vuelo_temp = m_vuelo[posicion];
            m_vuelo[posicion] = m_vuelo[indexMin];
            m_vuelo[indexMin] = vuelo_temp;

            posicion++; // Pasamos a la siguiente

        } while (posicion != m_numVuelos);
        return true;
    } else {
        return false;
    }
}

bool CGestorVuelos::ordenarPorPrecio(){

    int posicion = 0;
    int MinIndex = 0;

    CVuelo vuelo_temp;
    
    if(m_numVuelos > 1) // Tiene que haber 1 minimo
    { 
        do
        {
            MinIndex = posicion;
            for (int i = posicion + 1; i < m_numVuelos; i++)
            {
                if (m_vuelo[i].getPrecio() < m_vuelo[MinIndex].getPrecio())
                {
                    MinIndex = i;
                }
                
            }

            vuelo_temp = m_vuelo[posicion];
            m_vuelo[posicion] = m_vuelo[MinIndex];
            m_vuelo[MinIndex] = vuelo_temp;

            posicion++;
            
        } while (posicion != m_numVuelos);
        return true;
    } else {
        return false;
    }
}

bool CGestorVuelos::ordenarPorDuracion(){

    int posicion = 0;
    int MinIndex = 0;

    CVuelo vuelo_temp;

    if(m_numVuelos > 1) // Tiene que haber 1 minimo
    {
        do
        {
            MinIndex = posicion;
            for (int i = posicion + 1; i < m_numVuelos; i++)
            {
                if (m_vuelo[i].getDuracion() < m_vuelo[MinIndex].getDuracion())
                {
                    MinIndex = i;
                }
                
            }

            vuelo_temp = m_vuelo[posicion];
            m_vuelo[posicion] = m_vuelo[MinIndex];
            m_vuelo[MinIndex] = vuelo_temp;

            posicion++;
            
        } while (posicion != m_numVuelos);
        return true;
    } else {
        return false;
    }
    
}
