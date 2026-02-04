#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "tape.hpp"

void Tape::SetBlack(int x, int y) {
    if (InBounds(x, y)) {
        cells[y][x] = 1;
    }
}

void Tape::SetWhite(int x, int y) {
    if (InBounds(x, y)) {
        cells[y][x] = 0;
    }
}

int Tape::GetCell(int x, int y) const {
    if (InBounds(x, y)) {
        return cells[y][x];
    }
    return -1; // Valor inválido si está fuera de los límites
}

bool Tape::InBounds(int x, int y) const {
    return (x >= 0 && x < size_x_ && y >= 0 && y < size_y_);
}

std::ostream& operator<<(std::ostream& os, const Tape& tape) {
    for (int y = 0; y < tape.size_y_; ++y) {
        for (int x = 0; x < tape.size_x_; ++x) {
            os << (tape.cells[y][x] ? 'X' : ' '); // X para negra, espacio para blanca
        }
        os << std::endl;
    }
    return os;
}

void Tape::save(std::ofstream& out) const {
    out << size_x_ << " " << size_y_ << std::endl;
    for (int y = 0; y < size_y_; ++y) {
        for (int x = 0; x < size_x_; ++x) {
            if (cells[y][x]) {
                out << x << " " << y << std::endl;
            }
        }
    }
}

