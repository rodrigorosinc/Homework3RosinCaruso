#include "crearJson.hpp"

CrearJson::CrearJson() {}

void CrearJson::abrir(std::ostream& os) {
    os << "{\n";
}
void CrearJson::cerrar(std::ostream& os) {
    os << "}\n";
}

void CrearJson::imprimir(std::ostream& os, std::string archivoNombre) {
    std::ifstream archivo(archivoNombre);  // abrimos el archivo JSON

    std::string linea;
    while (std::getline(archivo, linea)) {
        os << linea << '\n';  // imprimimos cada línea en el stream os (por ejemplo std::cout)
    }

    archivo.close();
}