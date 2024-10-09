// sistema.h
#ifndef SISTEMA_H
#define SISTEMA_H

#include <iostream>
#include "Libro.h"
#include "MaterialBibliografico.h"
#include "Revista.h"
#include "Usuario.h"
class Sistema {
private:
    MaterialBibliografico* biblioteca[100];
    int numLibros;

    Usuario* usuarios[100];
    int numUsuarios;
    public:
    Sistema();
    ~Sistema();
    void cargarDatos();
    void agregarMaterial();
    void prestarDevolver();
    void gestionUsurios();
    void mostrarMenu();
    void listarMateriales();
    int buscarEspacio();
    void revisarMaterial();
    MaterialBibliografico *buscarMaterial(std::string b);
    void pedirMaterial(std::string titulo, std::string usuario);
    void crearUsuario(const std::string &nombre, const std::string &id);
    Usuario *buscarUsuario(std::string id);
    int buscarEspacioUsuario();
    void imprimirUsuario(std::string b);
    void eliminarMaterial(MaterialBibliografico *material);
    void eliminarUsuario(std::string b);
};


#endif
