# Nombre del ejecutable
TARGET = hormiga

# Compilador
CXX = g++

# Flags de compilación
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude

# Carpetas
SRC_DIR = src
OBJ_DIR = obj

# Archivos fuente
SRCS = $(wildcard $(SRC_DIR)/*.cpp) main.cpp

# Archivos objeto
OBJS = $(SRCS:%.cpp=$(OBJ_DIR)/%.o)

# Regla por defecto
all: $(TARGET)

# Crear ejecutable
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

# Compilar cada .cpp a .o
$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpiar
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

# Ejecutar con fichero de entrada
run:
	./$(TARGET) input/entrada2.txt

.PHONY: all clean run
