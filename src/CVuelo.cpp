
<<<<<<< HEAD
/**
 * FITXER: CVuelo.cpp
 * AUTOR: Carlos Morales
 * DATA: 13/09/2025
 * VERSIO: 6.0
 * Descripció: Contiene los datos de los vuelos
 */

=======
>>>>>>> 7fe59fd07166bef4c32246d88d85878eef614e6c
#include "./headers/CVuelo.h";

CVuelo::CVuelo()
{
    m_IDVuelo = 0;
    m_duracion = 0;
    m_precio = 0;
    m_numMaxPasajeros = 0;
    m_pilotos[0] = CPiloto();
    m_pilotos[1] = CPiloto();
    avionAsignado = CAvion();
}

CVuelo::CVuelo(CCadena origen, CCadena destino, int id, int Duracion, 
                int Precio, int maxPasajeros, CPiloto piloto1, CPiloto piloto2, CAvion avion){
    m_origen = origen;
    m_destino = destino;
    m_IDVuelo = id;
    m_duracion = Duracion;
    m_precio = Precio;
    m_numMaxPasajeros = maxPasajeros;
    m_pilotos[0] = piloto1;
    m_pilotos[1] = piloto2;
    avionAsignado = avion;
}

ostream& operator<<(std::ostream& out, const CVuelo& vuelo)
{
    out << "-> Vuelo con ID: " << vuelo.m_IDVuelo << "\n"
        << "- Duración: " << vuelo.m_duracion << " minutos\n"
        << "- Precio: " << vuelo.m_precio << " euros\n"
        << "- Pilotos asignados: \n"
        << "-- " << vuelo.m_pilotos[0].getNombre() << " con ID: " << vuelo.m_pilotos[0].getID() << "\n"
        << "-- " << vuelo.m_pilotos[1].getNombre() << " con ID: " << vuelo.m_pilotos[1].getID() << "\n"
        << "- Avion Asignado: \n"
        << "-- " << " Avion asignado con ID: " << vuelo.avionAsignado.getIDAvion() << "\n"
        ;
    return out;
}
