#include "lista_cola.h"
#include "cliente.h"
#include <iostream>

ListaCola::ListaCola(int capacidadMaxima) {
    this->capacidadMaxima = capacidadMaxima;
    this->cola = new Cliente[capacidadMaxima];
    this->inicio = 0;
    this->fin = -1;
    this->cantidadClientes = 0;
}

int ListaCola::Encolar(const char* nombre, const char* dni, int cantidadEntradas) {
    if (cantidadClientes >= capacidadMaxima) {
        return -1; // La cola está llena
    }

    fin = (fin + 1) % capacidadMaxima;
    Cliente nuevoCliente(nombre, dni, cantidadEntradas);
    cola[fin] = nuevoCliente;
    cantidadClientes++;

    return (capacidadMaxima - cantidadClientes);
}

void ListaCola::Atender() {
    if (cantidadClientes == 0) {
        std::cout << "La cola está vacía." << std::endl;
        return;
    }

    Cliente clienteAtendido = cola[inicio];
    std::cout << "Nombre: " << clienteAtendido.nombre << std::endl;
    std::cout << "DNI: " << clienteAtendido.dni << std::endl;
    std::cout << "Cantidad de entradas: " << clienteAtendido.cantidadEntradas << std::endl;

    inicio = (inicio + 1) % capacidadMaxima;
    cantidadClientes--;
}
