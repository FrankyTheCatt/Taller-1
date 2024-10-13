// sistema.h
#ifndef SISTEMA_H
#define SISTEMA_H

#include <iostream>
#include "Libro.h"
#include "MaterialBibliografico.h"
#include "Revista.h"
#include "Usuario.h"
using namespace std;
class Sistema {
private:
    MaterialBibliografico* biblioteca[100];
    int numLibros;

    Usuario* usuarios[100];
    int numUsuarios;
    public:
    Sistema();

    void buscarMaterial();

    MaterialBibliografico* busquedaMaterial(string nombre);
    ~Sistema();

    void LeerUsuario(const string & linea);

    void LeerMateriales(const string & string);

    void cargarDatos();
    void agregarMaterial();
    void prestarDevolver();
    void gestionUsurios();
    void gestionUsuarios();
    void mostrarMenu();
    void listarMateriales();
    int buscarEspacio();
    int buscarEspacioUsuario();
    void revisarMaterial();
    MaterialBibliografico *buscarMaterial(std::string b);
    void pedirMaterial(std::string titulo, std::string usuario);
    void crearUsuario();
    static Usuario *buscarUsuario(std::string id);
    void imprimirUsuario(std::string b);
    void eliminarMaterial(MaterialBibliografico *material);
    void eliminarUsuario(std::string b);
};


#endif
