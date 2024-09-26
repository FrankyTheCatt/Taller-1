#ifndef REVISTA_H
#define REVISTA_H

#include "MaterialBibliografico.h"

class Revista : public MaterialBibliografico {
private:
    std::string numeroEdicion;
    std::string mesPublicacion;

public:
    Revista(const std::string &nombre, const std::string &isbn, const std::string &autor, int diff, const std::string &numeroEdicion, const std::string &mesPublicacion);
    void mostrarInfo() override;
};

#endif //REVISTA_H
