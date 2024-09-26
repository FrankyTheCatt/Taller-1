#include "Libro.h"
#include <iostream>

Libro::Libro(const std::string &nombre, const std::string &isbn, const std::string &autor, const std::string &resumen, int diff, const std::string &fechapublicacion)
    : MaterialBibliografico(nombre, isbn, autor, diff), resumen(resumen), fechapublicacion(fechapublicacion) {
}

void Libro::mostrarInfo() {
    MaterialBibliografico::mostrarInfo();
    std::cout << "\tResumen: " << this->resumen << std::endl;
    std::cout << "\tFecha publicacion: " << this->fechapublicacion << std::endl;
    std::cout << "\n" << std::endl;
}
