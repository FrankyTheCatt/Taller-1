// sistema.cpp
#include <algorithm>

#include "sistema.h"
#include "Usuario.h"
#include <cctype>
#include <fstream>
#include <ranges>
#include <sstream>
#include <vector>
using namespace std;
MaterialBibliografico *biblioteca[100];
Usuario *listaUsuarios[100];
int numLibros = 0;
int numUsuarios = 0;

Sistema::Sistema() {
    numLibros = 0;
    numUsuarios = 0;
    for (int i = 0; i < 100; i++) {
        listaUsuarios[i] = nullptr;
        biblioteca[i] = nullptr;
    }}
MaterialBibliografico* Sistema::busquedaMaterial(std::string nombre) {
    for (int i = 0; i < 100; i++) {
        if (biblioteca[i] != nullptr && (biblioteca[i]->getNombre() == nombre || biblioteca[i]->getAutor() == nombre)) {
            return biblioteca[i];
        }
    }
    return nullptr;
}
void Sistema::buscarMaterial() {
    string opcion;
    string busqueda;
    bool on;
    cout << "1- Nombre" << endl;
    cout << "2- Autor" << endl;
    cout << "Ingrese la opcion: ";
    getline(cin, opcion);
    while (opcion != "1" && opcion != "2") {
        cout << "Opcion invalida reingrese: ";
        getline(cin, opcion);
    }
    cout << "Ingrese el termino de busqueda: ";
    getline(cin, busqueda);
    MaterialBibliografico *b = busquedaMaterial(busqueda);
    if (b != nullptr) {
        b->mostrarInfo();
    } else {
        cout << "Material/Autor no encontrado." << endl;
    }
}
void eliminarMaterial(MaterialBibliografico *material) {
    for (int i = 0; i < 100; i++) {
        if (biblioteca[i] == material) {
            delete material;
        }
    }
}
int Sistema::buscarEspacio() {
    for (int i = 0; i < 100; i++) {
        if (biblioteca[i] == nullptr) {
            return i;
        }
    }
    return -1;
}
int toInt(const string &isbn) {
    try {
        return stoi(isbn);
    } catch (const invalid_argument &e) {
        return -1;
    }
}
void Sistema::agregarMaterial() {
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
    transform(tipo.begin(), tipo.end(), tipo.begin(), ::tolower);
    while (tipo != "libro" && tipo != "revista") {
        cout << "Reingrese la opcion: ";
        getline(cin, tipo);
        transform(tipo.begin(), tipo.end(), tipo.begin(), ::tolower);
    }
    if (tipo == "libro") {
        cout << "Ingrese el nombre del libro: ";
        getline(cin, nombre);

        cout << "Ingrese el autor del libro: ";
        getline(cin, autor);

        cout << "Ingrese el ISBN del libro: ";
        getline(cin, isbn);

        int isbnNum = toInt(isbn);
        while (isbnNum == -1) {
            cout << "Ingrese un ISBN valido: ";
            getline(cin, isbn);
            isbnNum = toInt(isbn);
        }

        cout <<  "Ingrese la fecha de publicacion: ";
        getline(cin, fecha);

        cout << "Ingrese el resumen del libro: ";
        getline(cin, resumen);

        int id = buscarEspacio();

        biblioteca[id] = new Libro(nombre, isbnNum, autor, resumen, fecha);

        cout << "El libro " << biblioteca[id]->getNombre() << " se agrego con exito" << endl;
    }
    else if (tipo == "revista") {
        cout << "Ingrese el nombre de la revista: ";
        getline(cin, nombre);

        cout << "Ingrese el autor de la revista: ";
        getline(cin, autor);

        cout << "Ingrese el ISBN de la revista: ";
        getline(cin, isbn);

        int isbnNum = toInt(isbn);
        while (isbnNum == -1) {
            cout << "Ingrese un ISBN valido: ";
            getline(cin, isbn);
            isbnNum = toInt(isbn);
        }

        cout <<  "Ingrese el numero de edicion: ";
        getline(cin, numEdicion);

        cout << "Ingrese el mes de publicacion: ";
        getline(cin, mes);
        int mesNum = toInt(mes);
        if (mesNum == -1) {
            cout << "Ingrese un mes valido: ";
            getline(cin, mes);
            mesNum = toInt(mes);
        }

        int id = buscarEspacio();
        biblioteca[id] = new Revista(nombre, isbnNum, autor, numEdicion, mesNum);
        cout << "La revista " << biblioteca[id]->getNombre() << " se agrego con exito" << endl;
    }
    else {
        cout << "Elija solamente entre Libro y Revista. " << endl;
    }
}
void Sistema::listarMateriales() {
    for (int i = 0; i < 100; i++) {
        if (biblioteca[i] == nullptr) {
            continue;
        } else {
            biblioteca[i]->mostrarInfo();
        }
    }
}
Usuario* Sistema::buscarUsuario(string id) {
    for (int i = 0; i < 100; i++) {
        if (listaUsuarios[i] != nullptr && listaUsuarios[i]->getId() == id) {
            return listaUsuarios[i];
        }
    }
    return nullptr;
}
int Sistema::buscarEspacioUsuario() {
    for (int i = 0; i < 100; i++) {
        if (listaUsuarios[i] == nullptr) {
            return i;
        }
    }
    return -1;
}
void Sistema::crearUsuario() {
    string nombre;
    string id;
    int a;
    cout << "Ingrese el nombre del usuario: ";
    getline(cin, nombre);
    cout << "Ingrese el id: ";
    getline(cin, id);
    Usuario *usuario = new Usuario(nombre, id);
    a = buscarEspacioUsuario();
    listaUsuarios[a] = usuario;
    std::cout << "Usuario creado correctamente... " << std::endl;
}
void Sistema::imprimirUsuario(std:: string b) {
    Usuario *usuario = buscarUsuario(b);
    if (usuario == nullptr) {
        cout << "Usuario no existe" << endl;
    }
    else {
        usuario->mostrarInfo();
    }

}
void Sistema::prestarDevolver() {
    string opcion;
    string nombre;
    string usuario;
    int espacio;
    cout << "1- Devolver: " << endl;
    cout << "2- Prestar: " << endl;
    cout << "Que quieres hacer: ";
    getline(cin, opcion);
    if (opcion == "1") {
        cout << "Ingrese el nombre del material a devolver: ";
        getline(cin, nombre);
        cout << "Ingrese el id del usuario: ";
        getline(cin, usuario);
        Usuario* u = buscarUsuario(usuario);
        if (u == nullptr) {
            cout << "Usuario no encontrado" << endl;
        }
        else  {
            MaterialBibliografico* m = u->buscarMaterialUser(nombre);
            if (m == nullptr) {
                cout << "Material no encontrado" << endl;
            }
            else {
                espacio = buscarEspacio();
                biblioteca[espacio] = m;
                cout << "El material " << m->getNombre() << " se devolvio con exito" << endl;
            }
        }
    }
    else if (opcion == "2") {
        cout << "Ingrese el nombre del material a pedir: ";
        getline(cin, nombre);
        cout << "Ingrese el id del usuario: ";
        getline(cin, usuario);
        Usuario* u = buscarUsuario(usuario);
        if (u == nullptr) {
            cout << "Usuario no encontrado" << endl;
        }
        else {
            MaterialBibliografico* m = Sistema::busquedaMaterial(nombre);

            if (m == nullptr) {
                cout << "Material no encontrado" << endl;
            }
            else {
                u->prestarMaterial(m);
                for (int i=0; i < 100; i++) {
                    if (biblioteca[i] == m) {
                        biblioteca[i] = nullptr;
                    }
                }
                cout << "El material " << m->getNombre() << " se presto con exito" << endl;
            }
        }
    }
}
void Sistema::eliminarUsuario(string b) {
    for (int i = 0; i < 100; i++) {
        if (listaUsuarios[i] != nullptr && listaUsuarios[i]->getId() == b) {
            listaUsuarios[i] = nullptr;
            delete listaUsuarios[i];
            std::cout << "Usuario eliminado correctamente...";
        }
    }
}
void Sistema::gestionUsuarios() {
    string opcion1;
    string id;
    cout << "1. Crear usuario " << endl;
    cout << "2. Buscar usuario " << endl;
    cout << "3. Eliminar usuario "<< endl;
    cout << "Ingrese una opcion: ";
    getline(cin, opcion1);
    while (opcion1 != "1" && opcion1 != "2" && opcion1 != "3") {
        cout << "Ingrese una opcion valida: ";
        getline(cin, opcion1);
    }
    if (opcion1 == "1") {
        crearUsuario();
    } else if (opcion1 == "2") {
        cout << "Ingrese el id del usuario: ";
        getline(cin, id);
        imprimirUsuario(id);
    } else if (opcion1 == "3") {
        cout << "Ingrese el id del usuario: ";
        getline(cin, id);
        eliminarUsuario(id);
    }
}
void Sistema::mostrarMenu() {
    bool on = true;
    while (on) {
        string opcion;
        cout << "\nMenu biblioteca: \n"
                     "1- Agregar Material\n"
                     "2- Mostrar lista de material\n"
                     "3- Buscar material\n"
                     "4- Prestar y devolver material\n"
                     "5- Gestion de usuarios\n"
                     "6- Salir...\n";
        cout << "Seleccione su opcion: ";
        getline(cin, opcion);
        if (opcion == "1") {
            agregarMaterial();
        }
        else if (opcion == "2") {
            listarMateriales();
        }
        else if (opcion == "3") {
            buscarMaterial();
        }
        else if (opcion == "4") {
            prestarDevolver();
        }
        else if (opcion == "5") {
            gestionUsuarios();
        }
        else if (opcion == "6") {
            cout << "Saliendo... " << endl;
            on = false;
        }
        else {
            cout << "Opcion no valida." << endl;
        }
    }
}

vector<string> split(const string &str, char delimiter)
{
    vector<std::string> splits;
    string parte;
    stringstream ss(str);

    while (std::getline(ss, parte, delimiter))
    {
        splits.push_back(parte);
    }

    return splits;
}
void Sistema::LeerUsuario(const string &linea) {
    vector<string> splits = split(linea, '-');
    int id1;
    if (splits.size() == 2) {
        string nombre = splits[0];
        string id = splits[1];
        id1 = toInt(id);
        if (buscarEspacioUsuario() != -1) {
            Usuario *usuario = new Usuario(nombre, id);
            listaUsuarios[buscarEspacioUsuario()] = usuario;
            cout << "El usuario " << usuario->getNombre() << " se agrego con exito" << endl;
        }
        else {
            cout << "Lista de usuarios llena..." << endl;
        }
    }
    else {
        cout << "Linea sin suficientes datos..." << endl;
    }
}

void Sistema::LeerMateriales(const string &linea) {
    vector<string> splits = split(linea, '-');
    int id1;
    if (buscarEspacio() != -1) {
    if (splits.size() >= 6) {
        string tipo = splits[0];
        string nombre = splits[1];
        int isbn = toInt(splits[2]);
        string autor = splits[3];
        transform(tipo.begin(), tipo.end(), tipo.begin(), ::tolower);
        if (tipo == "libro") {
            string resumen = splits[4];
            string fechapublicacion = splits[5];
            Libro* libro = new Libro(nombre, isbn, autor, resumen, fechapublicacion);
            biblioteca[buscarEspacio()] = libro;
            cout << "El Libro " << libro->getNombre() << " se agrego con exito" << endl;
        }
        else if (tipo == "revista") {
            string numEdicion = splits[4];
            int mesPublicacion = toInt(splits[5]);
            Revista* revista = new Revista(nombre, isbn, autor, numEdicion, mesPublicacion);
            biblioteca[buscarEspacio()] = revista;
            cout << "La Revista " << revista->getNombre() << " se agrego con exito" << endl;
        }
        else {
            cout << "Tipo no valido" << endl;
        }
    }
        else {
            cout << "La linea " << linea << " no es valida" << endl;
        }
    }
    else {
        cout << "Lista de materiales llena..." << endl;
    }
}

void Sistema::cargarDatos(){
    ifstream usuarios("usuarios.txt");
    string linea;

    if (!usuarios)
    {
        cout << "El archivo de usuarios no existe" << endl;
    }

    while (getline(usuarios, linea))
    {
        LeerUsuario(linea);
    }
    usuarios.close();

    ifstream materiales("materiales.txt");
    if (!materiales)
    {
        cout << "El archivo de materiales no existe" << endl;
    }

    string linea1;
    while (getline(materiales, linea1))
    {
        LeerMateriales(linea1);
    }
    materiales.close();
}

Sistema::~Sistema() {
        for (int i = 0; i < 100; i++) {
            delete biblioteca[i];
            delete listaUsuarios[i];
        }
    }




