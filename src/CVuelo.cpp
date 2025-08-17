
#include "CVuelo.h";

CVuelo::CVuelo(int ID, int Duracion, int Precio){
    m_IDVuelo = ID;
    m_duracion = Duracion;
    m_precio = Precio;
}

CVuelo::CVuelo(){
    m_IDVuelo = 0;
    m_duracion = 0;
    m_precio = 0;
}

ostream& operator<<(std::ostream& out, const CVuelo& vuelo)
{
    out << "-> Vuelo con ID: " << vuelo.m_IDVuelo << "\n"
        << "- Duración: " << vuelo.m_duracion << " minutos\n"
        << "- Precio: " << vuelo.m_precio << " euros\n";
    return out;
}
