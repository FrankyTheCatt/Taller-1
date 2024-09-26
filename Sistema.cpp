// sistema.cpp
#include "sistema.h"
#include "Usuario.h"
MaterialBibliografico *biblioteca[100];
Usuario *listaUsuarios[100];

MaterialBibliografico *buscarMaterial(std::string b) {
    for (int i = 0; i < 100; i++) {
        if (b == biblioteca[i]->getAutor()) {
            return biblioteca[i];
        }
        else if (b == biblioteca[i]->getNombre()) {
            return biblioteca[i];
        }
    }
    return nullptr;
}

void revisarMaterial(std::string b) {
    MaterialBibliografico *a = buscarMaterial(b);
    a->mostrarInfo();
}

void eliminarMaterial(MaterialBibliografico *material) {
    for (int i = 0; i < 100; i++) {
        if (biblioteca[i] == material) {
            delete material;
        }
    }
}

int buscarEspacio() {
    for (int i = 0; i < 100; i++) {
        if (biblioteca[i] == nullptr) {
            return i;
        }
    }
    return -1;
}

int buscarEspacioUsuario() {
    for (int i = 0; i < 100; i++) {
        if (listaUsuarios[i] == nullptr) {
            return i;
        }
    }
    return -1;
}

void agregarMaterial(const std::string &nombre, const std::string &isbn, const std::string &autor, const std::string arg1, const std::string&arg2, int diff){
    switch (diff) {
        case 1: {
            Libro *libro = new Libro(nombre, isbn, autor, arg1,1, arg2);
            biblioteca[buscarEspacio()] = libro;
            std::cout << "El libro "<< libro->getNombre() << " se agrego correctamente" << std::endl;
            break;
        }
        case 2: {
            Revista *revista = new Revista(nombre, isbn, autor,2, arg1, arg2);
            biblioteca[buscarEspacio()] = revista;
            std::cout << "La revista "<< revista->getNombre() << " se agrego correctamente" << std::endl;
            break;
        }
    }
}

void listarMateriales() {
    for (int i = 0; i < 100; i++) {
        if (biblioteca[i] == nullptr) {
            continue;
        } else {
            biblioteca[i]->mostrarInfo();
        }
    }
}

Usuario* buscarUsuario(std::string id) {
    for (int i = 0; i < 100; i++) {
        if (listaUsuarios[i]->getId() == id) {
            return listaUsuarios[i];
        }
    }
    return nullptr;
}

void pedirMaterial(std::string titulo, std::string usuario) {
    Usuario *u = buscarUsuario(usuario);
    MaterialBibliografico *material = buscarMaterial(titulo);
    u->prestarMaterial(material);
    eliminarMaterial(material);
    std::cout << "Material pedido: " << material->getNombre() << " con exito" << std::endl;
    }

void crearUsuario(const std::string &nombre, const std::string &id) {
    Usuario *usuario = new Usuario(nombre, id);
    listaUsuarios[buscarEspacioUsuario()] = usuario;
    std::cout << "Usuario creado correctamente... "<< std::endl;
    }
void devolverMaterial(std::string &titulo,std::string &id) {
    Usuario *usuario = buscarUsuario(id);
    MaterialBibliografico material = *usuario->devolverMaterial(titulo);

}

void imprimirUsuario(std:: string b) {
    Usuario *usuario = buscarUsuario(b);
    usuario->mostrarInfo();
}

void eliminarUsuario(std:: string b) {
    Usuario *usuario = buscarUsuario(b);
    for (int i = 0; i < 100; i++) {
        if (listaUsuarios[i]->getId() == b) {
            delete listaUsuarios[i];
            std::cout << "Usuario eliminado correctamente...";
        }
    }
}

