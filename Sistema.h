// sistema.h
#ifndef SISTEMA_H
#define SISTEMA_H

#include <iostream>
#include "Libro.h"
#include "MaterialBibliografico.h"
#include "Revista.h"

struct DatosComunes {
    std::string nombre;
    std::string isbn;
    std::string autor;
};

// Declaraciones de funciones
void correr();
void agregarMaterial(const std::string &string, const std::string &isbn, const std::string &autor, std::string arg1, const std::string &arg2, int
                     diff);
int buscarEspacio();
bool revisarMaterial(int a);
MaterialBibliografico *buscarLibro(const std::string b, int a, MaterialBibliografico **c);

#endif
