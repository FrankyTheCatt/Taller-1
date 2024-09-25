// sistema.cpp
#include "sistema.h"



MaterialBibliografico *buscarLibro(const std::string b, int a, MaterialBibliografico **c) {
    for (int i = 0; i < a; i++) {
        if (b == c[i]->getAutor()) {
            return c[i];
        } else if (b == c[i]->getNombre()) {
            return c[i];
        }
    }
    return nullptr;
}

MaterialBibliografico *biblioteca[100];

int buscarEspacio() {
    for (int i = 0; i < 100; i++) {
        if (biblioteca[i] == nullptr) {
            return i;
        }
    }
    return -1;
}

void agregarMaterial(const std::string &nombre, const std::string &isbn, const std::string &autor, const std::string arg1, const std::string&arg2, int diff){
    switch (diff) {
        case 1: {
            Libro *libro = new Libro(nombre, isbn, autor, arg1, arg2);
            biblioteca[buscarEspacio()] = libro;
            std::cout << "El libro "<< libro->getNombre() << " se agrego correctamente" << std::endl;
            break;
        }
        case 2: {
            Revista *revista = new Revista(nombre, isbn, autor, arg1, arg2);
            biblioteca[buscarEspacio()] = revista;
            std::cout << "La revista "<< revista->getNombre() << " se agrego correctamente" << std::endl;
            break;
        }
    }
}

// Implementación del main
void correr(); {


            case 2: {
                std::cout << "Biblioteca:" << std::endl;
                for (int i = 0; i < numMateriales; i++) {
                    std::cout << i + 1 << "- " << biblioteca[i]->getNombre() << std::endl;
                }
                break;
            }

            case 3: {
                std::cout << "1- Buscar por Autor" << std::endl;
                std::cout << "2- Buscar por Titulo" << std::endl;
                std::cout << "Ingresa una opcion: ";
                int opcion1 = leerInt();

                if (opcion1 == 1) {
                    std::cout << "Ingresa el nombre del autor: ";
                    std::string nombre = leerString();
                    MaterialBibliografico *a = buscarLibro(nombre, numMateriales, biblioteca);
                    a->mostrarInfo();
                } else if (opcion1 == 2) {
                    std::cout << "Ingresa el titulo: ";
                    std::string titulo = leerString();
                    MaterialBibliografico *b = buscarLibro(titulo, numMateriales, biblioteca);
                    b->mostrarInfo();
                }
                break;
            }

            case 4: {
                std::cout << "1. Pedir Material" << std::endl;
                std::cout << "2. Devolver Material" << std::endl;
                std::cout << "Ingresa una opcion: ";
                int opcion4 = leerInt();

                if (opcion4 == 1) {
                    std::cout << "Ingrese el titulo: ";
                    std::string titulo = leerString();
                    MaterialBibliografico *a = buscarLibro(titulo, numMateriales, biblioteca); {
                        if (a->getEstado()) {
                            std::cout << "El material no está disponible" << std::endl;
                        } else {
                            a->setEstado(true);
                            std::cout << "Material prestado con éxito!" << std::endl;
                        }
                        break;
                    }
                } else if (opcion4 == 2) {
                    std::cout << "Ingrese el titulo: ";
                    std::string titulo = leerString();
                    for (int i = 0; i < numMateriales; i++) {
                        if (titulo == biblioteca[i]->getNombre()) {
                            if (!biblioteca[i]->getEstado()) {
                                std::cout << "El material no ha sido prestado." << std::endl;
                            } else {
                                biblioteca[i]->setEstado(false);
                                std::cout << "Material devuelto con éxito!" << std::endl;
                            }
                            break;
                        }
                    }
                }
                break;
            }

            case 5: {
                std::cout << "Funcionalidad de gestión de usuarios pendiente..." << std::endl;
                break;
            }

            case 6: {
                std::cout << "Saliendo..." << std::endl;
                break;
            }

            default: {
                std::cout << "Opción incorrecta, por favor ingrese otra opción.\n";
                break;
            }
        }
    } while (opcion != 6);
}
