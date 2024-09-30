// main.cpp
#include "sistema.h"
#include <iostream>
#include <string>
#include <stdexcept>

int leerInt(int ver) {
    std::string str;
    int x = 0;

    while (true) {
        std::cout << "\nIngrese una opcion: ";
        std::getline(std::cin, str);
        try {
            x = std::stoi(str);
            if (ver == 1) {
                if (x >= 1 && x <= 6) {
                    break;
                }
            }
            return x;

        }
        catch (std::invalid_argument& e) {
        }
        catch (std::out_of_range& e) {
        }
    }

    return x;
}


std::string leerString() {
    std::string str;
    std::getline(std::cin, str);
    return str;
}

DatosComunes leerDatosComunes() {
    DatosComunes datos;
    std::cout << "\nIngrese el nombre: ";
    datos.nombre = leerString();
    std::cout << "\nIngrese el ISBN: ";
    datos.isbn = leerString();
    std::cout << "\nIngrese el autor: ";
    datos.autor = leerString();
    return datos;
}

int imprimirMenu() {
    std::cout << "\nMenu biblioteca: \n"
                 "1- Agregar Material\n"
                 "2- Mostrar lista de material\n"
                 "3- Buscar material\n"
                 "4- Prestar y devolver material\n"
                 "5- Gestion de usuarios\n"
                 "6- Salir...\n";
    return leerInt(1);
}

void start() {
    int opcion;
    do {
        opcion = imprimirMenu();
        switch (opcion) {
            case 1: {
                if (buscarEspacio() != -1) {
                    std::cout << "1- Libro " << std::endl;
                    std::cout << "2- Revista" << std::endl;
                    int opcion1 = leerInt(0);
                    DatosComunes datos = leerDatosComunes();

                    if (opcion1 == 1) {
                        std::cout << "\nIngrese la fecha de publicacion: ";
                        std::string fechapublicacion = leerString();
                        std::cout << "\nIngrese el resumen: ";
                        std::string resumen = leerString();
                        agregarMaterial(datos.nombre, datos.isbn, datos.autor, fechapublicacion, resumen, 1);
                    } else if (opcion1 == 2) {
                        std::cout << "\nIngrese el numero de edicion: ";
                        std::string num_edicion = leerString();
                        std::cout << "\nIngrese el mes de publicacion: ";
                        std::string mes = leerString();
                        agregarMaterial(datos.nombre, datos.isbn, datos.autor, num_edicion, mes, 2);
                    }
                } else {
                    std::cout << "Biblioteca llena no es posible agregar mas... " << std::endl;
                }
                break;
            }
            case 2: {
                listarMateriales();
                break;
            }
            case 3: {
                std::cout << "1- Busqueda por autor" << std::endl;
                std::cout << "2- Busqueda por titulo" << std::endl;
                std::cout << "Ingrese una opcion -> " << std::endl;
                int opcion1 = leerInt(0);
                if (opcion1 == 1) {
                    std::cout << "Ingrese el autor: ";
                    std::string autor = leerString();
                    revisarMaterial(autor);
                }
                if (opcion1 == 2) {
                    std::cout << "Ingrese el titulo: ";
                    std::string titulo = leerString();
                    revisarMaterial(titulo);
                }
                break;
            }
            case 4: {
                std::cout << "1. Pedir material" << std::endl;
                std::cout << "2. Devolver material" << std::endl;
                std::cout << "Ingresa una opcion -> ";
                int opcion1 = leerInt(0);
                if (opcion1 == 1) {
                    std::cout << "\nIngrese el titulo : ";
                    std::string titulo = leerString();
                    std::cout << "\nIngrese el id de usuario: ";
                    std::string usuario = leerString();
                    pedirMaterial(titulo, usuario);

                }
            }
            case 5: {
                std::cout << "1- Crear usuario" << std::endl;
                std::cout << "2- Buscar usuario"<< std::endl;
                std::cout << "3- Eliminar usuario" << std::endl;
                int opcion1 = leerInt(0);
                if (opcion1 == 1) {
                    std::cout << "\nIngrese el nombre: ";
                    std::string nombre = leerString();
                    std::cout << "\nIngrese el id: ";
                    std::string id = leerString();
                    crearUsuario(nombre, id);
                } if (opcion == 2) {
                    std::cout << "\nIngrese el id del usuario: ";
                    std::string id = leerString();
                    imprimirUsuario(id);
                } if (opcion == 3) {
                    std::cout << "Ingrese el id del usuario: ";
                    std::string id = leerString();
                    eliminarUsuario(id);

                }

            }
        }
    }while(opcion != 6);
}

int main() {
    start();
    return 0;
}
