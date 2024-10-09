#ifndef LIBRO_H
#define LIBRO_H

#include "MaterialBibliografico.h"
using namespace std;

class Libro : public MaterialBibliografico {
private:
    string resumen;
    string fechapublicacion;

public:
    Libro(const string &nombre, const int &isbn, const string &autor, const string &resumen, const string &fechapublicacion);
    void mostrarInfo() override;
};

#endif // LIBRO_H
