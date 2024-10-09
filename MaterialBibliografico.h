// GG AYUDANTIA 1V9 MENTIRA TALLER 1 LOOOL GO WIN LOCO AL 7 ALTOKE
// Created by nicol y marti on 18-09-2024.
//

#ifndef MATERIALBIBLIOGRAFICO_H
#define MATERIALBIBLIOGRAFICO_H
#include <string>

using namespace std;

class MaterialBibliografico {
protected:
    string nombre;
    int isbn;
    string autor;

public:
    MaterialBibliografico(const string &nombre, const int &isbn, const string &autor);

    virtual void mostrarInfo();
    string getNombre();
    int getIsbn();
    string getAutor();
    void imprimirMaterial() const;
    virtual ~MaterialBibliografico() = default;
};

#endif //MATERIALBIBLIOGRAFICO_H
