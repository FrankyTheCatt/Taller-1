// Usuario.h
#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include "MaterialBibliografico.h"

class Usuario {
private:
    std::string nombre;
    std::string id;
    MaterialBibliografico* biblioteca[5]{}; // Arreglo de 5 punteros a MaterialBibliografico

public:
    Usuario(const std::string &nombre, const std::string &id);

    std::string getNombre();
    std::string getId();

    MaterialBibliografico* prestarMaterial(MaterialBibliografico* material);
    MaterialBibliografico* devolverMaterial(MaterialBibliografico* material);
    void mostrarMaterialesPrestados(); // void para mostrar los materiales
};

#endif
