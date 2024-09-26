// Usuario.h
#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include "MaterialBibliografico.h"

class Usuario {
private:
    std::string nombre;
    std::string id;
    MaterialBibliografico* biblioteca[5]{};

public:
    Usuario(const std::string &nombre, const std::string &id);
    std::string getNombre();
    std::string getId();
    MaterialBibliografico* prestarMaterial(MaterialBibliografico* material);

    MaterialBibliografico *devolverMaterial(std::string material);

    void mostrarMaterialesPrestados();
    void mostrarInfo();
    MaterialBibliografico buscarMaterialUser(std::string string);
};

#endif
