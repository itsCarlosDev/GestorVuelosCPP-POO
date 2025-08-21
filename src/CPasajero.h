#ifndef CPASAJERO.H
#define CPASAJERO.H

#include "CPersona.h";
#include "CAvion.h";

class CPasajero{

    public:

        void crearPasajero();
        //void asignarVuelo(CVuelo vuelo);
        //void asignarAvion(CAvion avion);

    private:
        CPersona pasajero;
};

#endif