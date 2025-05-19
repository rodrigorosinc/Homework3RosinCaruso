# include <iostream>
# include <fstream>
# include <string>
# include "procesar.hpp"
#pragma once

class CrearJson {
    public:
    CrearJson();
    void abrir(std::ostream& os);

    template<typename T>
    void asociar(std::ostream& os, ContenedorDatos<T> data, std::string nombre, bool last = false) {
        os << "  \"" << nombre << "\": ";
        data.procesar(os);
        if (!last) {
            os << ",\n";
        } else {
            os << "\n";
        }
    }
    
    void cerrar(std::ostream& os);
    void imprimir(std::ostream& os);
};

CrearJson::CrearJson() {}

void CrearJson::abrir(std::ostream& os) {
    os << "{\n";
}
void CrearJson::cerrar(std::ostream& os) {
    os << "}\n";
}

void CrearJson::imprimir(std::ostream& os) {
    std::ifstream archivo("data.json");  // abrimos el archivo JSON

    std::string linea;
    while (std::getline(archivo, linea)) {
        os << linea << '\n';  // imprimimos cada línea en el stream os (por ejemplo std::cout)
    }

    archivo.close();
}
