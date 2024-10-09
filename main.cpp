#include "sistema.h"

int main() {
    auto* sistema = new Sistema();
    sistema->cargarDatos();
    sistema->mostrarMenu();
    delete sistema;
    return 0;
}