#include <iostream>
#include "FigurasGeometricas.hpp"
#include "ProcesadorFiguras.hpp"

int main() {
    Punto p(1.0, 2.0);
    Circulo c(p, 5.0);
    Elipse e(p, 4.0, 2.0);
    Rectangulo r(p, 6.0, 3.0);

    std::cout << "Área del círculo: " << calcularArea(c) << std::endl;
    std::cout << "Área de la elipse: " << calcularArea(e) << std::endl;
    std::cout << "Área del rectángulo: " << calcularArea(r) << std::endl;
    std::cout << "Área de la figura no soportada: " << calcularArea(FiguraNoSoportada()) << std::endl;
    return 0;
}
