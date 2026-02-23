#ifndef TAPE_HPP
#define TAPE_HPP

#include <vector>
#include <iostream>

// Tipo enumerado con ámbito para los colores
enum class CellColor : int {
    White = 0,
    Black = 1,
    Red = 2,
    Green = 3,
    Blue = 4,
    Yellow = 5,
    Magenta = 6,
    Cyan = 7,
    Brown = 8,
};

class Tape {
private:
    int size_x_;
    int size_y_;
    int num_colors_;
    std::vector<std::vector<CellColor>> cells_;

public:
    // Constructores
    Tape(int x, int y, int colors);
    Tape();

    // Comprobación de límites
    bool InBounds(int x, int y) const;

    // Getters
    CellColor GetColor(int x, int y) const;
    int GetNumColors() const { return num_colors_; }
    int GetSizeX() const { return size_x_; }
    int GetSizeY() const { return size_y_; }

    // Setters
    void SetColor(int x, int y, CellColor color);

    // Cambio cíclico de color
    void NextColor(int x, int y);

    // Salida por pantalla
    friend std::ostream& operator<<(std::ostream& os, const Tape& t);
};

#endif
