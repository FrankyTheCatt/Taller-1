#include "Revista.h"
#include <iostream>

Revista::Revista(const std::string &nombre, const std::string &isbn, const std::string &autor, int diff, const std::string &numeroEdicion, const std::string &mesPublicacion)
    : MaterialBibliografico(nombre, isbn, autor, diff), numeroEdicion(numeroEdicion), mesPublicacion(mesPublicacion) {
}

void Revista::mostrarInfo() {
    MaterialBibliografico::mostrarInfo();

    std::cout << "\tNumero Edicion: " << this->numeroEdicion << std::endl;
    std::cout << "\tMes Publicacion: " << this->mesPublicacion << std::endl;
}
