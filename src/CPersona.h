#ifndef CPERSONA.H
#define CPERSONA.H

#include "CCadena.h"

class CPersona{

    public:

    // Getters and Setters
    CCadena get_nombre(){
		return m_nombre;
	}
    int get_edad() {
        return m_edad;
    }
    int get_dni() {
        return m_dni;
    }

    private:
        CCadena m_nombre;
        int m_edad;
        int m_dni;

}

#endif