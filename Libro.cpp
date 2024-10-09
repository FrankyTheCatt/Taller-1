#include "Libro.h"
#include <iostream>

using namespace std;

Libro::Libro(const string &nombre, const int &isbn, const string &autor, const string &resumen, const string &fechapublicacion)
    : MaterialBibliografico(nombre, isbn, autor), resumen(resumen), fechapublicacion(fechapublicacion) {
}

void Libro::mostrarInfo() {
    MaterialBibliografico::mostrarInfo();
    std::cout << "\tResumen: " << this->resumen << std::endl;
    std::cout << "\tFecha publicacion: " << this->fechapublicacion << std::endl;
    std::cout << "\n" << std::endl;
}
