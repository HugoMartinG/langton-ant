#include "tape.hpp"

// Constructor con tamaño y número de colores
Tape::Tape(int x, int y, int colors)
    : size_x_(x), size_y_(y), num_colors_(colors),
      cells_(y, std::vector<CellColor>(x, CellColor::White)) {}

// Constructor por defecto
Tape::Tape() : size_x_(0), size_y_(0), num_colors_(0) {}

// Comprueba si la posición está dentro de la cinta
bool Tape::InBounds(int x, int y) const {
    return (x >= 0 && x < size_x_ && y >= 0 && y < size_y_);
}

// Devuelve el color de una celda
CellColor Tape::GetColor(int x, int y) const {
    if (InBounds(x, y))
        return cells_[y][x];
    return CellColor::White; // Por defecto, fuera de límites es blanco
}

// Asigna un color a una celda
void Tape::SetColor(int x, int y, CellColor color) {
    if (InBounds(x, y))
        cells_[y][x] = color;
}

// Cambia el color de forma cíclica
void Tape::NextColor(int x, int y) {
    if (!InBounds(x, y)) return;

    int color = static_cast<int>(cells_[y][x]);
    color = (color + 1) % num_colors_;
    cells_[y][x] = static_cast<CellColor>(color);
}

// Sobrecarga del operador <<
std::ostream& operator<<(std::ostream& os, const Tape& t) {
    for (int y = 0; y < t.size_y_; ++y) {
        for (int x = 0; x < t.size_x_; ++x) {
            os << static_cast<int>(t.cells_[y][x]);
        }
        os << "\n";
    }
    return os;
}
