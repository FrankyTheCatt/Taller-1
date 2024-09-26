// sistema.h
#ifndef SISTEMA_H
#define SISTEMA_H

#include <iostream>
#include "Libro.h"
#include "MaterialBibliografico.h"
#include "Revista.h"
#include "Usuario.h"

struct DatosComunes {
    std::string nombre;
    std::string isbn;
    std::string autor;
};

// Declaraciones de funciones
void agregarMaterial(const std::string &string, const std::string &isbn, const std::string &autor, std::string arg1, const std::string &arg2, int diff);
void listarMateriales();
int buscarEspacio();
void revisarMaterial(std::string a);
MaterialBibliografico *buscarMaterial(std::string b);
void pedirMaterial(std::string titulo, std::string usuario);
void crearUsuario(const std::string &nombre, const std::string &id);
Usuario *buscarUsuario(std::string id);
int buscarEspacioUsuario();
void imprimirUsuario(std::string b);
void eliminarMaterial(MaterialBibliografico *material);
void eliminarUsuario(std::string b);


#endif
