
#ifndef CCLASE_H
#define CCLASE_H

#include <string>

class CClase
{
    public:
        CClase() : m_precio(0), m_nombre(""){};
        CClase(int precio, std::string nombre) : m_precio(precio), m_nombre(nombre) {};
        ~CClase();
    private:
        int m_precio;
        std::string m_nombre;
};

#endif




