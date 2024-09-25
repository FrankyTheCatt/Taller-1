//
// Created by nicol y marticuta saricuta on 18-09-2024.
//

#include "Revista.h"

Revista::Revista(const std::string &nombre, const std::string &isbn, const std::string &autor,
             const std::string &numeroEdicion, const std::string mesPublicacion)
    : MaterialBibliografico(nombre, isbn, autor), numeroEdicion(numeroEdicion), mesPublicacion(mesPublicacion) {

}


