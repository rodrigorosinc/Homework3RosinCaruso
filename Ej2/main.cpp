#include <iostream>
#include "FigurasGeometricas.hpp"
#include "ProcesadorFiguras.hpp"

int main()  { 
    Punto p(1.0, 2.0);
    Circulo c(p, 5.0);
    Elipse e(p, 4.0, 2.0);
    Rectangulo r(p, 6.0, 3.0);
    FiguraNoSoportada fn;

    ProcesadorFigura<Punto> procesadorPunto;
    ProcesadorFigura<Circulo> procesadorCirculo;
    ProcesadorFigura<Elipse> procesadorElipse;
    ProcesadorFigura<Rectangulo> procesadorRectangulo;
    ProcesadorFigura<FiguraNoSoportada> procesadorNoSoportada;

    std::cout << "Área del punto: " << procesadorPunto.calcularArea(p) << std::endl;
    std::cout << "Área del círculo: " << procesadorCirculo.calcularArea(c) << std::endl;
    std::cout << "Área de la elipse: " << procesadorElipse.calcularArea(e) << std::endl;
    std::cout << "Área del rectángulo: " << procesadorRectangulo.calcularArea(r) << std::endl;
    std::cout << "Área figura no soportada: " << procesadorNoSoportada.calcularArea(fn) << std::endl;

    return 0;
}

