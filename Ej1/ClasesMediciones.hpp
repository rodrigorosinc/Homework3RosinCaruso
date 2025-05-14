#pragma once
#include <fstream>
#include <memory>
#include <iostream>

class IMediciones {
public:
    virtual void serializar(std::ostream& out) const = 0;
    virtual void deserializar(std::istream& in) = 0;
    virtual ~IMediciones() = default;
};

class MedicionBase : public IMediciones {
    protected:
        std::unique_ptr<float> tiempoMedicion;
    public:
        MedicionBase(float t);
        MedicionBase(const MedicionBase& other); //Este es el constructor de copia, que se usa para copiar el objeto.
        ~MedicionBase() = default;

        float getTiempo() const;
};

class Presion : public MedicionBase {
    private:
        float presionEstatica; //p
        float presionDinamica; //q
    public:
        Presion(float p, float q, float t);
        Presion(const Presion& other); // Constructor de copia
        ~Presion() = default;
        void serializar(std::ostream& out) const override;
        void deserializar(std::istream& in) override;
};

class Posicion : public MedicionBase {
    private:
        float latitud; //x
        float longitud; //y
        float altitud; //z
    public:
        Posicion(float x, float y, float z, float t);
        void serializar(std::ostream& out) const override;
        void deserializar(std::istream& in) override;
};

class SaveFlightData {
    private:
        Posicion posicion;
        Presion presion;
    public:
        SaveFlightData(Posicion pos, Presion pres);
        void serializar(std::ostream& out) const;
        void deserializar(std::istream& in);
        void imprimir() const;
};   

