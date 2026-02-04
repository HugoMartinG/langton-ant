#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

#include "ant.hpp"

bool Ant::Move(Tape& tape) {
    if (!tape.InBounds(GetX(), GetY())) {
        return false; // La hormiga está fuera de los límites
    }

    if (tape.GetCell(GetX(), GetY()) == 0) { 
        tape.SetBlack(x_, y_);
        TurnLeft();
    } else { 
        tape.SetWhite(x_, y_);
        TurnRight();
    }
    StepForward(); // Avanzar una posición en la dirección actual
    return true;
}

void Ant::TurnLeft() {
    switch (direccion_) {
        case LEFT:  direccion_ = DOWN; break;
        case DOWN:  direccion_ = RIGHT; break;
        case RIGHT: direccion_ = UP; break;
        case UP:    direccion_ = LEFT; break;
    }
}

void Ant::TurnRight() {
    switch (direccion_) {
        case LEFT:  direccion_ = UP; break;
        case UP:    direccion_ = RIGHT; break;
        case RIGHT: direccion_ = DOWN; break;
        case DOWN:  direccion_ = LEFT; break;
    }
}

void Ant::StepForward() {
    switch (direccion_) {
        case LEFT:
            x_--;
            break;
        case RIGHT:
            x_++;
            break;
        case UP:
            y_--;
            break;
        case DOWN:
            y_++;
            break;
    }
}

std::ostream& operator<<(std::ostream& os, const Ant& ant) {
    switch (ant.direccion_) {
        case LEFT:
            os << "<";
            break;
        case RIGHT:
            os << ">";
            break;
        case UP:
            os << "^";
            break;
        case DOWN:
            os << "v";
            break;
    }
    return os;
}

