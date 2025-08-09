
#include "CVuelo.h";
#include <thread>   // std::this_thread::sleep_for
#include <chrono>   // std::chrono::seconds, std::chrono::milliseconds

// Created by AI
void esperar(int segundos) {
    std::this_thread::sleep_for(std::chrono::seconds(segundos));
}

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

// TODO Se puede mejorar para que el login sea mucho mas seguro
void CVuelo::crearVuelo(int idVuelo, int duracion, int precio){
    
    int pass;

    cout << "\nIntroduce la contraseña: ";
    cin >> pass;

    if(pass == 1234){ // Simple version of login check
        cout << "Bienvenido Admin.\n";
        m_IDVuelo = idVuelo;
        m_duracion = duracion;
        m_precio = precio;
        cout << "Realizando cambios...\n";
        esperar(1);
        cout << "Por favor espere...\n";
        esperar(3);
        
    } else {
        cout << "Contraseña incorrecta.\n";
    }
    
    cout << "Proceso finalizado correctamente. \n";
    
}