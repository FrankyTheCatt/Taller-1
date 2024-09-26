#ifndef LIBRO_H
#define LIBRO_H

#include "MaterialBibliografico.h"

class Libro : public MaterialBibliografico {
private:
    std::string resumen;
    std::string fechapublicacion;

public:
    Libro(const std::string &nombre, const std::string &isbn, const std::string &autor, const std::string &resumen,
          int diff, const std::string &fechapublicacion);
    void mostrarInfo() override;
};

#endif // LIBRO_H
