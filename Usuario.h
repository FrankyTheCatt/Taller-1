#ifndef USUARIO_H
#define USUARIO_H
#include <string>


class MaterialBibliografico;

class Usuario {
private:
    std::string nombre;
    std::string id;
    MaterialBibliografico* biblioteca[5];
public:

    Usuario(const std::string &nombre, const std::string &id);
};



#endif //USUARIO_H
