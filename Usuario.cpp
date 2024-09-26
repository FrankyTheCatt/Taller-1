#include "Usuario.h"
#include <iostream>

#include "sistema.h"

/**
 * Constructor de la clase Usuario
 * @param nombre Nombre del usuario en string
 * @param id Id del usuario en string
 */

Usuario::Usuario(const std::string &nombre, const std::string &id) {
    this->nombre = nombre;
    this->id = id;
    for (int i = 0; i < 5; i++) {
        biblioteca[i] = nullptr;
    }
}
std::string Usuario::getNombre() {
    return this->nombre;
}

std::string Usuario::getId() {
    return this->id;
}


MaterialBibliografico *buscarMaterialUser(std::string nombre) {
    for (int i = 0; i < 5; i++) {


    }
}

MaterialBibliografico *Usuario::prestarMaterial(MaterialBibliografico *material) {
    for (int i = 0; i < 5; i++) {
        if (biblioteca[i] == nullptr) {
            biblioteca[i] = material;
            return material;
        }
    }
    std::cout << "No puedes pedir mas de 5 materiales..." << std::endl;
    return nullptr;
}

MaterialBibliografico *Usuario::devolverMaterial(std::string material) {
    MaterialBibliografico a = buscarMaterialUser(material);
    for (int i = 0; i < 5; i++) {
        if (biblioteca[i] == a) {
            biblioteca[i] = nullptr;
            return material;
        }
    }
    std::cout << "No puedes devolver lo que no tienes..." << std::endl;
    return nullptr;
}

void Usuario::mostrarMaterialesPrestados() {
    for (int i = 0; i < 5; i++) {
        if (biblioteca[i] != nullptr) {
            std::cout << "-> " << biblioteca[i]->getNombre() << std::endl;
        }
    }
}

void Usuario::mostrarInfo() {
    std::cout << "Nombre: " << this->nombre << std::endl;
    std::cout << "Id: " << this->id << std::endl;
}
