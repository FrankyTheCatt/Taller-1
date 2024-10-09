#ifndef REVISTA_H
#define REVISTA_H

#include "MaterialBibliografico.h"
using namespace std;

class Revista : public MaterialBibliografico {
private:
    string numeroEdicion;
    int mesPublicacion;

public:
    Revista(const string &nombre, const int &isbn, const string &autor, const string &numeroEdicion, const int &mesPublicacion);


    void mostrarInfo() override;
};

#endif //REVISTA_H
