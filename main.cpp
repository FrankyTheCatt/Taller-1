#include <iostream>
#include "Libro.h"
#include "MaterialBibliografico.h"
#include "Revista.h"
using namespace std;

int leerInt() {
    int x;
    cin >> x;
    cin.ignore();
    return x;
}

struct DatosComunes {
    std::string nombre;
    std::string isbn;
    std::string autor;
};

int imprimirMenu() {
    cout << "\nMenu biblioteca: \n"
            "1- Agregar Material\n"
            "2- Mostrar lista de material\n"
            "3- Buscar material\n"
            "4- Prestar y devolver material\n"
            "5- Gestion de usuarios\n"
            "6- Salir...\n";
    cout << "Seleccione su opcion -> ";
    return leerInt();
}

string leerString() {
    string str;
    getline(cin, str);
    return str;
}

DatosComunes leerDatosComunes() {
    DatosComunes datos;
    cout << "\nIngrese el nombre: ";
    datos.nombre = leerString();
    cout << "\nIngrese el ISBN: ";
    datos.isbn = leerString();
    cout << "\nIngrese el autor: ";
    datos.autor = leerString();
    return datos;
}

bool revisarMaterial(int a) {
    return a < 100;
}

MaterialBibliografico *buscarLibro(const string b, int a, MaterialBibliografico **c) {
    for (int i = 0; i < a; i++) {
        if (b == c[i]->getAutor()) {
            return c[i];
        } else if (b == c[i]->getNombre()) {
            return c[i];
        }
    }
    return nullptr;
}

int main() {
    MaterialBibliografico *biblioteca[100];
    int numMateriales = 0;
    int opcion;

    do {
        opcion = imprimirMenu();
        switch (opcion) {
            case 1: {
                if (revisarMaterial(numMateriales)) {
                    cout << "1- Libro " << endl;
                    cout << "2- Revista" << endl;
                    cout << "Ingresa una opcion: ";
                    int opcion1 = leerInt();
                    DatosComunes datos = leerDatosComunes();

                    if (opcion1 == 1) {
                        cout << "\nIngrese la fecha de publicacion: ";
                        string fechapublicacion = leerString();
                        cout << "\nIngrese el resumen: ";
                        string resumen = leerString();

                        Libro *libro = new Libro(datos.nombre, datos.isbn, datos.autor, false, fechapublicacion,
                                                 resumen);
                        biblioteca[numMateriales++] = libro;
                        cout << "Libro ingresado correctamente!!\n" << endl;
                    } else if (opcion1 == 2) {
                        cout << "\nIngrese el numero de edicion: ";
                        int num_edicion = leerInt();
                        cout << "\nIngrese el mes de publicacion: ";
                        int mes = leerInt();

                        Revista *revista = new Revista(datos.nombre, datos.isbn, datos.autor, false, num_edicion, mes);
                        biblioteca[numMateriales++] = revista;
                        cout << "Revista ingresada correctamente!!\n" << endl;
                    }
                }
                break;
            }

            case 2: {
                cout << "Biblioteca:" << endl;
                for (int i = 0; i < numMateriales; i++) {
                    cout << i + 1 << "- " << biblioteca[i]->getNombre() << endl;
                }
                break;
            }

            case 3: {
                cout << "1- Buscar por Autor" << endl;
                cout << "2- Buscar por Titulo" << endl;
                cout << "Ingresa una opcion: ";
                int opcion1 = leerInt();

                if (opcion1 == 1) {
                    cout << "Ingresa el nombre del autor: ";
                    string nombre = leerString();
                    MaterialBibliografico *a = buscarLibro(nombre, numMateriales, biblioteca);
                    a->mostrarInfo();
                } else if (opcion1 == 2) {
                    cout << "Ingresa el titulo: ";
                    string titulo = leerString();
                    MaterialBibliografico *b = buscarLibro(titulo, numMateriales, biblioteca);
                    b->mostrarInfo();
                }
                break;
            }

            case 4: {
                cout << "1. Pedir Material" << endl;
                cout << "2. Devolver Material" << endl;
                cout << "Ingresa una opcion: ";
                int opcion4 = leerInt();

                if (opcion4 == 1) {
                    cout << "Ingrese el titulo: ";
                    string titulo = leerString();
                    MaterialBibliografico *a = buscarLibro(titulo, numMateriales, biblioteca); {
                        if (a->getEstado()) {
                            cout << "El material no está disponible" << endl;
                        } else {
                            a->setEstado(true);
                            cout << "Material prestado con éxito!" << endl;
                        }
                        break;
                    }
                } else if (opcion4 == 2) {
                    cout << "Ingrese el titulo: ";
                    string titulo = leerString();
                    for (int i = 0; i < numMateriales; i++) {
                        if (titulo == biblioteca[i]->getNombre()) {
                            if (!biblioteca[i]->getEstado()) {
                                cout << "El material no ha sido prestado." << endl;
                            } else {
                                biblioteca[i]->setEstado(false);
                                cout << "Material devuelto con éxito!" << endl;
                            }
                            break;
                        }
                    }
                }
                break;
            }

            case 5: {
                cout << "Funcionalidad de gestión de usuarios pendiente..." << endl;
                break;
            }

            case 6: {
                cout << "Saliendo..." << endl;
                break;
            }

            default: {
                cout << "Opción incorrecta, por favor ingrese otra opción.\n";
                break;
            }
        }
    } while (opcion != 6);

    return 0;
}
