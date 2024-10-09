// sistema.cpp
#include "sistema.h"
#include "Usuario.h"
using namespace std;
MaterialBibliografico *biblioteca[100];
Usuario *listaUsuarios[100];
int numLibros = 0;
int numUsuarios = 0;

Sistema::Sistema() {
    numLibros = 0;
    numUsuarios = 0;
    for (int i = 0; i < 100; i++) {
        biblioteca[i] = nullptr;
        listaUsuarios[i] = nullptr;
    }
}

MaterialBibliografico *buscarMaterial() {
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

int toInt(const string & isbn) {
    int num;
    try{
        num = stoi(isbn);
        return num;
    }
    catch (const std::invalid_argument &e){
        return -1;
    }
}

void agregarMaterial() {
    if (buscarEspacio() == -1) {
        cout << "La biblioteca esta llena" << endl;
        return;
    }
    string nombre;
    string categoria;
    string isbn;
    string autor;
    string fecha;
    string numEdicion;
    string resumen;
    string mes;
    string tipo;
    cout << "Que desea agregar (Libro/Revista)" << endl;
    getline(cin, tipo);
    if (tipo == "Libro") {
        cout << "Ingrese el nombre del libro: ";
        getline(cin, nombre);

        cout << "Ingrese el autor del libro: ";
        getline(cin, autor);

        cout << "Ingrese el ISBN del libro: ";
        getline(cin, isbn);

        int isbnNum = toInt(isbn);
        if (isbnNum == -1) cout << "Isbn invalido" << endl;

        cout <<  "Ingrese la fecha de publicacion:";
        getline(cin, fecha);

        cout << "Ingrese el resumen del libro";
        getline(cin, resumen);

        int id = buscarEspacio();
        biblioteca[id] == new Libro(nombre, isbnNum, autor, resumen, fecha);
        cout << "El libro " << biblioteca[id]->getNombre() << " se agrego con exito" << endl;
    }
    else if (tipo == "Revista") {
        cout << "Ingrese el nombre de la revista: ";
        getline(cin, nombre);

        cout << "Ingrese el autor de la revista: ";
        getline(cin, autor);

        cout << "Ingrese el ISBN de la revista: ";
        getline(cin, isbn);

        int isbnNum = toInt(isbn);
        if (isbnNum == -1) cout << "Isbn invalido" << endl;

        cout <<  "Ingrese el numero de edicion: ";
        getline(cin, numEdicion);

        cout << "Ingrese el mes de publicacion: ";
        getline(cin, mes);
        int mesNum = toInt(mes);
        if (mesNum == -1) cout << "Mes invalido" << endl;

        int id = buscarEspacio();
        biblioteca[id] == new Revista(nombre, isbnNum, autor, numEdicion, mesNum);
        cout << "La revista " << biblioteca[id]->getNombre() << " se agrego con exito" << endl;
    }
    else {
        cout << "Elija solamente entre Libro y Revista. " << endl;
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

void mostrarMenu() {
    bool on = true;
    while (on) {
        std::string opcion;
        std::cout << "\nMenu biblioteca: \n"
                     "1- Agregar Material\n"
                     "2- Mostrar lista de material\n"
                     "3- Buscar material\n"
                     "4- Prestar y devolver material\n"
                     "5- Gestion de usuarios\n"
                     "6- Salir...\n";
        std::cout << "Seleccione su opcion -> ";
        std::getline(std::cin, opcion);
        switch (opcion) {
            case "1": {
                agregarMaterial();
            }
            case "2": {
                listarMateriales();
            }
            case "3": {
                buscarMaterial();
            }
            case "4": {
                prestarDevolver();
            }
            case "5": {
                gestionUsurios();
            }
            case "6": {
                std::cout << "Saliendo..." << std::endl;
                on = false;
            }
        }
    }
}

