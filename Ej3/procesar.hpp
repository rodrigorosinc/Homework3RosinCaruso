#pragma once
#include <istream>
#include <type_traits>
#include <vector>

template<typename T>
class ContenedorDatos {
    private:
        std::vector<T> vect;
    public:
        void agregar(T elem);
        void procesar(std::ostream& os);
};

template<typename T>
void ContenedorDatos<T>::agregar(T elem){
    vect.push_back(elem);
}

template<typename T>
void ContenedorDatos<T>::procesar(std::ostream& os){
    if constexpr (std::is_same_v<T, double>){
        os << "[";
        for (size_t i = 0; i < vect.size(); ++i) {
            os << vect[i];
            if (i != vect.size() - 1) os << ", ";
        }
        os << "]";
    } else if constexpr (std::is_same_v<T, std::string>){
        os << "[";
        for (size_t i = 0; i < vect.size(); ++i){
            os << "\"" << vect[i] << "\"";
            if (i != vect.size() - 1) os << ", ";
        }
        os << "]";
    } else if constexpr (std::is_same_v<T, std::vector<int>>){
        os << "[";
        for (size_t i = 0; i < vect.size(); ++i){
            os << "\n[";
            for (size_t j = 0; j < vect[i].size(); ++j) {
                os << vect[i][j];
                if (j != vect[i].size() - 1) os << ", ";
            }
            os << "]";
            if (i != vect.size() - 1) os << ", ";
        }
        os << "\n";
        os << "]";
    }
    else {
        static_assert(std::is_same_v<T, void>, "Tipo no soportado para procesar");
    }
}

