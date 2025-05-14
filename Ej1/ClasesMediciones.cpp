#include "ClasesMediciones.hpp"

// MedicionBase
MedicionBase::MedicionBase(float t) {
    tiempoMedicion = std::make_unique<float>(t);
}

MedicionBase::MedicionBase(const MedicionBase& med) : tiempoMedicion(std::make_unique<float>(*med.tiempoMedicion)) {}

float MedicionBase::getTiempo() const {
    return *tiempoMedicion;
}

// Presion
Presion::Presion(float p, float q, float t) : MedicionBase(t), presionEstatica(p), presionDinamica(q) {}

Presion::Presion(const Presion& other) : MedicionBase(*other.tiempoMedicion),  presionEstatica(other.presionEstatica),
                presionDinamica(other.presionDinamica) {}

