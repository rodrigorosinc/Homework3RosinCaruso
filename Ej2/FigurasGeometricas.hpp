/* 2. Escriba el código para las clases que representan: 
a. Un punto, con su posición (x, y) y los correspondientes setters y getters. 
b. Un círculo, con su posición, radio (r) y los correspondientes setters y getters. 
c. Una elipse, con la posición de su centro, el semieje mayor (a), el semieje menor 
(b) y los correspondientes setters y getters. 
d. Un rectángulo, con la posición de su vértice izquierdo inferior, su ancho, su largo 
y los correspondientes métodos setters y getters. 
Cree una clase adicional denominada ProcesadorFigura que utilice especialización de 
plantilla para calcular el área de las figuras. 
Escriba el código en el main que permita ejemplificar como calcular el área de cada una 
de las figuras mencionadas.
*/

class Punto {
    private:
        double x;
        double y;
    public:
        // Constructor
        Punto(double x = 0, double y = 0) : x(x), y(y) {}

        // Setters
        void setX(double x) { this->x = x; }
        void setY(double y) { this->y = y; }

        // Getters
        double getX() const { return x; }
        double getY() const { return y; }
};

