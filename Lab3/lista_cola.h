#pragma once
#include "cliente.h"

class ListaCola {
public:
    ListaCola(int capacidadMaxima);
    int Encolar(const char* nombre, const char* dni, int cantidadEntradas);
    void Atender();

private:
    int capacidadMaxima;
    Cliente* cola;
    int inicio;
    int fin;
    int cantidadClientes;
};
