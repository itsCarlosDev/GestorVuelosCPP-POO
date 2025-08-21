
#include "CVuelo.h";

CVuelo::CVuelo()
{
    // Mejorar el constructor por defecto CVuelo ya que tener dos objetos asi no esta bien.
    CPiloto piloto1;
    CPiloto piloto2;

    m_IDVuelo = 0;
    m_duracion = 0;
    m_precio = 0;
    m_numMaxPasajeros = 0;
    m_pilotos[0] = piloto1;
    m_pilotos[1] = piloto2;
}

CVuelo::CVuelo(int id, int Duracion, int Precio, int maxPasajeros, CPiloto piloto1, CPiloto piloto2){
    m_IDVuelo = id;
    m_duracion = Duracion;
    m_precio = Precio;
    m_numMaxPasajeros = maxPasajeros;
    m_pilotos[0] = piloto1;
    m_pilotos[1] = piloto2;
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
        ;
    return out;
}
