// Libro.h
#ifndef LIBRO_H
#define LIBRO_H

#include "MaterialBibliografico.h"

class Libro : public MaterialBibliografico {
private:
    std::string resumen;
    std::string fechapublicacion;

public:
    // Constructor de la clase derivada
    Libro(const std::string &nombre, const std::string &isbn, const std::string &autor,
          const std::string &resumen, const std::string &fechapublicacion);
    void mostarInfo();
};

#endif // LIBRO_H
