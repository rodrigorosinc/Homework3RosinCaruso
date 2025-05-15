#include "ClasesMediciones.hpp"

// MedicionBase
MedicionBase::MedicionBase(float t) {
    tiempoMedicion = std::make_unique<float>(t);
}
MedicionBase::MedicionBase(const MedicionBase& med) : tiempoMedicion(std::make_unique<float>(*med.tiempoMedicion)) {}
MedicionBase::~MedicionBase() = default;
float MedicionBase::getTiempo() const {
    return *tiempoMedicion;
}


// Presion
Presion::Presion(float p, float q, float t) : MedicionBase(t), presionEstatica(p), presionDinamica(q) {}
Presion::Presion(const Presion& other) : MedicionBase(*other.tiempoMedicion),  presionEstatica(other.presionEstatica),
                presionDinamica(other.presionDinamica) {}
Presion::~Presion() = default;

void Presion::serializar(std::ostream& out) const {
    out.write(reinterpret_cast<const char*>(&presionEstatica), sizeof(presionEstatica));
    out.write(reinterpret_cast<const char*>(&presionDinamica), sizeof(presionDinamica));
    float tiempo = getTiempo();
    out.write(reinterpret_cast<const char*>(&tiempo), sizeof(tiempo));
}

void Presion::deserializar(std::istream& in){
    in.read(reinterpret_cast<char*>(&presionEstatica), sizeof(presionEstatica));
    in.read(reinterpret_cast<char*>(&presionDinamica), sizeof(presionDinamica));
    float tiempo;
    in.read(reinterpret_cast<char*>(&tiempo), sizeof(tiempo));
    tiempoMedicion = std::make_unique<float>(tiempo);
}

void Presion::imprimir() const {
    std::cout << "Presion estatica: " << presionEstatica 
                  << ", dinamica: " << presionDinamica
                  << ", tiempo: " << *tiempoMedicion 
                  << std::endl;

}

// Posicion
Posicion::Posicion(float x, float y, float z, float t) : MedicionBase(t), latitud(x), longitud(y), altitud(z) {}
Posicion::Posicion(const Posicion& other) : MedicionBase(*other.tiempoMedicion), 
                latitud(other.latitud), longitud(other.longitud), altitud(other.altitud) {}
Posicion::~Posicion() = default;

void Posicion::serializar(std::ostream& out) const {
    out.write(reinterpret_cast<const char*>(&latitud), sizeof(latitud));
    out.write(reinterpret_cast<const char*>(&longitud), sizeof(longitud));
    out.write(reinterpret_cast<const char*>(&altitud), sizeof(altitud));
    float tiempo = getTiempo();
    out.write(reinterpret_cast<const char*>(&tiempo), sizeof(tiempo));
}

void Posicion::deserializar(std::istream& in) {
    in.read(reinterpret_cast<char*>(&latitud), sizeof(latitud));
    in.read(reinterpret_cast<char*>(&longitud), sizeof(longitud));
    in.read(reinterpret_cast<char*>(&altitud), sizeof(altitud));
    float tiempo;
    in.read(reinterpret_cast<char*>(&tiempo), sizeof(tiempo));
    tiempoMedicion = std::make_unique<float>(tiempo);
}

void Posicion::imprimir() const {
    std::cout << "Posicion: lat=" << latitud
                  << ", lon=" << longitud
                  << ", alt=" << altitud
                  << ", tiempo: " << *tiempoMedicion 
                  << std::endl;
}

//SaveFlightData
SaveFlightData::SaveFlightData(Posicion pos, Presion pres) : posicion(pos), presion(pres){}
SaveFlightData::~SaveFlightData() = default;

void SaveFlightData::serializar(std::ostream& out) const {
    posicion.serializar(out);
    presion.serializar(out);
}
void SaveFlightData::deserializar(std::istream& in) {
    posicion.deserializar(in);
    presion.deserializar(in);
}
void SaveFlightData::imprimir() const {
    std::cout << "Datos de vuelo:" << std::endl;
    posicion.imprimir();
    presion.imprimir();
    std::cout << "------------------------" << std::endl;
}
