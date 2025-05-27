#include "procesar.hpp"
#include "crearJson.hpp"
#include <fstream>
#include <string>

using namespace std;

int main(){

    double a = 1.3, b = 2.1, c = 3.2;
    string h = "Hola", m = "mundo";
    vector<int> l1 = {1, 2}, l2 = {3, 4};

    ContenedorDatos<double> vec_doubles;
    ContenedorDatos<string> palabras;
    ContenedorDatos<vector<int>> listas;

    vec_doubles.agregar(a); vec_doubles.agregar(b); vec_doubles.agregar(c);
    palabras.agregar(h); palabras.agregar(m);
    listas.agregar(l1); listas.agregar(l2);

    CrearJson json;
    ofstream os("datos.json");
    if (!os) {
        cerr << "Error al abrir el archivo" << endl;
        return 1;
    }
    json.abrir(os);
    json.asociar(os, vec_doubles, "vec_doubles");
    json.asociar(os, palabras, "palabras");
    json.asociar(os, listas, "listas", true);
    json.cerrar(os);
    os.close();
    
    json.imprimir(cout, "datos.json");

    return 0;
}   