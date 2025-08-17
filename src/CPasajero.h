#ifndef CPASAJERO.H
#define CPASAJERO.H

class CPasajero{

    public:
    
        void asignarVuelo(CVuelo vuelo){
            m_vuelo = vuelo;
        }


    private:
        CPersona pasajero;
};

#endif