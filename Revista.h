//
// Created by nicol on 18-09-2024.
//

#ifndef REVISTA_H
#define REVISTA_H
#include "MaterialBibliografico.h"


class Revista : public MaterialBibliografico{
private:
    std::string numeroEdicion;
    std::string mesPublicacion;
public:
    Revista(const std::string &nombre, const std::string &isbn, const std::string &autor,
            const std::string &numeroEdicion, std::string mesPublicacion);
};



#endif //REVISTA_H
