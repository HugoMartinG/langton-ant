#ifndef TAPE_
#define TAPE_

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

class Tape {
    private:
        int size_x_, size_y_; // Dimensiones de la cinta
        std::vector<std::vector<bool>> cells; // Matriz que representa las celdas de la cinta

    public:
        // Constructores
        Tape(int x, int y) : size_x_(x), size_y_(y), cells(y, std::vector<bool>(x, 0)) {}
        Tape() : size_x_(0), size_y_(0), cells() {}

        // Setters
        void SetBlack(int x, int y); 
        void SetWhite(int x, int y);

        // Getters
        int GetCell(int x, int y) const;
        bool InBounds(int x, int y) const;
        int GetSizeX() const { return size_x_; }
        int GetSizeY() const { return size_y_; }

        // Sobrecarga del operador de salida
        friend std::ostream& operator<<(std::ostream& os, const Tape& t);

        void save(std::ofstream& out) const;
};

#endif