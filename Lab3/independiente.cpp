#include "independiente.h"

Cliente* pregunta3(ListaCola* listaCola) {
    if (listaCola->cantidadClientes == 0) {
        return nullptr; // La cola está vacía
    }

    Cliente* clienteSacado = &listaCola->cola[listaCola->inicio];
    listaCola->inicio = (listaCola->inicio + 1) % listaCola->capacidadMaxima;
    listaCola->cantidadClientes--;

    return clienteSacado;
}

void pregunta4(ListaCola* listaCola, Cliente* cliente, int posicion) {
    if (posicion < 0 || posicion > listaCola->cantidadClientes) {
        std::cout << "Posición no válida." << std::endl;
        return;
    }

    if (listaCola->cantidadClientes >= listaCola->capacidadMaxima) {
        std::cout << "La cola está llena, no se puede insertar." << std::endl;
        return;
    }

    int index = (listaCola->inicio + posicion) % listaCola->capacidadMaxima;

    for (int i = listaCola->cantidadClientes; i > posicion; i--) {
        int prevIndex = (listaCola->inicio + i - 1) % listaCola->capacidadMaxima;
        listaCola->cola[(prevIndex + 1) % listaCola->capacidadMaxima] = listaCola->cola[prevIndex];
    }

    listaCola->cola[index] = *cliente;
    listaCola->fin = (listaCola->fin + 1) % listaCola->capacidadMaxima;
    listaCola->cantidadClientes++;
}

void pregunta5(ListaCola* listaCola, int i, int j) {
    if (i < 0 || i >= listaCola->cantidadClientes || j < 0 || j >= listaCola->cantidadClientes) {
        std::cout << "Posiciones no válidas." << std::endl;
        return;
    }

    int indexI = (listaCola->inicio + i) % listaCola->capacidadMaxima;
    int indexJ = (listaCola->inicio + j) % listaCola->capacidadMaxima;

    Cliente temp = listaCola->cola[indexI];
    listaCola->cola[indexI] = listaCola->cola[indexJ];
    listaCola->cola[indexJ] = temp;
}
