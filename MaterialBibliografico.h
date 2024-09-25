// GG AYUDANTIA 1V9 MENTIRA TALLER 1 LOOOL GO WIN LOCO AL 7 ALTOKE
// Created by nicol y marti on 18-09-2024.
//

#ifndef MATERIALBIBLIOGRAFICO_H
#define MATERIALBIBLIOGRAFICO_H
#include <string>


class MaterialBibliografico {
private:
    std::string nombre;
    std::string isbn;
    std::string autor;

public:
    MaterialBibliografico(const std::string &nombre, const std::string &isbn, const std::string &autor);
    std::string getNombre();
    std::string getIsbn();
    std::string getAutor();

    void mostrarInfo();

    void mostarInfo();
};



#endif //MATERIALBIBLIOGRAFICO_H
