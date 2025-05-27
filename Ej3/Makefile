# Nombre del compilador
CXX = g++

# Flags de compilación
CXXFLAGS = -std=c++20 -Wall -Wextra -pedantic

# Archivos fuente y objeto
SRCS = main.cpp crearJson.cpp
OBJS = $(SRCS:.cpp=.o)

# Nombre del ejecutable
TARGET = Ej3.exe

# Regla por defecto
all: $(TARGET)

# Regla para enlazar el ejecutable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Regla para compilar los .cpp a .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpiar archivos generados
clean:
	rm -f $(OBJS) $(TARGET)
