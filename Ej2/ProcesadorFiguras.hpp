#pragma once
#include "FigurasGeometricas.hpp"

// Clase base
template<typename T>
class ProcesadorFigura {
    public: 
        double calcularArea(const T&) const {
            return 0.0;
        }
};


// Especializaciones
template<>
class ProcesadorFigura<Circulo> {
    public: 
        double calcularArea(const Circulo& figura) const {
            return 3.14159 * figura.getRadio() * figura.getRadio();
        }
};

template<>
class ProcesadorFigura<Elipse> {
    public: 
        double calcularArea(const Elipse& figura) const {
            return 3.14159 * figura.getSemiejeMayor() * figura.getSemiejeMenor();
        }
};

template<>
class ProcesadorFigura<Rectangulo> {
    public: 
        double calcularArea(const Rectangulo& figura) const {
            return figura.getAncho() * figura.getLargo();
        }
};

