#include "MaterialBibliografico.h"
#include <iostream>
using namespace std;

MaterialBibliografico::MaterialBibliografico(const string &nombre, const int &isbn, const string &autor) {
    this->nombre = nombre;
    this->isbn = isbn;
    this->autor = autor;
}

string MaterialBibliografico::getAutor() {
    return this->autor;
}

string MaterialBibliografico::getNombre() {
    return this->nombre;
}

int MaterialBibliografico::getIsbn() {
    return this->isbn;
}


void MaterialBibliografico::mostrarInfo() {
    cout << " \tNombre: " << this->nombre << endl;
    cout << "\tAutor: " << this->autor << endl;
    cout << "\tISBN: " << this->isbn << endl;
}


