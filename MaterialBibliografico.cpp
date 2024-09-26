#include "MaterialBibliografico.h"
#include <iostream>

MaterialBibliografico::MaterialBibliografico(const std::string &nombre, const std::string &isbn, const std::string &autor, const int &diff) {
    this->nombre = nombre;
    this->isbn = isbn;
    this->autor = autor;
    this->diff = diff;
}

// Getters
std::string MaterialBibliografico::getAutor() {
    return this->autor;
}

std::string MaterialBibliografico::getNombre() {
    return this->nombre;
}

std::string MaterialBibliografico::getIsbn() {
    return this->isbn;
}

int MaterialBibliografico::getdiff() {
    return this->diff;
}

void MaterialBibliografico::mostrarInfo() {
    std::cout << " \tNombre: " << this->nombre << std::endl;
    std::cout << "\tAutor: " << this->autor << std::endl;
    std::cout << "\tISBN: " << this->isbn << std::endl;
}


