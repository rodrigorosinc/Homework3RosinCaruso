#include "ClasesMediciones.hpp"


int main(){
    // Crear un objeto de tipo SaveFlightData
    Posicion posicion(-34.6f, -58.4f, 950.0f, 5.3); 
    Presion presion(101.3f, 5.8f, 6.1f);

    SaveFlightData saveFlightData(posicion, presion);

    // Serializar el objeto a un archivo
    std::ofstream outFile("data.bin", std::ios::binary);
    if (!outFile) {
        std::cerr << "Error al abrir el archivo para escritura." << std::endl;
        return 1;
    }
    saveFlightData.serializar(outFile);
    outFile.close();
    std::cout << "Datos serializados correctamente." << std::endl;
    // Deserializar el objeto desde el archivo
    SaveFlightData loadedData(Posicion(0, 0, 0, 0), Presion(0, 0, 0));
    std::ifstream inFile("data.bin", std::ios::binary);
    if (!inFile) {
        std::cerr << "Error al abrir el archivo para lectura." << std::endl;
        return 1;
    }
    loadedData.deserializar(inFile);
    inFile.close();
    std::cout << "Datos deserializados correctamente." << std::endl;
    // Imprimir los datos deserializados
    loadedData.imprimir();

    return 0;
}