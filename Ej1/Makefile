# Nombre del ejecutable
TARGET = programa

# Compilador
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic

# Archivos fuente y objetos
SRCS = main.cpp ClasesMediciones.cpp
OBJS = $(SRCS:.cpp=.o)

# Regla por defecto
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Limpieza
clean:
	rm -f $(OBJS) $(TARGET)
