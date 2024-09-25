//
// Created by nicol on 18-09-2024.
//

#ifndef REVISTA_H
#define REVISTA_H
#include "MaterialBibliografico.h"


class Revista : public MaterialBibliografico{
private:
    int numeroEdicion;
    int mesPublicacion;
public:
    Revista(const std::string &nombre, const std::string &isbn, const std::string &autor, bool estado,
            const int &numeroEdicion, int mesPublicacion);
};



#endif //REVISTA_H
