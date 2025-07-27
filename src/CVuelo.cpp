
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