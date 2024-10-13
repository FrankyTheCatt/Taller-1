#include "sistema.h"

int main() {
    Sistema* sistema = new Sistema();
    sistema->cargarDatos();
    sistema->mostrarMenu();
    return 0;
}