//
// Created by nicol y marticuta saricuta on 18-09-2024.
//

#include "Revista.h"

Revista::Revista(const std::string &nombre, const std::string &isbn, const std::string &autor, bool estado,
             const int &numeroEdicion, const int mesPublicacion)
    : MaterialBibliografico(nombre, isbn, autor, estado), numeroEdicion(numeroEdicion), mesPublicacion(mesPublicacion) {

}


