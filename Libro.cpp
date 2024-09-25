#include "Libro.h"
#include <iostream>

Libro::Libro(const std::string &nombre, const std::string &isbn, const std::string &autor, bool estado,
             const std::string &resumen, const std::string &fechapublicacion)
    : MaterialBibliografico(nombre, isbn, autor), resumen(resumen), fechapublicacion(fechapublicacion) {
    this->resumen = resumen;
    this->fechapublicacion = fechapublicacion;
}

void MaterialBibliografico::mostarInfo() {
    std::cout << "\tAutor: " << this->autor << std::endl;
    std::cout << "\tIsbn: " << this->isbn << std::endl;
}