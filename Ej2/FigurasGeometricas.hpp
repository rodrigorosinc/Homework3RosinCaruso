#include <iostream>
#pragma once

class Punto {
    private:
        double x;
        double y;
    public:
        // Constructor
        Punto(double x = 0, double y = 0);
        ~Punto();
        // Setters
        void setX(double x);
        void setY(double y);
        // Getters
        double getX() const;
        double getY() const;
};

class Circulo {
    private:
        Punto centro;
        double radio;
    public:
        // Constructor
        Circulo(Punto centro = Punto(), double radio = 0);
        ~Circulo();
        // Setters
        void setCentro(Punto centro);
        void setRadio(double radio);
        // Getters
        Punto getCentro() const;
        double getRadio() const;
};

class Elipse {
    private:
        Punto centro;
        double semiejeMayor;
        double semiejeMenor;
    public:
        // Constructor
        Elipse(Punto centro = Punto(), double semiejeMayor = 0, double semiejeMenor = 0);
        ~Elipse();
        // Setters
        void setCentro(Punto centro);
        void setSemiejeMayor(double semiejeMayor);
        void setSemiejeMenor(double semiejeMenor);
        // Getters
        Punto getCentro() const;
        double getSemiejeMayor() const;
        double getSemiejeMenor() const;
};

class Rectangulo {
    private:
        Punto verticeInferiorIzquierdo;
        double ancho;
        double largo;
    public:
        // Constructor
        Rectangulo(Punto verticeInferiorIzquierdo = Punto(), double ancho = 0, double largo = 0);
        ~Rectangulo();
        // Setters
        void setVerticeInferiorIzquierdo(Punto verticeInferiorIzquierdo);
        void setAncho(double ancho);
        void setLargo(double largo);
        // Getters
        Punto getVerticeInferiorIzquierdo() const;
        double getAncho() const;
        double getLargo() const;
};

class FiguraNoSoportada {
    public:
        double dummyParameter;
        FiguraNoSoportada();
        ~FiguraNoSoportada();
};
