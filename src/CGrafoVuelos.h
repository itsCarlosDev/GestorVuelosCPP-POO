#ifndef CGRAFOVUELOS_H
#define CGRAFOVUELOS_H

#include <vector>
#include "CVuelo.h"

// Conexion entre dos verticesento
struct arista 
{
    CVuelo vuelo;
    int tiempo;
};

class CGrafoVuelos
{
	public:
	
        // Pasamos la direcion del vuelo ya creado
		bool añadirVuelo(const CVuelo& vuelo, int tiempoVuelo);
		void mostrarRutas();
	
	private:
		vector<arista> adj_; // Lista de aydacencia y 
                             // "_" porque es privado
};

#endif