#include "Revista.h"
#include <iostream>

using namespace std;

Revista::Revista(const string &nombre, const int &isbn, const string &autor, const string &numeroEdicion, const int &mesPublicacion)
    : MaterialBibliografico(nombre, isbn, autor), numeroEdicion(numeroEdicion), mesPublicacion(mesPublicacion) {
}

void Revista::mostrarInfo() {
    MaterialBibliografico::mostrarInfo();

    cout << "\tNumero Edicion: " << this->numeroEdicion << endl;
    cout << "\tMes Publicacion: " << this->mesPublicacion << endl;
}
