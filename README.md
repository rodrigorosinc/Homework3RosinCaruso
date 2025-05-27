# Readme

## Ejercicio 1

Este ejercicio implementa un sistema de mediciones basado en clases abstractas y herencia, que permite serializar y deserializar datos binarios de distintas mediciones de un vuelo. 

Las clases Presion y Posicion heredan de una clase base MedicionBase, y se utilizadan en la clase SaveFlightData para encapsular la información completa de una muestra de vuelo.

Para la serialización se utilizan las librerías <std::ostream> y <std::istream>.

Dado que la consigna prohíbe el uso de std::move, se implementé una copia profunda de los datos apuntados por unique_ptr. Esto se logra creando una nueva instancia del valor (float) y asignándola a un nuevo unique_ptr.

### Archivos involucrados
* ClasesMediciones.hpp: contiene las definiciones de las clases IMediciones, MedicionBase, Presion, Posicion y SaveFlightData.

* ClasesMediciones.cpp: contiene las implementaciones de los métodos definidos en el header.

### Compilación

Para compilar, usar el comando make por terminal y correr el codigo con <./nombreEjecutable>.

## Ejercicio 2

Este ejercicio implementa las siguientes clases para representar figuras geométricas:

- Punto: representa una coordenada (x; y).
- Círculo: definido por un centro (Punto) y un radio.
- Elipse: definida por un centro (Punto), semieje mayor y semieje menor.
- Rectángulo: definido por un vértice inferior izquierdo (Punto), ancho y largo.
- FiguraNoSoportada: clase para probar el manejo de casos no soportados.

### Funcionalidad
Cada clase incluye setters y getters para sus atributos. La clase ProcesadorFiguras implementa la función template calcularArea con especializaciones para calcular el área de cada figura geométrica:
- Círculo: 𝜋 × 𝑟 × 2 
- Elipse: 𝜋 × 𝑎 × 𝑏
- Rectángulo: 𝑎𝑛𝑐ℎ𝑜 × 𝑙𝑎𝑟𝑔𝑜
- Para figuras no soportadas, devuelve 0.

Usar plantillas y especialización permite la extensión sencilla a nuevas figuras.

### Compilacion

Para compilar basta con usar el comando make por terminal y <./nombreEjecutable>

## Ejercicio 3

Este ejercicio implementa una clase genérica para crear archivos JSON manualmente a partir de contenedores de datos de distintos tipos (double, string y vector<int>), usando templates.

### Estructura del código
1. Clase ContenedorDatos<T>: 
    - Contiene un vector interno para almacenar elementos de tipo T.
    - Permite agregar elementos con el método agregar.
    - Tiene un método procesar que imprime el contenido en formato JSON según el tipo:
        Para double y string, imprime un arreglo JSON simple.
        Para vector<int>, imprime arreglos anidados.
    - Usa if constexpr para especializar la serialización según el tipo.
    - Lanza error de compilación (static_assert) para tipos no soportados.

2. Clase CrearJson
    - Métodos para abrir (abrir) y cerrar (cerrar) un objeto JSON con { y }.
    - Método asociar que recibe un contenedor de datos y un nombre, para imprimir una propiedad JSON con el arreglo serializado.
    - Método imprimir para mostrar el contenido de un archivo JSON en un stream, útil para verificar el resultado.

3. main.cpp
* Crea instancias de ContenedorDatos para double, string y vector<int>.
* Agrega datos de ejemplo a cada contenedor.
* Crea un archivo datos.json usando CrearJson.
* Escribe los datos en formato JSON en el archivo.
* Luego imprime por consola el contenido generado.

### Compilacion

Para compilar, usar el comando make por terminal y correr el codigo con <./nombreEjecutable>.
