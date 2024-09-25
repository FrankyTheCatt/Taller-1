// main.cpp
#include "sistema.h"


int leerInt() {
    int x;
    std::cin >> x;
    std::cin.ignore();
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
    std::cout << "Seleccione su opcion -> ";
    return leerInt();
}

int main() {
    correr();
    int opcion;
    do {
        opcion = imprimirMenu();
        switch (opcion) {
            case 1: {
                if (buscarEspacio()!= -1) {
                    std::cout << "1- Libro " << std::endl;
                    std::cout << "2- Revista" << std::endl;
                    std::cout << "Ingresa una opcion: ";
                    int opcion1 = leerInt();
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
                        std::string  mes = leerString();
                        agregarMaterial(datos.nombre, datos.isbn, datos.autor,num_edicion, mes, 2);
                    }
                }
                else {
                    std::cout << "Biblioteca llena no es posible agregar mas... " << std::endl;
                }
                break;
            }
            case 2: {

            }

    return 0;
}
