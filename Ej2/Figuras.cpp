#include "FigurasGeometricas.hpp"
#include "ProcesadorFiguras.hpp"    

Punto::Punto(double x, double y) : x(x), y(y) {}
Punto::~Punto() {}
void Punto::setX(double x_) { 
    x = x_;
}
void Punto::setY(double y_) { 
    y = y_;
}
double Punto::getX() const { 
    return x; 
}
double Punto::getY() const { 
    return y; 
}

// Circulo

Circulo::Circulo(Punto centro, double radio) : centro(centro), radio(radio) {}
Circulo::~Circulo() {}
void Circulo::setCentro(Punto centro_) { 
    centro = centro_; 
}
void Circulo::setRadio(double radio_) { 
    radio = radio_; 
}
Punto Circulo::getCentro() const { 
    return centro; 
}
double Circulo::getRadio() const { 
    return radio; 
}

// Elipse

Elipse::Elipse(Punto centro, double semiejeMayor, double semiejeMenor) 
    : centro(centro), semiejeMayor(semiejeMayor), semiejeMenor(semiejeMenor) {}
Elipse::~Elipse() {}
void Elipse::setCentro(Punto centro_) { 
    centro = centro_; 
}
void Elipse::setSemiejeMayor(double semiejeMayor_) { 
    semiejeMayor = semiejeMayor_; 
}
void Elipse::setSemiejeMenor(double semiejeMenor_) { 
    semiejeMenor = semiejeMenor_; 
}
Punto Elipse::getCentro() const { 
    return centro; 
}
double Elipse::getSemiejeMayor() const { 
    return semiejeMayor; 
}
double Elipse::getSemiejeMenor() const { 
    return semiejeMenor; 
}

// Rectangulo

Rectangulo::Rectangulo(Punto verticeInferiorIzquierdo, double ancho, double largo) 
    : verticeInferiorIzquierdo(verticeInferiorIzquierdo), ancho(ancho), largo(largo) {}
Rectangulo::~Rectangulo() {}
void Rectangulo::setVerticeInferiorIzquierdo(Punto verticeInferiorIzquierdo_) { 
    verticeInferiorIzquierdo = verticeInferiorIzquierdo_; 
}
void Rectangulo::setAncho(double ancho_) { 
    ancho = ancho_; 
}
void Rectangulo::setLargo(double largo_) { 
    largo = largo_; 
}
Punto Rectangulo::getVerticeInferiorIzquierdo() const { 
    return verticeInferiorIzquierdo; 
}
double Rectangulo::getAncho() const { 
    return ancho; 
}
double Rectangulo::getLargo() const { 
    return largo; 
}

// FiguraNoSoportada

FiguraNoSoportada::FiguraNoSoportada() : dummyParameter(0) {}
FiguraNoSoportada::~FiguraNoSoportada() {}
